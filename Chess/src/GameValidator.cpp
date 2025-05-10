#include "GameValidator.h"
#include "Board.h"
#include "MyPiece.h"
#include "MyKnight.h"

int checkMove(const std::string& m, std::string& state, bool isWhiteTurn) {
    int sCol = m[0] - 'a';
    int sRow = m[1] - '1';
    int dCol = m[2] - 'a';
    int dRow = m[3] - '1';

    MyBoard bObj;
    bObj.loadFromString(state);

    MyPiece* from = bObj.boardArr[sRow][sCol].get();
    MyPiece* to = bObj.boardArr[dRow][dCol].get();

    if (!from)
        return 11;

    if (from->getColor() != isWhiteTurn)
        return 12; 

    if (to && to->getColor() == from->getColor())
        return 13; 

    MyPiece* const* const* raw = bObj.getRawBoard();
    if (!from->checkMove(dRow, dCol, (MyPiece* (*)[8])raw))
        return 21; 

    from->setPos(dRow, dCol);
    bObj.boardArr[dRow][dCol] = std::move(bObj.boardArr[sRow][sCol]);
    bObj.boardArr[sRow][sCol] = nullptr;

    state = bObj.getBoardString();
    return 42;
}
