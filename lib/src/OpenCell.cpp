#include "../include/OpenCell.h"

OpenCell::OpenCell() : Cell() {
    numberOfSurroundingBombs = 0;
    revealed = false;
}

// Set the value of a cell based on the number of surrounding bombs
void OpenCell::setNumberOfSurroundingBombs(int value) {
    numberOfSurroundingBombs = value;
}

// Should return the current set number of surrounding bombs value for the cell
int OpenCell::getValueInside() {
    return numberOfSurroundingBombs;
}

// Returns the symbol 'O' to recognize an open (or non-bomb) cell
char OpenCell::getSymbol() {
    return 'O';
}
