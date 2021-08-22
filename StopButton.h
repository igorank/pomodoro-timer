#ifndef STOPBUTTON_H_INCLUDED
#define STOPBUTTON_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class StopButton : public wxButton
{
	private:
		wxPanel* m_parent;
	public:
		StopButton(wxPanel* panel, wxStandardID ID, const char* title);
		void Clicked(wxCommandEvent& WXUNUSED(event));
};

#endif
