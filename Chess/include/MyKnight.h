#pragma once
#include "MyPiece.h"

class MyKnight : public MyPiece {
public:
    MyKnight(bool white, int r, int c) : MyPiece(white, r, c) {}

    char symbol() const override { 
        return isWhite ? 'N' : 'n'; 
    }

    bool checkMove(int toRow, int toCol, MyPiece* /*notUsed*/[8][8]) override;
};
