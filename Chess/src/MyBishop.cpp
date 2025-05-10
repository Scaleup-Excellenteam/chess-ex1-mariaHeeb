#include "BishopPiece.h"
#include <cstdlib>

bool BishopPiece::checkMove(int r, int c, Piece* b[8][8]) {
    int sr = getRow();
    int sc = getCol();

    if (abs(r - sr) != abs(c - sc)) {
        return false;
    }

    int dr = (r > sr) ? 1 : -1;
    int dc = (c > sc) ? 1 : -1;

    int i = sr + dr;
    int j = sc + dc;

    while (i != r || j != c) {
        if (b[i][j] != nullptr) {
            return false;
        }
        i += dr;
        j += dc;
    }

    return true;
}
