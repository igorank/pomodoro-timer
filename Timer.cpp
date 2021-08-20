#include "Timer.h"

Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& label) : wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize,
	wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE)
{
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
	UpdateDisplayedTime();
}

void Timer::OnUpdateDisplayedTime(wxTimerEvent&)
{
	UpdateDisplayedTime();
}

void Timer::UpdateDisplayedTime()
{
	if (m_Timer.IsRunning())
	{
		const wxDateTime currentTime = wxDateTime::Now();
		const wxTimeSpan pomodoroSession = wxTimeSpan::Minutes(25);
		const wxTimeSpan ellapsedTime = (((currentTime - StartTime) - pomodoroSession) * -1);

		this->SetLabel(ellapsedTime.Format("%M:%S"));
	}
	else
	{
		this->SetLabel("25:00");
	}
}
