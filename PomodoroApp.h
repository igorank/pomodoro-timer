#ifndef POMODOROAPP_H_INCLUDED
#define POMODOROAPP_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Frame.h"

class PomodoroApp : public wxApp
{
    public:
        Frame* frame;

        virtual bool OnInit();
};

#endif
