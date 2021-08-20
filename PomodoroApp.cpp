#include "PomodoroApp.h"
#include "Frame.h"

IMPLEMENT_APP(PomodoroApp);

bool PomodoroApp::OnInit()
{
    frame = new Frame(wxT("Pomodoro"), windowWidth, windowHeight);
    frame->Show(true);

    return true;
}
