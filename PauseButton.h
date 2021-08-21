#ifndef PAUSE_H_INCLUDED
#define PAUSE_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class PauseButton : public wxButton
{
public:
	PauseButton(wxPanel* panel, wxStandardID ID, const char* title);
	void Clicked(wxCommandEvent& WXUNUSED(event));

	wxPanel* m_parent;
};

#endif

