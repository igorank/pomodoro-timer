#include "Frame.h"

enum
{
	ID_Settings = 1
};

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_MENU(ID_Settings, Frame::OnSettings)
	EVT_MENU(wxID_ABOUT, Frame::OnAbout)
	EVT_MENU(wxID_EXIT, Frame::OnExit)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,
	wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));

	parent = new wxPanel(this, wxID_ANY);

	wxMenuBar* menuBar = new wxMenuBar;
	wxMenu* menuOptions = new wxMenu;
	menuOptions->Append(ID_Settings, "&Settings\tCtrl-S",
		"string");
	menuOptions->AppendSeparator();
	menuOptions->Append(wxID_EXIT);

	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	menuBar->Append(menuOptions, "&Options");
	menuBar->Append(menuHelp, "&Help");
	
	timer = new Timer(parent, wxID_ANY, "Timer");

	wxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);

	buttons_sizer->AddStretchSpacer();

	startbutton = new StartButton(parent, wxID_ANY, "Start");
	stopbutton = new StopButton(parent, wxID_ANY, "Stop");
	pausebutton = new PauseButton(parent, wxID_ANY, "Pause");

	buttons_sizer->Add(stopbutton, 0, wxALL | wxALIGN_BOTTOM, 15);
	buttons_sizer->Add(startbutton, 0, wxALL | wxALIGN_BOTTOM, 15);
	buttons_sizer->Add(pausebutton, 0, wxALL | wxALIGN_BOTTOM, 15);

	top_sizer->Add(timer, 0, wxALL | wxALIGN_CENTER, 120);

	buttons_sizer->AddStretchSpacer();

	top_sizer->Add(buttons_sizer, wxSizerFlags(0).Center());

	parent->SetSizerAndFit(top_sizer);

	SetMenuBar(menuBar);

	//CreateStatusBar();
	//SetStatusText("Pomodoros today:");
}

void Frame::OnSettings(wxCommandEvent& event)
{
	settingsdlg = new SettingsDialog("Settings", parent);
}

void Frame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("Pomodoro is a customizable pomodoro timer that works on desktop. The aim of this app is to help you focus on any task you are working on, such as study, writing, or coding. This app is inspired by Pomodoro Technique which is a time management method developed by Francesco Cirillo.\n\t\nOnline documentation: https://github.com/igorank/PomodoroTimer \n© 2021 anikinigor165@gmail.com\nAll rights reserved.",
		"About Pomodoro", wxOK | wxICON_INFORMATION);
}

void Frame::OnExit(wxCommandEvent& event)
{
	Close(true);
}