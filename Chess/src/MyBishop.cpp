#include "MyBishop.h"
#include "MyValidatorUtils.h"
#include <cstdlib>

bool MyBishop::checkMove(int toRow, int toCol, MyPiece* b[8][8]) {
    if (std::abs(toRow - row) != std::abs(toCol - col)) {
        return false; // Not diagonal
    }

    return MyValidatorUtils::clearDiagonal(row, col, toRow, toCol, b);
}
