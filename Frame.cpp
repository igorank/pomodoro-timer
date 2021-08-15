#include "Frame.h"

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));

	wxPanel* panel = new wxPanel(this, wxID_ANY);
	
	wxSizer* s0 = new wxBoxSizer(wxHORIZONTAL);
	s0->AddStretchSpacer();
	wxButton* button = new wxButton(panel, wxID_EXIT, wxT("Start"));
	s0->Add(button, 0, wxALL | wxALIGN_BOTTOM, 100);
	s0->AddStretchSpacer();
	panel->SetSizer(s0);

	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::StartButton));
	button->SetFocus();
}

void Frame::StartButton(wxCommandEvent& WXUNUSED(event))
{
	//
}
