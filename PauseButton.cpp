#include "PauseButton.h"
#include "Frame.h"

PauseButton::PauseButton(wxPanel* panel, wxStandardID ID, const char* title) : wxButton(panel, ID, wxString(title))
{
	m_parent = panel;
	Connect(ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PauseButton::Clicked));
}

void PauseButton::Clicked(wxCommandEvent& WXUNUSED)
{
	Frame* frame = (Frame*)m_parent->GetParent();
	frame->timer->PauseTimer(WXUNUSED);
	frame->startbutton->SetLabel("Continue");
}