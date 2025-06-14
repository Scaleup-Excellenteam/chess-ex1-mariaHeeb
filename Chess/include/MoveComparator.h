#pragma once

#include "Move.h"

class MoveComparator {
public:
    bool operator()(const Move& a, const Move& b) const {
        return a.score < b.score;
    }
};
