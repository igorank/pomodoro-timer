#include "Timer.h"


Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
	state = INIT;
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
	//UpdateDisplayedTime();
}

void Timer::OnUpdateDisplayedTime(wxTimerEvent&)
{
	state = RUNNING;
	UpdateDisplayedTime();
}

void Timer::UpdateDisplayedTime()
{
	if (m_Timer.IsRunning())
	{
		currentTime = wxDateTime::Now();
		if (state == INIT || state == STOPPED)
			pomodoroSession = wxTimeSpan::Minutes(25);
		else if (state == PAUSED)
			pomodoroSession = paused_time;
		//state == STOPPED || state == RUNNING ? pomodoroSession = wxTimeSpan::Minutes(25) : pomodoroSession = paused_time;
		//pomodoroSession = wxTimeSpan::Minutes(25);
		ellapsedTime = (((currentTime - StartTime) - pomodoroSession) * -1);

		this->SetLabel(ellapsedTime.Format("%M:%S"));
	}
	else 
	{
		this->SetLabel("25:00");
	}
}


