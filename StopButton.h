#ifndef STOPBUTTON_H_INCLUDED
#define STOPBUTTON_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class StopButton : public wxButton
{
public:
	StopButton(wxPanel* panel, wxStandardID ID, const char* title, wxPoint pos);
	void Clicked(wxCommandEvent& WXUNUSED(event));

	wxPanel* m_parent;
};

#endif
