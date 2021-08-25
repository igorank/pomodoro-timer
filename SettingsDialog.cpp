#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(const wxString& title) :
	wxDialog(nullptr, 1, title, wxDefaultPosition, wxSize(350, 330))
{
	wxPanel* panel = new wxPanel(this, 1);

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

	wxSlider* SessionTimeSlider = new wxSlider(panel, 100, 25, 5, 55,
		wxPoint(100, 30), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSlider* ShortBreakSlider = new wxSlider(panel, 101, 5, 1, 30,
		wxPoint(100, 80), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSlider* LongBreakSlider = new wxSlider(panel, 102, 15, 5, 55,
		wxPoint(100, 130), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	wxSpinCtrl* PomToLongSpinCtrl = new wxSpinCtrl(panel, wxID_ANY, '4', wxPoint(180, 180), wxDefaultSize,
		wxSP_ARROW_KEYS, 1, 8, 4);

	wxButton* okButton = new wxButton(this, -1, wxT("Ok"),
		wxDefaultPosition, wxSize(70, 30));

	hbox->Add(okButton, 1);

	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	SetSizer(vbox);

	Centre();
	ShowModal();

	Destroy();
}