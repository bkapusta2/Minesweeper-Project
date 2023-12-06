#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "lib/include/MinesweeperWindow.h"
#endif


class MinesweeperApp: public wxApp {
public:
    virtual bool OnInit() override;
};


wxIMPLEMENT_APP(MinesweeperApp);


bool MinesweeperApp::OnInit()
{
    MinesweeperWindow* window = new MinesweeperWindow( "Minesweeper", wxPoint(50, 50), wxSize(450, 340) );
    window->Show( true );
    return true;
}
