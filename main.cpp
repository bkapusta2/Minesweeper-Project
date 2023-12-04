#include <iostream>
#include "lib/include/Board.h"
#include "lib/include/Cell.h"

int main() {
    Board* board = new Board();
    board->setCells();
    board->setCellValues();
    return 0;
}
