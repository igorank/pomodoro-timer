#include "SettingsDialog.h"
#include "Frame.h"

SettingsDialog::SettingsDialog(const wxString& title, wxPanel* ptr) :
	wxDialog(nullptr, 1, title, wxDefaultPosition, wxSize(350, 330))
{
	panel = new wxPanel(this, 1);
	m_parent = ptr;

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

	SessionTimeSlider = new wxSlider(panel, 100, GetSessionTime(), 5, 55,
		wxPoint(100, 30), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	ShortBreakSlider = new wxSlider(panel, 101, GetShortBreakTime(), 1, 30,
		wxPoint(100, 80), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	LongBreakSlider = new wxSlider(panel, 102, GetLongBreakTime(), 5, 55,
		wxPoint(100, 130), wxSize(140, -1), wxSL_LABELS | wxSL_TOP);
	PomToLongSpinCtrl = new wxSpinCtrl(panel, wxID_ANY, GetPomToLongBreakChar(), wxPoint(180, 180), wxDefaultSize,
		wxSP_ARROW_KEYS, 1, 8, GetPomToLongBreak());

	wxButton* okButton = new wxButton(this, 11, wxT("Ok"),
		wxDefaultPosition, wxSize(70, 30));

	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialog::onOkButton));

	hbox->Add(okButton, 1);

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
	if (frame->timer->getTimer().IsRunning() && Was_SettingChanged())
	{
		wxMessageDialog * WarningMsg = new wxMessageDialog(panel, wxString("Error"),wxString("Warning"), wxYES_NO| wxCENTRE);
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

bool SettingsDialog::Was_SettingChanged()
{
	Frame* frame = (Frame*)m_parent->GetParent();
	if (frame->timer->GetSessionTime() != SessionTimeSlider->GetValue() || frame->timer->GetShortBreakTime() != ShortBreakSlider->GetValue() ||
		frame->timer->GetLongBreakTime() != LongBreakSlider->GetValue() || frame->timer->GetSessionsNum() != PomToLongSpinCtrl->GetValue())
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
	wfile.close();
}

char SettingsDialog::GetPomToLongBreakChar()
{
	PomToLongBreakChar = '0' + PomToLongBreak;
	return PomToLongBreakChar;
}
