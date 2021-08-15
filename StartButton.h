#ifndef STARTBUTTON_H_INCLUDED
#define STARTBUTTON_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class StartButton : public wxButton
{
	public:
		StartButton(wxPanel* panel, wxStandardID, const char * title);
		void Clicked(wxCommandEvent& WXUNUSED(event));

		wxPanel* m_parent;
};

#endif // FRAME_H_INCLUDED