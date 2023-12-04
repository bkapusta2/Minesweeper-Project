#ifndef MINESWEEPER_PROJECT_OPENCELL_H
#define MINESWEEPER_PROJECT_OPENCELL_H
#include "Cell.h"

class OpenCell : public Cell {
private:
    int numberOfSurroundingBombs;
public:
    OpenCell();
    ~OpenCell();

    // Gets the value of the cell (if not a bomb)
    virtual int getNumberOfSurroundingBombs();

    virtual void setNumberOfSurroundingBombs(int value);

    virtual int getValueInside();

    virtual char getSymbol();

};


#endif //MINESWEEPER_PROJECT_OPENCELL_H
