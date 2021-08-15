#include "StartButton.h"

StartButton::StartButton(wxPanel* panel, wxStandardID ID, const char * title) : wxButton(panel, ID, wxString(title))
{
	
}

void StartButton::Clicked(wxCommandEvent& WXUNUSED)
{
	Close(true);
}
