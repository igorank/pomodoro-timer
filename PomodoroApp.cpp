#ifdef __WXMSW__
    #include <wx/msw/msvcrt.h>
#endif
#include "PomodoroApp.h"
#include "Frame.h"

IMPLEMENT_APP(PomodoroApp);

bool PomodoroApp::OnInit()
{
    frame = new Frame(wxT("Pomodoro"), windowWidth, windowHeight);
    frame->Show(true);
    //_CrtDumpMemoryLeaks();
    return true;
}
