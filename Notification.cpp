#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>
#endif
#include "Notification.h"

Notification::Notification(wxWindow* parent) : wxNotificationMessage(wxString("Pomodoro"), wxEmptyString, parent)
{
	this->SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));
	ReadSettings();
}

Notification::Notification(const char* title, const char* message, wxWindow* parent) : 
	wxNotificationMessage(wxString(title), wxString(message), parent)
{
	this->SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));
}

void Notification::ShowPomodoroSessionEndSMsg()
{
	if (ShowNotifi)
	{
		//SetTitle(wxString("Pomodoro"));
		this->SetIcon(wxIcon("data\\break.ico", wxBITMAP_TYPE_ICO));
		SetMessage(wxString("Take a short break"));
		Show();
	}
}

void Notification::ShowPomodoroSessionEndLMsg()
{
	if (ShowNotifi)
	{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\break.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Take a long break"));
	Show();
	}
}

void Notification::StartFocusingMsg()
{
	if (ShowNotifi)
	{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\pomodoro.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Time to work!"));
	Show();
	}
}

void Notification::ReadSettings()
{
	int temp[4];
	file.open("data\\config.cfg");
	for (int i = 0; i < 4; i++)
		file >> temp[i];
	file >> ShowNotifi;
	file.close();
}

void Notification::EndedPomodoroSessionMsg()
{
	if (ShowNotifi)
	{
	//SetTitle(wxString("Pomodoro"));
	this->SetIcon(wxIcon("data\\done.ico", wxBITMAP_TYPE_ICO));
	SetMessage(wxString("Pomodoro session has been ended"));
	Show();
	}
}
