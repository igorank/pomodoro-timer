#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>
#endif
#include "SettingsDialog.h"
#include "Frame.h"

SettingsDialog::SettingsDialog(const wxString& title, wxPanel* ptr) :
	wxDialog(nullptr, 1, title, wxDefaultPosition, wxSize(275, 330))
{
	panel = new wxPanel(this, 1);
	m_parent = ptr;

	OpenConfFile("data\\config.cfg");
	ReadConfFile();

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxStaticBox* box = new wxStaticBox(panel, wxID_ANY, "Timer",wxPoint(5,5),wxSize(250,210));

	wxStaticText* Pomodoro = new wxStaticText(box, wxID_ANY, wxT("Pomodoro:"),
		wxPoint(10, 33));
	wxStaticText* ShortBreak = new wxStaticText(box, wxID_ANY, wxT("Short break:"),
		wxPoint(10, 83));
	wxStaticText* LongBreak = new wxStaticText(box, wxID_ANY, wxT("Long break:"),
		wxPoint(10, 133));
	wxStaticText* PomToLongBreak = new wxStaticText(box, wxID_ANY, wxT("Pomodoros to a long break:"),
		wxPoint(10, 183));

	SessionTimeSlider = new wxSlider(box, 100, GetSessionTime(), 5, 55,
		wxPoint(85, 30), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	ShortBreakSlider = new wxSlider(box, 101, GetShortBreakTime(), 1, 30,
		wxPoint(85, 80), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	LongBreakSlider = new wxSlider(box, 102, GetLongBreakTime(), 5, 55,
		wxPoint(85, 130), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	PomToLongSpinCtrl = new wxSpinCtrl(box, wxID_ANY, GetPomToLongBreakChar(), wxPoint(165, 180), wxDefaultSize,
		wxSP_ARROW_KEYS, 1, 8, GetPomToLongBreak());
	DisplayNotifications = new wxCheckBox(panel, 104, wxString("Display notifications"),wxPoint(10,225));
	DisplayNotifications->SetValue(DisplayNotifi);

	wxButton* okButton = new wxButton(this, 11, wxT("Ok"),
		wxDefaultPosition);
	wxButton* closeButton = new wxButton(this, 12, wxT("Close"),
		wxDefaultPosition);

	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialog::onOkButton));
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialog::onCloseButton));

	hbox->Add(okButton, 1);
	hbox->Add(closeButton, 1, wxLEFT, 5);

	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	SetSizer(vbox);

	Centre();
	ShowModal();

	CloseConfFile();
	Destroy();
}

void SettingsDialog::onOkButton(wxCommandEvent& WXUNUSED)
{
	Frame* frame = (Frame*)m_parent->GetParent();
	if (frame->timer->getTimer().IsRunning() && Was_SettingChanged() || (frame->timer->IsTimerPaused() && !frame->timer->getTimer().IsRunning()
		&& Was_SettingChanged()))
	{
		//wxMessageDialog * WarningMsg = new wxMessageDialog(panel, wxString("The settings were changed after the timer had already started. Changing the settings will restart the timer. Would you like to continue?"),wxString("Warning"), wxYES_NO| wxCENTRE);
		std::unique_ptr<wxMessageDialog> WarningMsg(new wxMessageDialog(panel, wxString("The settings were changed after the timer had already started. Changing the settings will restart the timer. Would you like to continue?"), wxString("Warning"), wxYES_NO | wxCENTRE));
		wxMessageDialog::ButtonLabel YesLabel(wxString("Yes"));
		wxMessageDialog::ButtonLabel NoLabel(wxString("No"));
		WarningMsg->SetYesNoLabels(YesLabel, NoLabel);
		if (WarningMsg->ShowModal() == wxID_YES)
		{
			SaveConfFile();
			frame->timer->StopTimer(WXUNUSED);
			frame->timer->GetSettings("data\\config.cfg");
			frame->timer->SetTimerLabel();
			frame->startbutton->SetLabel(wxString("Start"));
			Close(true);
		}
		else
			WarningMsg->Close();
	}
	else
	{
		SaveConfFile();
		if (Was_SettingChanged())
		{
			frame->timer->GetSettings("data\\config.cfg");
			frame->timer->SetTimerLabel();
		}
		Close(true);
	}
}

void SettingsDialog::onCloseButton(wxCommandEvent& WXUNUSED) 
{
	Close(true);
}

bool SettingsDialog::Was_SettingChanged()
{
	Frame* frame = (Frame*)m_parent->GetParent();
	if (PomodoroSessionTime != SessionTimeSlider->GetValue() || ShortBreakTime != ShortBreakSlider->GetValue() ||
		LongBreakTime != LongBreakSlider->GetValue() || PomToLongBreak != PomToLongSpinCtrl->GetValue()
		|| DisplayNotifi != DisplayNotifications->GetValue())
		return true;
	else
		return false;
}

void SettingsDialog::OpenConfFile(const char* name)
{
	rfile.open(name);
}

void SettingsDialog::CloseConfFile()
{
	rfile.close();
}

void SettingsDialog::ReadConfFile()
{
	rfile >> PomodoroSessionTime;
	rfile >> ShortBreakTime;
	rfile >> LongBreakTime;
	rfile >> PomToLongBreak;
	rfile >> DisplayNotifi;
}

void SettingsDialog::SaveConfFile()
{
	wfile.open("data\\config.cfg");
	wfile << SessionTimeSlider->GetValue();
	wfile << ' ';
	wfile << ShortBreakSlider->GetValue();
	wfile << ' ';
	wfile << LongBreakSlider->GetValue();
	wfile << ' ';
	wfile << PomToLongSpinCtrl->GetValue();
	wfile << ' ';
	wfile << DisplayNotifications->GetValue();
	wfile.close();
}

char SettingsDialog::GetPomToLongBreakChar()
{
	PomToLongBreakChar = '0' + PomToLongBreak;
	return PomToLongBreakChar;
}
