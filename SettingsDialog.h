#ifndef SETTINGSDIALOG_H_INCLUDED
#define SETTINGSDIALOG_H_INCLUDED

#include <wx/wxprec.h>
	#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/spinctrl.h>
#include <fstream>


class SettingsDialog : public wxDialog
{
	private:
		wxSlider* SessionTimeSlider;
		wxSlider* ShortBreakSlider;
		wxSlider* LongBreakSlider;
		wxSpinCtrl* PomToLongSpinCtrl;

		wxPanel* panel;
		wxPanel* m_parent;

		std::ifstream rfile;
		std::ofstream wfile;
		char filename[50];

		int PomodoroSessionTime;
		int ShortBreakTime;
		int LongBreakTime;
		int PomToLongBreak;
		char PomToLongBreakChar;
	public:
		SettingsDialog(const wxString& title, wxPanel* ptr);
		void OpenConfFile(const char* name);
		void CloseConfFile();
		void ReadConfFile();
		void SaveConfFile();

		int GetSessionTime() { return PomodoroSessionTime; }
		int GetShortBreakTime() { return ShortBreakTime; }
		int GetLongBreakTime() { return LongBreakTime; }
		int GetPomToLongBreak() { return PomToLongBreak; }

		char GetPomToLongBreakChar();

		void onOkButton(wxCommandEvent& WXUNUSED);
		bool Was_SettingChanged();
};

#endif