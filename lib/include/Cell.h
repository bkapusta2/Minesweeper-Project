#ifndef MINESWEEPER_PROJECT_CELL_H
#define MINESWEEPER_PROJECT_CELL_H


class Cell {
private:
    int numberOfSurroundingBombs;
    bool revealed;
public:
    Cell();

    // If -1 it should be a bomb
    virtual int getValueInside();

    // Use only for OpenCell (bombs always are -1 value)
    virtual void setNumberOfSurroundingBombs(int value);

    virtual char getSymbol();

    virtual void setRevealed(bool revealed);

    virtual bool isRevealed();
};


#endif //MINESWEEPER_PROJECT_CELL_H
