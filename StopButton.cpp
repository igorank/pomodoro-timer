#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>
#endif
#include "StopButton.h"
#include "Frame.h"

StopButton::StopButton(wxPanel* panel, wxStandardID ID, const char* title) : wxButton(panel, ID, wxString(title))
{
	m_parent = panel;
	Connect(ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StopButton::Clicked));
}

void StopButton::Clicked(wxCommandEvent& WXUNUSED)
{
	Frame* frame = (Frame*)m_parent->GetParent();
	frame->startbutton->Reset_Clicked_At_Least_Once();
	frame->timer->StopTimer(WXUNUSED);
	frame->startbutton->SetLabel("Start");
}