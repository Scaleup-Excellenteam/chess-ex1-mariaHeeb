#pragma once
#include "MyPiece.h"

class MyPawn : public MyPiece {
public:
    MyPawn(bool white, int r, int c) : MyPiece(white, r, c) {}

    char symbol() const override { 
        return isWhite ? 'P' : 'p'; 
    }

    bool checkMove(int toRow, int toCol, MyPiece* b[8][8]) override;
    bool checkSquares(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]);
};
