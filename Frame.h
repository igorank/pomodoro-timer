#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "StartButton.h"
#include "Timer.h"

const int windowWidth = 400;
const int windowHeight = 400;

class Frame : public wxFrame
{
    public:
    Frame(const wxString& title, int width, int height);

    wxPanel* parent;
    StartButton* startbutton;
    Timer* timer;
};

#endif // FRAME_H_INCLUDED
