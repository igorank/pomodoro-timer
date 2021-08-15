#include "Frame.h"
#include "StartButton.h"

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,
	wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));

	wxPanel* panel = new wxPanel(this, wxID_ANY);
	
	wxSizer* StartButton_sizer = new wxBoxSizer(wxHORIZONTAL);
	StartButton_sizer->AddStretchSpacer();
	StartButton* startbutton = new StartButton(panel, wxID_OK, "Start");
	StartButton_sizer->Add(startbutton, 0, wxALL | wxALIGN_BOTTOM, 50);
	StartButton_sizer->AddStretchSpacer();

	panel->SetSizer(StartButton_sizer);

	Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StartButton::Clicked));
	startbutton->SetFocus();
}
