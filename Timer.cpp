#include "Timer.h"


Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
	state = INIT;	pomodorostate = POMODORO;
	SetupFont();
	PomodoroCount = 0;
	SetSessionTime(1);
	ShortBreakTime = 2;
	LongBreakTime = 3;
	SessionsNum = 2;
	UpdateDisplayedTime();
	m_Timer.Bind(wxEVT_TIMER, &Timer::OnUpdateDisplayedTime, this);
}

void Timer::StartTimer(wxCommandEvent&)
{
	StartTime = wxDateTime::Now();
	m_Timer.Start(1000);
	UpdateDisplayedTime();
}

void Timer::StopTimer(wxCommandEvent&)
{
	m_Timer.Stop();
	state = STOPPED;
	UpdateDisplayedTime();
}

void Timer::PauseTimer(wxCommandEvent&)
{
	m_Timer.Stop();
	state = PAUSED;
	paused_time = ellapsedTime;
}

void Timer::OnUpdateDisplayedTime(wxTimerEvent&)
{
	UpdateDisplayedTime();
}

void Timer::UpdateDisplayedTime()
{
	if (m_Timer.IsRunning())
	{
		currentTime = wxDateTime::Now();
		if (state == INIT || state == STOPPED)
		{
			pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
			if (pomodorostate == SHORT_BREAK)
				pomodoroSession = wxTimeSpan::Minutes(ShortBreakTime);
			if (pomodorostate == POMODORO)
				pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
			if (pomodorostate == LONG_BREAK)
				pomodoroSession = wxTimeSpan::Minutes(LongBreakTime);
		}
		else if (state == PAUSED)
			pomodoroSession = paused_time;
		ellapsedTime = (((currentTime - StartTime) - pomodoroSession) * -1);
		if (ellapsedTime >= 0)
			this->SetLabel(ellapsedTime.Format("%M:%S"));
		else if (ellapsedTime < 0 && pomodorostate == POMODORO && PomodoroCount == (SessionsNum-1))
		{
			pomodorostate = LONG_BREAK;
			PomodoroCount = 0;
			m_Timer.Stop();
			state = STOPPED;
			pomodoroSession = wxTimeSpan::Minutes(LongBreakTime);
			this->SetLabel(SessionTimeToStr(LongBreakTime));
		}
		else if (ellapsedTime < 0 && pomodorostate == POMODORO)
		{
			pomodorostate = SHORT_BREAK;
			PomodoroCount++;
			m_Timer.Stop();
			state = STOPPED;
			pomodoroSession = wxTimeSpan::Minutes(ShortBreakTime);
			this->SetLabel(SessionTimeToStr(ShortBreakTime));
		}
		else if (ellapsedTime < 0 && pomodorostate == SHORT_BREAK)
		{
			pomodorostate = POMODORO;
			m_Timer.Stop();
			state = STOPPED;
			pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
			this->SetLabel(SessionTimeToStr(GetSessionTime()));
		}
		else if (ellapsedTime < 0 && pomodorostate == LONG_BREAK)
		{
			pomodorostate = POMODORO;
			m_Timer.Stop();
			state = STOPPED;
			pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
			this->SetLabel(SessionTimeToStr(GetSessionTime()));
		}
	}
	else if (pomodorostate == SHORT_BREAK)
	{
		this->SetLabel(SessionTimeToStr(ShortBreakTime));
	}
	else if (pomodorostate == POMODORO)
	{
		this->SetLabel(SessionTimeToStr(GetSessionTime()));
	}
	else if (pomodorostate == LONG_BREAK)
	{
		this->SetLabel(SessionTimeToStr(LongBreakTime));
	}
	else
	{
		this->SetLabel(SessionTimeToStr(GetSessionTime()));
	}
}

void Timer::SetupFont()
{
	font = this->GetFont();
	font.MakeBold().MakeLarger();
	this->SetFont(font);
}

std::string Timer::SessionTimeToStr(int min)
{
	std::string strlabel = std::to_string(min);
	if (min > 9)
		return strlabel += ":00";
	else
	{
		std::string str = "0";
		return str += strlabel + ":00";
	}
}