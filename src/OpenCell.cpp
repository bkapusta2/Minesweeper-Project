#include "../include/OpenCell.h"

OpenCell::OpenCell() : Cell() {
    numberOfSurroundingBombs = 0;
}

int OpenCell::getNumberOfSurroundingBombs() {
    return numberOfSurroundingBombs;
}

void OpenCell::setNumberOfSurroundingBombs(int value) {
    numberOfSurroundingBombs = value;
}

int OpenCell::getValueInside() {
    getNumberOfSurroundingBombs();
}

char OpenCell::getSymbol() {
    return 'O';
}
