#include "../include/MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, pos, size), board() {
    makeBoard();
    rerenderGUI();
}

void MinesweeperWindow::makeBoard() {
    int boardSize = board.getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            cellButtons[x][y] = new wxButton(this, wxID_ANY, "", wxPoint(x * 30, y * 30), wxSize(30, 30));
            cellButtons[x][y]->Bind(wxEVT_BUTTON, [this, x, y](wxCommandEvent& event) {
                // Implement button click event based on the button
                // Use gameBoard methods to update the board state
                // Example: gameBoard.clickCell(x, y);
                rerenderGUI();
            });
        }
    }
}

void MinesweeperWindow::rerenderGUI() {
    int boardSize = board.getBoardSize();
    // Update GUI elements and re render
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            char symbol = board[x][y].getSymbol();
            int value = board[x][y].getValueInside();
            wxString buttonText = wxString::Format("%c%d", symbol, value);
            cellButtons[x][y]->SetLabel(buttonText);
        }
    }
}