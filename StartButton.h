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

		bool clicked_atl_once;
	public:
		StartButton(wxPanel* panel, wxStandardID ID, const char * title);
		bool Was_Clicked_At_Least_Once() { return clicked_atl_once; }
		void Clicked(wxCommandEvent& WXUNUSED(event));
		void Reset_Clicked_At_Least_Once() { clicked_atl_once = false; }
};

#endif