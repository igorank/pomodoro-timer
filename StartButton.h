#ifndef STARTBUTTON_H_INCLUDED
#define STARTBUTTON_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class StartButton : public wxButton
{
	private:
		wxPanel* m_parent;
	public:
		StartButton(wxPanel* panel, wxStandardID ID, const char * title);
		void Clicked(wxCommandEvent& WXUNUSED(event));
};

#endif