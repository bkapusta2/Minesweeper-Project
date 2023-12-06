#include "../include/Cell.h"

Cell::Cell() {
    numberOfSurroundingBombs = 0;
    revealed = false;
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

void Cell::setRevealed(bool revealed) {
    this->revealed = revealed;
}

bool Cell::isRevealed() {
    return this->revealed;
};
