#include "../include/Cell.h"

Cell::Cell() {
    numberOfSurroundingBombs = 0;
}

void Cell::setNumberOfSurroundingBombs(int value) {
    numberOfSurroundingBombs = value;
}

int Cell::getValueInside() {
    return numberOfSurroundingBombs;
}

char Cell::getSymbol() {
    return 'P';
}
