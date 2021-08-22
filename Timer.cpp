#include "Timer.h"


Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
	state = INIT;
	SetupFont();
	SetStudySession(25);
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
			pomodoroSession = wxTimeSpan::Minutes(GetStudySession());
		else if (state == PAUSED)
			pomodoroSession = paused_time;
		ellapsedTime = (((currentTime - StartTime) - pomodoroSession) * -1);

		this->SetLabel(ellapsedTime.Format("%M:%S"));
	}
	else 
	{
		this->SetLabel(StudySessionToStr(GetStudySession()));
	}
}

void Timer::SetupFont()
{
	font = this->GetFont();
	font.MakeBold().MakeLarger();
	this->SetFont(font);
}

std::string Timer::StudySessionToStr(int min)
{
	std::string strlabel = std::to_string(min);
	return strlabel += ":00";
}
