#include "Board.h"
#include "PriorityQueue.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Define Move struct for suggestion
struct Move {
    int fromRow, fromCol, toRow, toCol;
    int score;

    Move(int fr, int fc, int tr, int tc, int s)
        : fromRow(fr), fromCol(fc), toRow(tr), toCol(tc), score(s) {}
};

// Comparator for Move based on score
struct MoveComparator {
    int operator()(const Move& a, const Move& b) const {
        return a.score - b.score;
    }
};

// Suggest best move(s)
void MyBoard::suggestBestMove(bool isWhiteTurn) const {
    PriorityQueue<Move, MoveComparator> pq;

    for (int fr = 0; fr < 8; ++fr) {
        for (int fc = 0; fc < 8; ++fc) {
            MyPiece* piece = boardArr[fr][fc].get();
            if (!piece || piece->getColor() != isWhiteTurn) continue;

            for (int tr = 0; tr < 8; ++tr) {
                for (int tc = 0; tc < 8; ++tc) {
                    MyPiece* target = boardArr[tr][tc].get();
                    if (target && target->getColor() == isWhiteTurn) continue;

                    if (piece->checkMove(tr, tc, getRawBoard())) {
                        int baseScore = target ? 10 : 1;

                        // Bonus 1: Center Control
                        if ((tr == 3 || tr == 4) && (tc == 3 || tc == 4)) {
                            baseScore += 3;
                        }

                        // Bonus 2: Threat Count After Move
                        int threatCount = 0;
                        MyPiece* savedPiece = boardArr[tr][tc].release();
                        boardArr[tr][tc].reset(boardArr[fr][fc].release());
                        boardArr[fr][fc].reset();

                        MyPiece* movedPiece = boardArr[tr][tc].get();
                        for (int nr = 0; nr < 8; ++nr) {
                            for (int nc = 0; nc < 8; ++nc) {
                                MyPiece* enemy = boardArr[nr][nc].get();
                                if (enemy && enemy->getColor() != isWhiteTurn &&
                                    movedPiece->checkMove(nr, nc, getRawBoard())) {
                                    threatCount++;
                                }
                            }
                        }
                        baseScore += threatCount * 2;

                        // Bonus 3: Pawn Promotion
                        if (movedPiece && dynamic_cast<MyPawn*>(movedPiece) && (tr == 0 || tr == 7)) {
                            baseScore += 5;
                        }

                        // Restore Board State
                        boardArr[fr][fc].reset(boardArr[tr][tc].release());
                        boardArr[tr][tc].reset(savedPiece);

                        // Push move with calculated score
                        pq.push(Move(fr, fc, tr, tc, baseScore));
                    }
                }
            }
        }
    }

    if (pq.isEmpty()) {
        std::cout << "No legal moves found." << std::endl;
        return;
    }

    std::cout << "Top suggested moves:" << std::endl;
    int count = 0;
    while (!pq.isEmpty() && count < 3) {
        Move best = pq.poll();
        std::cout << "From (" << best.fromRow << "," << best.fromCol << ") to ("
                  << best.toRow << "," << best.toCol << ") with score " << best.score << std::endl;
        ++count;
    }
}

Move MyBoard::computeBestFor(const std::string& piecePos, int depth) const {
    int col = piecePos[0] - 'a';
    int row = 8 - (piecePos[1] - '0');
    int newRow = row + (isupper(m_boardStr[row * 8 + col]) ? -1 : 1);
    if (newRow >= 0 && newRow < 8) {
        return Move(piecePos, std::string(1, 'a' + col) + std::to_string(8 - newRow), 10);
    }
    return Move(piecePos, piecePos, 0); 
}
void MyBoard::applyMove(const Move& move) {
    char piece = m_boardStr[move.srcRow * 8 + move.srcCol];
    m_boardStr[move.srcRow * 8 + move.srcCol] = '#';
    m_boardStr[move.dstRow * 8 + move.dstCol] = piece;
}
std::vector<std::string> MyBoard::getPieces(bool isWhiteTurn) const {
    std::vector<std::string> positions;
    for (int i = 0; i < 64; ++i) {
        char piece = m_boardStr[i];
        if ((isWhiteTurn && isupper(piece)) || (!isWhiteTurn && islower(piece))) {
            int row = i / 8;
            int col = i % 8;
            positions.emplace_back(std::string(1, 'a' + col) + std::to_string(8 - row));
        }
    }
    return positions;
}

