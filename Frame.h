#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Frame : public wxFrame
{
    public:
    Frame(const wxString& title, int width, int height);
};

#endif // FRAME_H_INCLUDED
