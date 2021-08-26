#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/datetime.h>
#include <fstream>
#include "Notification.h"

class Timer : public wxStaticText
{
	private:
		enum TimerState {INIT, PAUSED, STOPPED};
		TimerState timerstate;

		enum PomodoroState {POMODORO,SHORT_BREAK,LONG_BREAK};
		PomodoroState pomodorostate;

		wxTimer m_Timer;
		wxDateTime StartTime;
		wxDateTime currentTime;

		wxTimeSpan pomodoroSession;
		wxTimeSpan ellapsedTime;
		wxTimeSpan paused_time;

		wxFont font;
		wxWindow* m_parent;

		std::ifstream file;

		int SessionsNum;
		int SessionTime;
		int ShortBreakTime;
		int LongBreakTime;
		int PomodoroCount;
	public:

		Notification* msg;

		Timer(wxWindow* parent, wxWindowID id, const wxString& label);

		void SetupFont();
		void UpdateDisplayedTime();
		void SetTimerLabel();
		void StartTimer(wxCommandEvent&);
		void StopTimer(wxCommandEvent&);
		void PauseTimer(wxCommandEvent&);
		void OnUpdateDisplayedTime(wxTimerEvent&);
		void SetSessionTime(int min) { SessionTime = min; }
		void SetSessionsNum(int num) { SessionsNum = num; }
		void SetShortBreakTime(int min) { ShortBreakTime = min; }
		void SetLongBreakTime(int min) { LongBreakTime = min; }
		void SetPomodoroCount(int num) { PomodoroCount = num; }
		void ChangeState(PomodoroState pomostate, int Time);
		void SetSettings(int sN, int sT, int sBT, int lBT, int pC = 0);
		void GetSettings(const char* name);

		int GetSessionTime() { return SessionTime; }
		int GetSessionsNum() { return SessionsNum; }
		int GetShortBreakTime() { return ShortBreakTime; }
		int GetLongBreakTime() { return LongBreakTime; }
		int GetPomodoroCount() { return PomodoroCount; }
		bool IsTimerPaused();
		wxTimer& getTimer() { return m_Timer; }
		std::string SessionTimeToStr(int min);
};

#endif
