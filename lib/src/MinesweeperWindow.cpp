#include "../include/MinesweeperWindow.h"
#include "../include/Cell.h"

MinesweeperWindow::MinesweeperWindow(const wxString &title, const wxPoint &pos, const wxSize &size)
        :wxFrame(NULL, wxID_ANY, title, pos, size), board(), timeElapsed(0) {
    board.setCells();
    board.setCellValues();
    timerText = new wxStaticText(this, wxID_ANY, "Timer: 0s", wxPoint(230, 10));
    timer.SetOwner(this, wxID_ANY);
    timer.Start(1000);
    // Binds the timer object to the OnTick function and this MinesweeperWindow
    Bind(wxEVT_TIMER, &MinesweeperWindow::OnTick, this);
    makeBoard();
    rerenderGUI();
}

void MinesweeperWindow::makeBoard() {
    int boardSize = board.getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            cellButtons[x][y] = new wxButton(this, wxID_ANY, "", wxPoint(x * 50, (y * 50) + 30), wxSize(50, 50));
            cellButtons[x][y]->Bind(wxEVT_BUTTON, [this, x, y](wxCommandEvent& event) {
                // Implement button click event based on the button
                // Use gameBoard methods to update the board state
                // Example: gameBoard.clickCell(x, y);
                // Add checking for if the game is over through the board
                    // If a bomb is clicked or if all the OpenCells are revealed
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
            // Get the symbol and value of the currently looked at cell
            char symbol = board.board[x][y]->getSymbol();
            int value = board.board[x][y]->getValueInside();
            wxString buttonText = "";
            wxColour revealedColor(2, 131, 147);
            // If the cell is revealed (by clicking)
            if (board.board[x][y]->isRevealed()) {
                /* Check if the symbol is B for Bomb
                 * - If it is, reveal the B symbol and set the color of the button to red
                 */
                if (symbol == 'B') {
                    buttonText = wxString::Format("%c", symbol);
                    revealedColor = wxColour(255, 0, 0);
                }
                /* Check if the symbol is B for Bomb
                * - If it isn't, reveal the inner cell value and set the color of the button to blue
                */
                else {
                    buttonText = wxString::Format("%d", value);
                }
                // Set the correct cell color
                cellButtons[x][y]->SetBackgroundColour(revealedColor);
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

void MinesweeperWindow::OnTick(wxTimerEvent& event){
    if (!board.gameEnded) {
        timeElapsed++;
        wxString newLabel = wxString::Format("Timer: %ds", timeElapsed);
        timerText->SetLabel(newLabel);
    }
}