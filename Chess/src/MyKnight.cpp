#include "MyKnight.h"
#include <cmath>

bool MyKnight::checkMove(int toRow, int toCol, MyPiece* /*notUsed*/[8][8]) {
    int rDiff = abs(toRow - row);
    int cDiff = abs(toCol - col);
    return (rDiff == 2 && cDiff == 1) || (rDiff == 1 && cDiff == 2);
}
