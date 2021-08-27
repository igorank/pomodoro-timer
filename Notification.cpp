#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>
#endif
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
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\break.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Take a short break"));
	Show();
}

void Notification::ShowPomodoroSessionEndLMsg()
{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\break.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Take a long break"));
	Show();
}

void Notification::StartFocusingMsg()
{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\pomodoro.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Time to work!"));
	Show();
}

void Notification::EndedPomodoroSessionMsg()
{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\done.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Pomodoro session has been ended"));
	Show();
}
