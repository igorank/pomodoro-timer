#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(const wxString& title) :
	wxDialog(nullptr, 1, title, wxDefaultPosition, wxSize(350, 330))
{
	wxPanel* panel = new wxPanel(this, 1);

	OpenConfFile("data\\config.cfg");
	ReadConfFile();

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* Pomodoro = new wxStaticText(this, wxID_ANY, wxT("Pomodoro:"),
		wxPoint(25, 33));
	wxStaticText* ShortBreak = new wxStaticText(this, wxID_ANY, wxT("Short break:"),
		wxPoint(25, 83));
	wxStaticText* LongBreak = new wxStaticText(this, wxID_ANY, wxT("Long break:"),
		wxPoint(25, 133));
	wxStaticText* PomToLongBreak = new wxStaticText(this, wxID_ANY, wxT("Pomodoros to a long break:"),
		wxPoint(25, 183));

	wxSlider* SessionTimeSlider = new wxSlider(panel, 100, GetSessionTime(), 5, 55,
		wxPoint(100, 30), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSlider* ShortBreakSlider = new wxSlider(panel, 101, GetShortBreakTime(), 1, 30,
		wxPoint(100, 80), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSlider* LongBreakSlider = new wxSlider(panel, 102, GetLongBreakTime(), 5, 55,
		wxPoint(100, 130), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSpinCtrl* PomToLongSpinCtrl = new wxSpinCtrl(panel, wxID_ANY, GetPomToLongBreakChar(), wxPoint(180, 180), wxDefaultSize,
		wxSP_ARROW_KEYS, 1, 8, GetPomToLongBreak());

	wxButton* okButton = new wxButton(this, -1, wxT("Ok"),
		wxDefaultPosition, wxSize(70, 30));

	hbox->Add(okButton, 1);

	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	SetSizer(vbox);

	Centre();
	ShowModal();

	CloseConfFile();
	Destroy();
}

void SettingsDialog::OpenConfFile(const char* name)
{
	file.open(name);
}

void SettingsDialog::CloseConfFile()
{
	file.close();
}

void SettingsDialog::ReadConfFile()
{
	file >> PomodoroSessionTime;
	file >> ShortBreakTime;
	file >> LongBreakTime;
	file >> PomToLongBreak;
}

char SettingsDialog::GetPomToLongBreakChar()
{
	PomToLongBreakChar = '0' + PomToLongBreak;
	return PomToLongBreakChar;
}
