#include "../include/BombCell.h"

BombCell::BombCell() : Cell() {
    numberOfSurroundingBombs = -1;
}

int BombCell::getValueInside() {
    return -1;
}

char BombCell::getSymbol() {
    return 'B';
}
