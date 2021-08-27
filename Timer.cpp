#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>
#endif
#include "Timer.h"
#include "Frame.h"

Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
	m_parent = parent;
	msg = new Notification(parent);
	//std::unique_ptr<Notification> msg(new Notification(parent));
	timerstate = INIT; pomodorostate = POMODORO;
	SetupFont();
	//SetSettings(2, 1, 2, 3);
	GetSettings("data\\config.cfg");
	UpdateDisplayedTime();
	m_Timer.Bind(wxEVT_TIMER, &Timer::OnUpdateDisplayedTime, this);
}

Timer::~Timer()
{
	delete msg;
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
					msg->ShowPomodoroSessionEndLMsg();
					ChangeState(LONG_BREAK, GetLongBreakTime());
				}
				else
				{
					PomodoroCount++;
					msg->ShowPomodoroSessionEndSMsg();
					ChangeState(SHORT_BREAK, GetShortBreakTime());
				}
			}
				break;
			case Timer::SHORT_BREAK:
			{
				msg->StartFocusingMsg();
				ChangeState(POMODORO, GetSessionTime());
			}
				break;
			case Timer::LONG_BREAK:
			{
				msg->EndedPomodoroSessionMsg();
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
		SetTimerLabel();
	}
}

void Timer::SetTimerLabel()
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

void Timer::SetupFont()
{
	font = this->GetFont();
	font.MakeBold().MakeLarger();
	font.Scale(2.2);
	this->SetFont(font);
}

void Timer::ChangeState(PomodoroState pomostate, int Time)
{
	pomodorostate = pomostate;
	m_Timer.Stop();
	timerstate = STOPPED;
	Frame* frame = (Frame*)m_parent->GetParent();
	frame->startbutton->SetLabel("Start");
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

void Timer::GetSettings(const char* name)
{
	file.open(name);
	file >> SessionTime;
	file >> ShortBreakTime;
	file >> LongBreakTime;
	file >> SessionsNum;
	file.close();
	
}

bool Timer::IsTimerPaused()
{
	if (timerstate == PAUSED)
		return true;
	else
		return false;
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