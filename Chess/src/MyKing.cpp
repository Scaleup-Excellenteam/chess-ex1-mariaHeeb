#include "MyKing.h"
#include <cstdlib>

bool MyKing::checkMove(int toRow, int toCol, MyPiece* b[8][8]) {
    int rDiff = abs(toRow - row);
    int cDiff = abs(toCol - col);
    return (rDiff <= 1 && cDiff <= 1);
}
