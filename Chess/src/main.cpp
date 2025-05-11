#include "Board.h"
#include "Chess.h"
#include "GameValidator.h"
#include "MyBoard.h"
#include <iostream>

int main() {
    std::string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    Chess a(board);
    int codeResponse = 0;
    std::string res = a.getInput();
    bool isWhite = true;

    while (res != "exit") {
        if (res == "suggest" || res == "recommend") {
            MyBoard b;
            b.loadFromString(board);
            b.suggestBestMove(isWhite);
        } else {
            codeResponse = validateMove(res, board, isWhite);
            if (codeResponse == 42)
                isWhite = !isWhite;
            a.setCodeResponse(codeResponse);
        }

        res = a.getInput();
    }

    std::cout << "\nExiting\n";
    return 0;
}
