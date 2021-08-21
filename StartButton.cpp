#include "StartButton.h"
#include "Frame.h"

StartButton::StartButton(wxPanel* panel, wxStandardID ID, const char * title) : wxButton(panel, ID, wxString(title))
{
	m_parent = panel;
	Connect(ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StartButton::Clicked));
}

void StartButton::Clicked(wxCommandEvent& WXUNUSED)
{
	Frame* frame = (Frame*)m_parent->GetParent();
	frame->timer->StartTimer(WXUNUSED);
	if (frame->timer->m_Timer.IsRunning())
		this->SetLabel(wxString("Reset"));
}