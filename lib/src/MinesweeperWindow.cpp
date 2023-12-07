#include "../include/MinesweeperWindow.h"
#include "../include/Cell.h"

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

void MinesweeperWindow::makeBoard() {
    int boardSize = board.getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            cellButtons[x][y] = new wxButton(this, wxID_ANY, "", wxPoint(x * 50, (y * 50) + 50), wxSize(50, 50));
            cellButtons[x][y]->Bind(wxEVT_BUTTON, [this, x, y](wxCommandEvent& event) {
                // Add checking for if the game is over through the board
                    // If a bomb is clicked or if all the OpenCells are revealed
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
    if (board.gameEnded) {
        wxString newStatusText = wxString("GAME OVER!!!");
        wxFont statusFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);
        statusText->SetFont(statusFont);
        statusText->SetLabel(newStatusText);
    }
}

void MinesweeperWindow::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MinesweeperWindow::OnTick(wxTimerEvent& event){
    if (!board.gameEnded) {
        timeElapsed++;
        wxString newTickLabel = wxString::Format("Timer: %ds", timeElapsed);
        timerText->SetLabel(newTickLabel);
    }
}

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