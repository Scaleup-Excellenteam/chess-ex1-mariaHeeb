#include "MyQueen.h"
#include "MyRook.h"
#include "MyBishop.h"

bool MyQueen::checkSquares(int /*fromRow*/, int /*fromCol*/, int toRow, int toCol, MyPiece* b[8][8]) {
    MyRook rHelper(isWhite, row, col);
    MyBishop bHelper(isWhite, row, col);
    return rHelper.checkMove(toRow, toCol, b) || bHelper.checkMove(toRow, toCol, b);
}

bool MyQueen::checkMove(int toRow, int toCol, MyPiece* b[8][8]) {
    return checkSquares(row, col, toRow, toCol, b);
}
