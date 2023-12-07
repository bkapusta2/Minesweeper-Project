#include "../include/Board.h"
#include "../include/BombCell.h"
#include "../include/OpenCell.h"
#include <iostream>

using std::cout, std::endl;

Board::Board(){
    this->size = 10;
    board.resize(size, std::vector<Cell*>(size, nullptr));
    gameEnded = false;
}

Board::~Board() {
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board.size(); x++) {
            delete board[x][y];
        }
    }
}

// This will create all of the cells randomly with a 20% chance of each cell being a bomb.
// Maybe try to implement adding a certain difficult (easy is 10% and hard is 30%)
void Board::setCells(){
    for (int y = 0; y < board.size(); y++){
        for (int x = 0; x < board.size(); x++){
            int randomValue = std::rand() % 10 + 1;
            if (randomValue <= 2) {
                board[x][y] = new BombCell();
            }
            else {
                board[x][y] = new OpenCell();
            }
        }
    }
}

// Set the internal value of each cell depending on if its a bomb (-1)
// or how many bombs are directly surrounding it
void Board::setCellValues() {
    for (int y = 0; y < board.size(); y++){
        for (int x = 0; x < board.size(); x++){
            // Counting the number of bombs surrounding the currently looked at cell
            int cellBombCount = 0;

            // Going through each spot around the current cell
            for (int deltaY = -1; deltaY <= 1; deltaY ++) {
                for (int deltaX = -1; deltaX <= 1; deltaX ++) {
                    // If the current cell, skip
                    if (deltaY == 0 && deltaX == 0) {
                        continue;
                    }
                    int currentlyCheckingY = y + deltaY;
                    int currentlyCheckingX = x + deltaX;
                    // If the cell is within the bounds of the board and is a bomb, add one to the bomb count
                    if (currentlyCheckingY >= 0 && currentlyCheckingX >= 0 &&
                        currentlyCheckingY < board.size() && currentlyCheckingX < board.size()) {
                        if (board[currentlyCheckingX][currentlyCheckingY]->getSymbol() == 'B') {
                            cellBombCount++;
                        }
                    }

                }
            }

            if (board[x][y]->getSymbol() == 'O') {
                board[x][y]->setNumberOfSurroundingBombs(cellBombCount);
            }
        }
    }
}

// Show the board (for testing in console)
void Board::printBoard() {
    for (int y = 0; y < size; y++) {
        cout << "|";
        for (int x = 0; x < size; x++) {
            if (board[x][y] != nullptr) {
                cout << board[x][y]->getSymbol() << board[x][y]->getValueInside() << "|";
            }
            else {
                cout << " |";
            }
        }
        std::cout << std::endl;
    }
}

// Return the size of the board given
int Board::getBoardSize() {
    return board.size();
}

Cell& Board::getCell(int x, int y){
    return *(board[x][y]);
}

void Board::clickCell(int x, int y) {
    if (!gameEnded){
        Cell& clickedCell = *board[x][y];
        if (clickedCell.getSymbol() == 'B') {
            // Handle bomb click, end the game
            clickedCell.setRevealed(true);
            for (int j = 0; j < board.size(); j++){
                for (int i = 0; i < board.size(); i++) {
                    if (board[i][j]->getSymbol() == 'B') {
                        Cell& bombCell = *board[i][j];
                        bombCell.setRevealed(true);
                    }
                }
            }
            gameEnded = true;
            // LATER IMPLEMENT REVEALING WHOLE BOARD
        }
        else {
            // Go through each surrounding element and if 0, reveal all of the values around (no bombs)
            if (clickedCell.getValueInside() == 0) {
                for (int deltaY = -1; deltaY <= 1; deltaY ++) {
                    for (int deltaX = -1; deltaX <= 1; deltaX ++) {
                        // If the current cell, skip
                        if (deltaY == 0 && deltaX == 0) {
                            continue;
                        }
                        int currentlyCheckingY = y + deltaY;
                        int currentlyCheckingX = x + deltaX;
                        // If the cell is within the bounds of the board and is a bomb, add one to the bomb count
                        if (currentlyCheckingY >= 0 && currentlyCheckingX >= 0 &&
                            currentlyCheckingY < board.size() && currentlyCheckingX < board.size()) {
                            Cell& surroundingCell = *board[currentlyCheckingX][currentlyCheckingY];
                            surroundingCell.setRevealed(true);
                        }
                    }
                }
            }
            clickedCell.setRevealed(true);
        }
    }
}

void Board::resetBoard() {
    gameEnded = false;
    this->setCells();
    this->setCellValues();
}
