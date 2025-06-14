#pragma once

#include <string>

class Move {
public:
    std::string src;
    std::string dst;
    int score;

    Move(const std::string& src_, const std::string& dst_, int score_ = 0);

    int srcRow, srcCol, dstRow, dstCol;

    std::string toString() const;
};
