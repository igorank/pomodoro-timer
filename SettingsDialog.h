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
		std::ifstream file;
		char filename[50];

		int PomodoroSessionTime;
		int ShortBreakTime;
		int LongBreakTime;
		int PomToLongBreak;
		char PomToLongBreakChar;
	public:
		SettingsDialog(const wxString& title);
		void OpenConfFile(const char* name);
		void CloseConfFile();
		void ReadConfFile();

		int GetSessionTime() { return PomodoroSessionTime; }
		int GetShortBreakTime() { return ShortBreakTime; }
		int GetLongBreakTime() { return LongBreakTime; }
		int GetPomToLongBreak() { return PomToLongBreak; }

		char GetPomToLongBreakChar();
};

#endif