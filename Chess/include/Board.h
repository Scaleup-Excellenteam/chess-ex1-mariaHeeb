#pragma once
#include <memory>
#include <string>
#include "MyPiece.h"
#include "MyRook.h"
#include "MyKing.h"
#include "MyQueen.h"
#include "MyBishop.h"
#include "MyKnight.h"
#include "MyPawn.h"

class MyBoard {
public:
    MyBoard();
    ~MyBoard();

    void loadFromString(const std::string& stateStr);
    std::string getBoardString() const;
    MyPiece* const* const* getRawBoard() const;

    std::unique_ptr<MyPiece> boardArr[8][8];

    // New method to suggest best move
    void suggestBestMove(bool isWhiteTurn) const;

    MyBoard(const MyBoard&) = delete;
    MyBoard& operator=(const MyBoard&) = delete;
 void display() const;
    bool isValidMove(const Move& move, bool isWhiteTurn) const;
    void applyMove(const Move& move);
    std::vector<std::string> getPieces(bool isWhiteTurn) const;
    Move computeBestFor(const std::string& piecePos, int depth) const;
};
