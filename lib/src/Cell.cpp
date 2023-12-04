#include "../../include/Cell.h"

Cell::Cell() {
    numberOfSurroundingBombs = 0;
}

void Cell::setNumberOfSurroundingBombs(int value) {
    numberOfSurroundingBombs = value;
}