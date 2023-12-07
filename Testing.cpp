#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "lib/include/MinesweeperWindow.h"
#include "lib/include/Board.h"
#include "lib/include/Cell.h"
#include "lib/include/OpenCell.h"
#include "lib/include/BombCell.h"

TEST_CASE("Check for board size") {
    Board board;
    CHECK(board.getBoardSize() == 10);
}

TEST_CASE("Check for instantiated cell types") {
    Board board;
    board.setCells();
    board.setCellValues();

    CHECK(board.board[0][0]->getSymbol() != 'P');
    CHECK(board.board[5][3]->getSymbol() != 'P');
    CHECK(board.board[8][3]->getSymbol() != 'P');
}

TEST_CASE("Test for clicking") {
    Board board;
    board.setCells();
    board.setCellValues();

    board.clickCell(3, 4);
    CHECK(board.board[3][4]->isRevealed() == true);
}

// IMPLEMENT
TEST_CASE("Test for game end on only bombs left IMPLEMENT") {
    Board board;
    board.setCells();
    board.setCellValues();
    for (int y = 0; y < board.getBoardSize(); y++) {
        for (int x = 0; x < board.getBoardSize(); x++) {
            if (board.board[x][y]->getSymbol() == 'O') {
                board.clickCell(x, y);
            }
        }
    }
    board.checkGameSuccess();
    CHECK(board.gameEnded == true);
}

TEST_CASE("Test for game end on bomb click") {
    Board board;
    board.setCells();
    board.board[0][0] = new BombCell();
    board.setCellValues();

    board.clickCell(0, 0);
    CHECK(board.board[0][0]->isRevealed() == true);
    CHECK(board.gameEnded == true);
}

TEST_CASE("Testing board reset") {
    Board board;
    board.setCells();
    board.setCellValues();

    board.clickCell(6, 6);
    CHECK(board.board[6][6]->isRevealed() == true);
    board.resetBoard();
    CHECK(board.board[6][6]->isRevealed() == false);
}

TEST_CASE("Checking for inner value bomb") {
    Board board;
    board.setCells();
    board.board[0][0] = new BombCell();
    board.setCellValues();
    CHECK(board.board[0][0]->getValueInside() == -1);
}

TEST_CASE("Checking for inner value open cell") {
    Board board;
    board.setCells();
    board.board[0][0] = new OpenCell();
    board.setCellValues();
    CHECK(board.board[0][0]->getValueInside() >= 0);
}

TEST_CASE("Test revealing all bombs on loss") {
    Board board;
    board.setCells();
    board.board[0][0] = new BombCell();
    board.board[3][3] = new BombCell();
    board.board[4][4] = new BombCell();
    board.board[5][5] = new BombCell();
    board.setCellValues();
    board.clickCell(0,0);
    CHECK(board.board[0][0]->isRevealed() == true);
    CHECK(board.board[3][3]->isRevealed() == true);
    CHECK(board.board[4][4]->isRevealed() == true);
    CHECK(board.board[5][5]->isRevealed() == true);
}



