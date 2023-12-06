#ifndef MINESWEEPER_PROJECT_BOMBCELL_H
#define MINESWEEPER_PROJECT_BOMBCELL_H
#include "Cell.h"


class BombCell : public Cell {
private:
    int numberOfSurroundingBombs;
    bool revealed;
public:
    BombCell();
    ~BombCell();

    virtual int getValueInside();

    virtual char getSymbol();

};


#endif //MINESWEEPER_PROJECT_BOMBCELL_H
