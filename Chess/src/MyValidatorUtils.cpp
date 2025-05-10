#include "MyValidatorUtils.h"
#include <cstdlib>

bool MyValidatorUtils::clearStraight(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]) {
    if (fromRow == toRow) {
        int step = (toCol > fromCol) ? 1 : -1;
        for (int c = fromCol + step; c != toCol; c += step) {
            if (b[fromRow][c]) return false;
        }
        return true;
    }

    if (fromCol == toCol) {
        int step = (toRow > fromRow) ? 1 : -1;
        for (int r = fromRow + step; r != toRow; r += step) {
            if (b[r][fromCol]) return false;
        }
        return true;
    }

    return false;
}

bool MyValidatorUtils::clearDiagonal(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]) {
    if (abs(toRow - fromRow) != abs(toCol - fromCol)) return false;

    int rStep = (toRow > fromRow) ? 1 : -1;
    int cStep = (toCol > fromCol) ? 1 : -1;

    for (int r = fromRow + rStep, c = fromCol + cStep; r != toRow; r += rStep, c += cStep) {
        if (b[r][c]) return false;
    }

    return true;
}
