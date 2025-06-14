#include "Move.h"

Move::Move(const std::string& src_, const std::string& dst_, int score_)
    : src(src_), dst(dst_), score(score_) {
    srcCol = src[0] - 'a';
    srcRow = 8 - (src[1] - '0');
    dstCol = dst[0] - 'a';
    dstRow = 8 - (dst[1] - '0');
}

std::string Move::toString() const {
    return src + dst;
}
