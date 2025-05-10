#pragma once

class MyPiece {
public:
    MyPiece(bool white, int r = -1, int c = -1);

    virtual ~MyPiece() {}

    bool getColor() const;
    int getRow() const;
    int getCol() const;
    void setPos(int r, int c);

    virtual char symbol() const = 0;

    virtual bool checkMove(int toRow, int toCol, MyPiece* b[8][8]) = 0;

protected:
    bool isWhite;
    int row, col;
};
