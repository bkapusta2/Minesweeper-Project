#include "../include/Cell.h"

Cell::Cell() {
    numberOfSurroundingBombs = 0;
    revealed = false;
}

// Set the value of a cell based on the number of surrounding bombs
void Cell::setNumberOfSurroundingBombs(int value) {
    numberOfSurroundingBombs = value;
}

// Should return the current set number of surrounding bombs value for the cell
int Cell::getValueInside() {
    return numberOfSurroundingBombs;
}

// Returns the symbol for a cell type
char Cell::getSymbol() {
    return 'P';
}

// Set the revealed value of the cell to the given argument
void Cell::setRevealed(bool revealed) {
    this->revealed = revealed;
}

// Return if the cell is revealed or not
bool Cell::isRevealed() {
    return this->revealed;
};
