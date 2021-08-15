#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

const int windowWidth = 400;
const int windowHeight = 400;

class Frame : public wxFrame
{
    public:
    Frame(const wxString& title, int width, int height);

    void StartButton(wxCommandEvent& WXUNUSED(event));
};

#endif // FRAME_H_INCLUDED
