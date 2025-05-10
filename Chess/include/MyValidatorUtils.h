#pragma once
#include "MyPiece.h"

class MyValidatorUtils {
public:
    static bool clearStraight(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]);
    static bool clearDiagonal(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]);
};
