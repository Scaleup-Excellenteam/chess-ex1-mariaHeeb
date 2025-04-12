#include "Board.h"
#include "Rook.h"
#include "King.h"

Board::Board(const std::string& startBoard) {
    grid.resize(8);
    for (int i = 0; i < 8; ++i) {
        grid[i].resize(8);
    }

    for (int i = 0; i < 64; ++i) {
        char curr = startBoard[i];
        if (curr == '#') continue;

        int r = i / 8;
        int c = i % 8;
        bool white = isupper(curr);

        switch (tolower(curr)) {
            case 'r': grid[r][c] = std::make_unique<Rook>(curr, white); break;
            case 'k': grid[r][c] = std::make_unique<King>(curr, white); break;
            // Add more cases for other pieces if needed
        }
    }
}

Piece* Board::get(int x, int y) const {
    return grid[x][y].get();
}

void Board::move(int sx, int sy, int dx, int dy) {
    grid[dx][dy] = std::move(grid[sx][sy]);
    grid[sx][sy] = nullptr;
}

bool Board::isPathClear(int sx, int sy, int dx, int dy) const {
    int xStep = (dx - sx) ? (dx - sx) / abs(dx - sx) : 0;
    int yStep = (dy - sy) ? (dy - sy) / abs(dy - sy) : 0;

    int x = sx + xStep, y = sy + yStep;
    while (x != dx || y != dy) {
        if (grid[x][y]) return false;
        x += xStep;
        y += yStep;
    }
    return true;
}
