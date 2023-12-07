#include "../include/MinesweeperWindow.h"
#include "../include/Cell.h"

// Minesweeper game constructor
MinesweeperWindow::MinesweeperWindow(const wxString &title, const wxPoint &pos, const wxSize &size)
        :wxFrame(NULL, wxID_ANY, title, pos, size), board(), timeElapsed(0) {
    // Instantiating the board state
    board.setCells();
    board.setCellValues();
    // Instantiating all the timer values, positions, and styling
    timerText = new wxStaticText(this, wxID_ANY, "Timer: 0s", wxPoint(210, 10));
    wxFont timerFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);
    timerText->SetFont(timerFont);
    timer.SetOwner(this, wxID_ANY);
    timer.Start(1000);
    // Binds the timer object to the OnTick function and this MinesweeperWindow
    Bind(wxEVT_TIMER, &MinesweeperWindow::OnTick, this);
    // Instantiating all the game status values, positions, and styling
    statusText = new wxStaticText(this, wxID_ANY, "Game in progress", wxPoint(10, 10));
    wxFont statusFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);
    statusText->SetFont(statusFont);
    // Instantiate the button to reset the game, with the correct functions
    wxButton* resetGameButton = new wxButton(this, wxID_ANY, "Restart", wxPoint(210, 560), wxSize(80, 30));
    resetGameButton->Bind(wxEVT_BUTTON, &MinesweeperWindow::resetGame, this);
    // MAKE AND RENDER THE BOARD FOR THE ACTUAL GUI WINDOW
    makeBoard();
    rerenderGUI();
}

/*
 * Initializes the board cell buttons and renders the gui, setting the colors of the background color
 */
void MinesweeperWindow::makeBoard() {
    int boardSize = board.getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            cellButtons[x][y] = new wxButton(this, wxID_ANY, "", wxPoint(x * 50, (y * 50) + 50), wxSize(50, 50));
            cellButtons[x][y]->Bind(wxEVT_BUTTON, [this, x, y](wxCommandEvent& event) {
                board.clickCell(x,y);
                rerenderGUI();
            });
        }
    }
    // This is purely meant for keeping colors the same from the start when resetting a new game
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            // Sets the color to the reset buttons to the original wxButton color
            wxColour defaultColor = wxColour(58,44,39);
            cellButtons[x][y]->SetBackgroundColour(defaultColor);
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
            wxColour revealedColor(2, 60, 147);
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
                    // Different text colors for different inner cell values
                    wxColour textColor(255, 255, 255);
                    switch (board.board[x][y]->getValueInside()) {
                        case 1: {
                            textColor = wxColour(255, 255, 255); // White
                            break;
                        }
                        case 2: {
                            textColor = wxColour(255, 165, 0); // Gold
                            break;
                        }
                        case 3: {
                            textColor = wxColour(255, 40, 255); // Purple
                            break;
                        }
                        case 4: {
                            textColor = wxColour(53, 255, 138); // Green
                            break;
                        }
                    }
                    cellButtons[x][y]->SetForegroundColour(textColor);
                    buttonText = wxString::Format("%d", value);
                }
                // Set the correct cell color
                cellButtons[x][y]->SetBackgroundColour(revealedColor);
            }
            // if cell[x][y] is revealed, set the label, else leave blank
            cellButtons[x][y]->SetLabel(buttonText);
        }
    }
    // If the game is ended also set the game status to show state of the game (not just relying on timer)
    if (board.gameEnded) {
        wxString newStatusText = wxString("GAME OVER!!!");
        wxFont statusFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);
        statusText->SetFont(statusFont);
        statusText->SetLabel(newStatusText);
    }
    // Add checking for if the game is over through the board
    // If all the OpenCells are revealed
}

// When exiting the window, close the app
void MinesweeperWindow::OnExit(wxCommandEvent& event)
{
    Close( true );
}

// OnTick function for the timer
void MinesweeperWindow::OnTick(wxTimerEvent& event){
    if (!board.gameEnded) {
        timeElapsed++;
        wxString newTickLabel = wxString::Format("Timer: %ds", timeElapsed);
        timerText->SetLabel(newTickLabel);
    }
}

/*
 * Resets the game
 * - Resets the board
 * - Resets the game status label to 'In progress'
 * - Resets the timer label and value
 * - Resets all the board colors
 */
void MinesweeperWindow::resetGame(wxCommandEvent &event) {
    board.resetBoard();
    timeElapsed = 0;
    wxString newTickLabel = wxString::Format("Timer: %ds", timeElapsed);
    timerText->SetLabel(newTickLabel);
    wxString newStatusText = wxString("Game in progress");
    statusText->SetLabel(newStatusText);
    int boardSize = board.getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            // Sets the color to the reset buttons to the original wxButton color
            wxColour defaultColor = wxColour(58,44,39);
            cellButtons[x][y]->SetBackgroundColour(defaultColor);
        }
    }
    rerenderGUI();
}