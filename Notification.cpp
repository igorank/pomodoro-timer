#include "Notification.h"

Notification::Notification(wxWindow* parent) : wxNotificationMessage(wxString("Pomodoro"), wxEmptyString, parent)
{
	this->SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));
}

Notification::Notification(const char* title, const char* message, wxWindow* parent) : 
	wxNotificationMessage(wxString(title), wxString(message), parent)
{
	this->SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));
}

void Notification::ShowPomodoroSessionEndSMsg()
{
	SetTitle(wxString("Pomodoro"));
	SetMessage(wxString("Take a Short Break"));
	Show();
}

void Notification::ShowPomodoroSessionEndLMsg()
{
	SetTitle(wxString("Pomodoro"));
	SetMessage(wxString("Take a Long Break"));
	Show();
}

void Notification::StartFocusingMsg()
{
	SetTitle(wxString("Pomodoro"));
	SetMessage(wxString("Start Focusing"));
	Show();
}

void Notification::EndedPomodoroSessionMsg()
{
	SetTitle(wxString("Pomodoro"));
	SetMessage(wxString("Pomodoro session has been ended"));
	Show();
}