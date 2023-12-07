#ifndef MINESWEEPER_PROJECT_MINESWEEPERWINDOW_H
#define MINESWEEPER_PROJECT_MINESWEEPERWINDOW_H

#include <wx/wx.h>
#include "Board.h"


class MinesweeperWindow : public wxFrame {
public:
    MinesweeperWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxTimer timer;
    int timeElapsed;
    wxStaticText* timerText;
    Board board;
    wxButton* cellButtons[10][10];
    void OnExit(wxCommandEvent& event);
    void OnTick(wxTimerEvent& event);
    void makeBoard();
    void rerenderGUI();
};


#endif //MINESWEEPER_PROJECT_MINESWEEPERWINDOW_H
