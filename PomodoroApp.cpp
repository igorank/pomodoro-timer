#include "PomodoroApp.h"
#include "Frame.h"

const int windowWidth= 400;
const int windowHeight = 400;

IMPLEMENT_APP(PomodoroApp);

bool PomodoroApp::OnInit()
{
    Frame * frame = new Frame(wxT("Test"), windowWidth, windowHeight);
    frame->Show(true);

    return true;
}
