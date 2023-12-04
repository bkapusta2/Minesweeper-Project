#ifndef MINESWEEPER_PROJECT_OPENCELL_H
#define MINESWEEPER_PROJECT_OPENCELL_H
#include "Cell.h"

class OpenCell : public Cell {
private:
    int numberOfSurroundingBombs;
public:
    OpenCell();
    ~OpenCell();

    virtual void setNumberOfSurroundingBombs(int value);

    virtual int getValueInside();

    virtual char getSymbol();

};


#endif //MINESWEEPER_PROJECT_OPENCELL_H
