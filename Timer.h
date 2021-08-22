#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/datetime.h>

class Timer : public wxStaticText
{
	private:
		enum STATE { INIT, PAUSED, STOPPED};
		STATE state;

		wxTimer m_Timer;
		wxDateTime StartTime;
		wxDateTime currentTime;

		wxTimeSpan pomodoroSession;
		wxTimeSpan ellapsedTime;
		wxTimeSpan paused_time;

		wxFont font;

		int SessionTime;
		int ShortBreaksNum;
		int ShortBreakTime;
		bool IsSessionDone;
	public:
		Timer(wxWindow* parent, wxWindowID id, const wxString& label);

		void StartTimer(wxCommandEvent&);
		void StopTimer(wxCommandEvent&);
		void PauseTimer(wxCommandEvent&);
		void OnUpdateDisplayedTime(wxTimerEvent&);
		void UpdateDisplayedTime();
		void SetSessionTime(int min) { SessionTime = min; }
		void SetupFont();

		int GetSessionTime() { return SessionTime; }
		wxTimer& getTimer() { return m_Timer; }
		std::string SessionTimeToStr(int min);
};

#endif
