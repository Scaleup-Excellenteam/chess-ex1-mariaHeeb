#include "Board.h"
#include <cctype>
#include <memory>

MyBoard::MyBoard() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            boardArr[i][j] = nullptr;
}

MyBoard::~MyBoard() {}

void MyBoard::loadFromString(const std::string& stateStr) {
    if (stateStr.size() != 64)
        return;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int idx = i * 8 + j;
            char sym = stateStr[idx];

            boardArr[i][j] = nullptr;

            char small = std::tolower(sym);
            bool white = std::isupper(sym);

            switch (small) {
                case 'r':
                    boardArr[i][j] = std::make_unique<MyRook>(white, i, j);
                    break;
                case 'k':
                    boardArr[i][j] = std::make_unique<MyKing>(white, i, j);
                    break;
                case 'b':
                    boardArr[i][j] = std::make_unique<MyBishop>(white, i, j);
                    break;
                case 'q':
                    boardArr[i][j] = std::make_unique<MyQueen>(white, i, j);
                    break;
                case 'n':
                    boardArr[i][j] = std::make_unique<MyKnight>(white, i, j);
                    break;
                case 'p':
                    boardArr[i][j] = std::make_unique<MyPawn>(white, i, j);
                    break;
                default:
                    boardArr[i][j] = nullptr;
                    break;
            }
        }
    }
}

std::string MyBoard::getBoardString() const {
    std::string res;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            res += (boardArr[i][j] ? boardArr[i][j]->symbol() : '#');
    return res;
}

MyPiece* const* const* MyBoard::getRawBoard() const {
    static MyPiece* raw[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            raw[i][j] = boardArr[i][j].get();
    return (MyPiece* const* const*)raw;
}
