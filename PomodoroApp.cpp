#include "PomodoroApp.h"
#include "Frame.h"

IMPLEMENT_APP(PomodoroApp);

bool PomodoroApp::OnInit()
{
    Frame * frame = new Frame(wxT("Test"));
    frame->Show(true);

    return true;
}
