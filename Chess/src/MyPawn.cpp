#include "MyPawn.h"
#include <cstdlib>

bool MyPawn::checkMove(int toRow, int toCol, MyPiece* b[8][8]) {
    return checkSquares(row, col, toRow, toCol, b);
}

bool MyPawn::checkSquares(int fromRow, int fromCol, int toRow, int toCol, MyPiece* b[8][8]) {
    if (toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8)
        return false;

    int dir = isWhite ? 1 : -1;
    int start = isWhite ? 1 : 6;

    if (fromCol == toCol) {
        // move 1 step
        if (toRow == fromRow + dir && b[toRow][toCol] == nullptr)
            return true;

        // move 2 steps from start
        if (fromRow == start &&
            toRow == fromRow + 2 * dir &&
            b[fromRow + dir][fromCol] == nullptr &&
            b[toRow][toCol] == nullptr)
            return true;
    }

    // eat enemy
    if (abs(toCol - fromCol) == 1 &&
        toRow == fromRow + dir &&
        b[toRow][toCol] != nullptr &&
        b[toRow][toCol]->getColor() != isWhite)
        return true;

    return false;
}
