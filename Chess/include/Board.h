#pragma once

#include <memory>
#include <string>
#include "MyPiece.h"
#include "MyRook.h"
#include "MyKing.h"
#include "MyQueen.h"
#include "MyBishop.h"
#include "MyKnight.h"
#include "MyPawn.h"

class MyBoard {
public:
    MyBoard();
    ~MyBoard();

    void loadFromString(const std::string& stateStr);
    std::string getBoardString() const;

    MyPiece* const* const* getRawBoard() const;

    std::unique_ptr<MyPiece> boardArr[8][8];

    MyBoard(const MyBoard&) = delete;
    MyBoard& operator=(const MyBoard&) = delete;
};
