#pragma once
#include "MyPiece.h"

class MyBishop : public MyPiece {
public:
    MyBishop(bool white, int r, int c) : MyPiece(white, r, c) {}
    
    char symbol() const override { 
        return isWhite ? 'B' : 'b'; 
    }

    bool checkMove(int r, int c, MyPiece* b[8][8]) override;
};
