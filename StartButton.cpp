#include "StartButton.h"
#include "Frame.h"

StartButton::StartButton(wxPanel* panel, wxStandardID ID, const char * title) : wxButton(panel, ID, wxString(title))
{
	m_parent = panel;
	Connect(ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StartButton::Clicked));
	clicked_atl_once = false;
}

void StartButton::Clicked(wxCommandEvent& WXUNUSED)
{
	clicked_atl_once = true;
	Frame* frame = (Frame*)m_parent->GetParent();
	if (frame->timer->getTimer().IsRunning())
	{
		this->SetLabel(wxString("Reset"));
		frame->timer->StopTimer(WXUNUSED);
		frame->timer->StartTimer(WXUNUSED);
	}
	else
		frame->timer->StartTimer(WXUNUSED);
		this->SetLabel(wxString("Reset"));
}