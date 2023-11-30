#ifndef MINESWEEPER_PROJECT_CELL_H
#define MINESWEEPER_PROJECT_CELL_H


class Cell {
private:
    int numberOfSurroundingBombs;
public:
    Cell();
    ~Cell();

    // If -1 it should be a bomb
    virtual int getValueInside();

    virtual char getSymbol();
};


#endif //MINESWEEPER_PROJECT_CELL_H
