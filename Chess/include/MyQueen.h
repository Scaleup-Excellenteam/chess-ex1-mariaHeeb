#pragma once
#include "MyPiece.h"

class MyQueen : public MyPiece {
public:
    MyQueen(bool white, int r, int c) : MyPiece(white, r, c) {}

    char symbol() const override { 
        return isWhite ? 'Q' : 'q'; 
    }

    bool checkMove(int toRow, int toCol, MyPiece* b[8][8]) override;
    bool checkSquares(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]);
};
