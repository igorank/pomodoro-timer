#include "Frame.h"

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,
	wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));

	parent = new wxPanel(this, wxID_ANY);
	
	wxSizer* StartButton_sizer = new wxBoxSizer(wxHORIZONTAL);
	StartButton_sizer->AddStretchSpacer();
	startbutton = new StartButton(parent, wxID_OK, "Start");
	StartButton_sizer->Add(startbutton, 0, wxALL | wxALIGN_BOTTOM, 50);
	StartButton_sizer->AddStretchSpacer();

	parent->SetSizer(StartButton_sizer);

	startbutton->SetFocus();

	stopbutton = new StopButton(parent, wxID_ANY, "Stop", wxPoint(200,200));

	timer = new Timer(parent,wxID_ANY,"dddddddddddddddddddddddd");
}