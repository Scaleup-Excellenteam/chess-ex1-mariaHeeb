#include "MyPiece.h"

MyPiece::MyPiece(bool white, int r, int c) : isWhite(white), row(r), col(c) {}

bool MyPiece::getColor() const {
    return isWhite;
}

int MyPiece::getRow() const {
    return row;
}

int MyPiece::getCol() const {
    return col;
}

void MyPiece::setPos(int r, int c) {
    row = r;
    col = c;
}
