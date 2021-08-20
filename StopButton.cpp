#include "StopButton.h"
#include "Frame.h"

StopButton::StopButton(wxPanel* panel, wxStandardID ID, const char* title, wxPoint pos) : wxButton(panel, ID, wxString(title),
	pos)
{
	m_parent = panel;
	Connect(ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StopButton::Clicked));
}

void StopButton::Clicked(wxCommandEvent& WXUNUSED)
{
	Frame* frame = (Frame*)m_parent->GetParent();
	frame->timer->StopTimer(WXUNUSED);
}