#include "../include/Board.h"
#include "../include/BombCell.h"
#include "../include/OpenCell.h"

Board::Board(){
    board.resize(size, std::vector<Cell*>(size, nullptr));
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
            board[x][y].
        }
    }
}
