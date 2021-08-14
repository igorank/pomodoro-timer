#ifndef POMODOROAPP_H_INCLUDED
#define POMODOROAPP_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class PomodoroApp : public wxApp
{
    public:
    virtual bool OnInit();
};

#endif // POMODOROAPP_H_INCLUDED
