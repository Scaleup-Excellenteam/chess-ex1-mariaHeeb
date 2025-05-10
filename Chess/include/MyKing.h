#pragma once
#include "MyPiece.h"

class MyKing : public MyPiece {
public:
    MyKing(bool white, int r, int c) : MyPiece(white, r, c) {}

    char symbol() const override { 
        return isWhite ? 'K' : 'k'; 
    }

    bool checkMove(int toRow, int toCol, MyPiece* b[8][8]) override;
};
