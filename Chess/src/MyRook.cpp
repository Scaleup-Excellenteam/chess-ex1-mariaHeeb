#include "MyRook.h"

bool MyRook::checkSquares(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]) {
    if (fromRow == toRow) {
        int dir = (toCol - fromCol > 0) ? 1 : -1;
        for (int c = fromCol + dir; c != toCol; c += dir) {
            if (b[fromRow][c] != nullptr)
                return false;
        }
        return true;
    }

    if (fromCol == toCol) {
        int dir = (toRow - fromRow > 0) ? 1 : -1;
        for (int r = fromRow + dir; r != toRow; r += dir) {
            if (b[r][fromCol] != nullptr)
                return false;
        }
        return true;
    }

    return false;
}

bool MyRook::checkMove(int toRow, int toCol, MyPiece* b[8][8]) {
    return checkSquares(row, col, toRow, toCol, b);
}
