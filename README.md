# Minesweeper Project
 
This project implements wxWidgets and object-oriented programming to create a GUI-based application to play a
simple local version of minesweeper.

_Libraries used:_
- wxWidgets: https://wxwidgets.org/
- doctest: https://github.com/doctest/doctest

You can run the project just by running the project, there are no arguments to be accepted

## _How to play minesweeper:_

You want to reveal all the open cells (using buttons) without touching any bombs. A cell's value is determined
by how many bombs are directly surrounding it on its surrounding 8 cells. Clicking a cell will reveal its inner value,
which is either a further clue to figuring out the position of more bombs, or a bomb itself which will end the game.
You want to achieve the lowest possible time for beating the game. You may restart the game by pressing the restart button.

### Notes:
- Since no bombs are surrounding a cell with a value of 0, clicking on one of those cell will reveal all the 
surrounding cells. This can often lead to a chain reaction of 0's being revealed by clicking 0's.