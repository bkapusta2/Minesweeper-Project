#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "lib/include/MinesweeperWindow.h"
#include "lib/include/Board.h"
#include "lib/include/Cell.h"
#include "lib/include/OpenCell.h"
#include "lib/include/BombCell.h"

TEST_CASE("Testing board creation") {
    SUBCASE("Check for board size") {
        Board board;
        CHECK(board.getBoardSize() == 10);
    }

    SUBCASE("Check for instantiated cell types") {
        Board board;
        board.setCells();
        board.setCellValues();

        CHECK(board.board[0][0]->getSymbol() != 'P');
        CHECK(board.board[5][3]->getSymbol() != 'P');
        CHECK(board.board[8][3]->getSymbol() != 'P');
    }
}

TEST_CASE("On click related tests") {
    SUBCASE("Test for clicking") {
        Board board;
        board.setCells();
        board.setCellValues();

        board.clickCell(3, 4);
        CHECK(board.board[3][4]->isRevealed() == true);
    }

    SUBCASE("Test for game end on only bombs left IMPLEMENT") {
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

    SUBCASE("Test for game end on bomb click") {
        Board board;
        board.setCells();
        board.board[0][0] = new BombCell();
        board.setCellValues();

        board.clickCell(0, 0);
        CHECK(board.board[0][0]->isRevealed() == true);
        CHECK(board.gameEnded == true);
    }
}

TEST_CASE("Cell value tests") {
    SUBCASE("Checking for inner value bomb") {
        Board board;
        board.setCells();
        board.board[0][0] = new BombCell();
        board.setCellValues();
        CHECK(board.board[0][0]->getValueInside() == -1);
    }

    SUBCASE("Checking for inner value open cell") {
        Board board;
        board.setCells();
        board.board[0][0] = new OpenCell();
        board.setCellValues();
        CHECK(board.board[0][0]->getValueInside() >= 0);
    }
}

TEST_CASE("Testing board reset") {
    SUBCASE("Board reset prior to loss") {
        Board board;
        board.setCells();
        board.setCellValues();

        board.clickCell(6, 6);
        CHECK(board.board[6][6]->isRevealed() == true);
        board.resetBoard();
        CHECK(board.board[6][6]->isRevealed() == false);
    }

    SUBCASE("Board reset after loss") {
        Board board;
        board.setCells();
        board.board[1][1] = new BombCell();
        board.setCellValues();
        board.clickCell(1,1);
        CHECK(board.gameEnded == true);
        board.resetBoard();
        CHECK(board.gameEnded == false);
    }
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




