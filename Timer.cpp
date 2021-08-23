#include "Timer.h"


Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
	timerstate = INIT;	
	pomodorostate = POMODORO;
	SetupFont();
	SetSettings(2, 1, 2, 3);
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
	timerstate = STOPPED;
	UpdateDisplayedTime();
}

void Timer::PauseTimer(wxCommandEvent&)
{
	m_Timer.Stop();
	timerstate = PAUSED;
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
		if (timerstate == INIT || timerstate == STOPPED)
		{
			switch (pomodorostate)
			{
			case POMODORO:
				pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
				break;
			case SHORT_BREAK:
				pomodoroSession = wxTimeSpan::Minutes(GetShortBreakTime());
				break;
			case LONG_BREAK:
				pomodoroSession = wxTimeSpan::Minutes(GetLongBreakTime());
				break;
			default:
				pomodoroSession = wxTimeSpan::Minutes(GetSessionTime());
				break;
			}
		}
		else if (timerstate == PAUSED)
			pomodoroSession = paused_time;
		ellapsedTime = (((currentTime - StartTime) - pomodoroSession) * -1);
		if (ellapsedTime >= 0)
			this->SetLabel(ellapsedTime.Format("%M:%S"));
		else 
		{
			switch (pomodorostate)
			{
			case Timer::POMODORO:
			{
				if (PomodoroCount == (GetSessionsNum() - 1))
				{
					PomodoroCount = 0;
					ChangeState(LONG_BREAK, GetLongBreakTime());
				}
				else
				{
					PomodoroCount++;
					ChangeState(SHORT_BREAK, GetShortBreakTime());
				}
			}
				break;
			case Timer::SHORT_BREAK:
			{
				ChangeState(POMODORO, GetSessionTime());
			}
				break;
			case Timer::LONG_BREAK:
			{
				ChangeState(POMODORO, GetSessionTime());
			}
				break;
			default:
				break;
			}
		}
	}
	else 
	{
		switch (pomodorostate)
		{
		case Timer::POMODORO:
			this->SetLabel(SessionTimeToStr(GetSessionTime()));
			break;
		case Timer::SHORT_BREAK:
			this->SetLabel(SessionTimeToStr(GetShortBreakTime()));
			break;
		case Timer::LONG_BREAK:
			this->SetLabel(SessionTimeToStr(GetLongBreakTime()));
			break;
		default:
			this->SetLabel(SessionTimeToStr(GetSessionTime()));
			break;
		}
	}
}

void Timer::SetupFont()
{
	font = this->GetFont();
	font.MakeBold().MakeLarger();
	this->SetFont(font);
}

void Timer::ChangeState(PomodoroState pomostate, int Time)
{
	pomodorostate = pomostate;
	m_Timer.Stop();
	timerstate = STOPPED;
	pomodoroSession = wxTimeSpan::Minutes(Time);
	this->SetLabel(SessionTimeToStr(Time));
}

void Timer::SetSettings(int sN, int sT, int sBT, int lBT, int pC)
{
	SetSessionsNum(sN);
	SetSessionTime(sT);
	SetShortBreakTime(sBT);
	SetLongBreakTime(lBT);
	SetPomodoroCount(pC);
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