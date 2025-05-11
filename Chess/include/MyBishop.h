#pragma once
#include "MyPiece.h"

class MyBishop : public MyPiece {
public:
    MyBishop(bool white, int r, int c) : MyPiece(white, r, c) {}

    char symbol() const override {
        return isWhite ? 'B' : 'b';
    }

    bool checkMove(int toRow, int toCol, MyPiece* b[8][8]) override;
};
