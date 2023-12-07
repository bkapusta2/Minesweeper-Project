#ifndef MINESWEEPER_PROJECT_BOARD_H
#define MINESWEEPER_PROJECT_BOARD_H
#include <vector>

using std::vector;

class Cell;

class Board {
private:
    int size;
public:
    vector<vector<Cell*>> board;
    bool gameEnded;

    Board();
    ~Board();

    void setCells();

    // Go through all the cells on the board and set the values
    // Must first create the board array, work on this.
    void setCellValues();

    int getBoardSize();

    void clickCell(int x, int y);

    void resetBoard();
};


#endif //MINESWEEPER_PROJECT_BOARD_H
