#include "Frame.h"

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,
	wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));

	parent = new wxPanel(this, wxID_ANY);
	
	timer = new Timer(parent, wxID_ANY, "test");

	wxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);

	buttons_sizer->AddStretchSpacer();

	startbutton = new StartButton(parent, wxID_OK, "Start");
	stopbutton = new StopButton(parent, wxID_ANY, "Stop");
	pausebutton = new PauseButton(parent, wxID_ANY, "Pause");

	buttons_sizer->Add(stopbutton, 0, wxALL | wxALIGN_BOTTOM, 15);
	buttons_sizer->Add(startbutton, 0, wxALL | wxALIGN_BOTTOM, 15);
	buttons_sizer->Add(pausebutton, 0, wxALL | wxALIGN_BOTTOM, 15);

	top_sizer->Add(timer, 0, wxALL | wxALIGN_CENTER, 120);

	buttons_sizer->AddStretchSpacer();

	top_sizer->Add(buttons_sizer, wxSizerFlags(0).Center());

	parent->SetSizerAndFit(top_sizer);
}