#include "../include/MinesweeperWindow.h"
#include "../include/Cell.h"

MinesweeperWindow::MinesweeperWindow(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, pos, size), board() {
    board.setCells();
    board.setCellValues();
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
                board.clickCell(x,y);
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
            char symbol = board.board[x][y]->getSymbol();
            int value = board.board[x][y]->getValueInside();
            wxString buttonText = "";
            if (board.board[x][y]->isRevealed()) {
                if (symbol == 'B') {
                    buttonText = wxString::Format("%c", symbol);
                }
                else {
                    buttonText = wxString::Format("%d", value);
                }
            }
            // if cell[x][y] is revealed, set the label, else leave blank
            cellButtons[x][y]->SetLabel(buttonText);
        }
    }
}

void MinesweeperWindow::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MinesweeperWindow::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' made Minesweeper game",
                  "About Minesweeper", wxOK | wxICON_INFORMATION );
}