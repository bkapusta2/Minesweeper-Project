#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "lib/include/MinesweeperWindow.h"
#endif


class MinesweeperApp: public wxApp {
public:
    virtual bool OnInit();
};


wxIMPLEMENT_APP(MinesweeperApp);


bool MinesweeperApp::OnInit()
{
    MinesweeperWindow* window = new MinesweeperWindow( "Minesweeper", wxPoint(100, 100), wxSize(507, 650) );
    window->Show( true );
    return true;
}
