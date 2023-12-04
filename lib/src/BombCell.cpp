#include "../../include/BombCell.h"

BombCell::BombCell() : Cell() {
    numberOfSurroundingBombs = -1;
}


// If it's a bomb the value should be -1
int BombCell::getValueInside() {
    return numberOfSurroundingBombs;
}

// Returns the symbol 'B' to recognize a bomb cell
char BombCell::getSymbol() {
    return 'B';
}
