#ifndef NOTIFICATION_H_INCLUDED
#define NOTIFICATION_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <fstream>
#include <wx/notifmsg.h>

class Notification : public wxNotificationMessage
{
	private:
		std::ifstream file;
		bool ShowNotifi;
	public:
		Notification(wxWindow* parent);
		Notification(const char* title, const char* message, wxWindow* parent = NULL);
		
		void ShowPomodoroSessionEndSMsg();
		void ShowPomodoroSessionEndLMsg();
		void EndedPomodoroSessionMsg();
		void StartFocusingMsg();
		void ReadSettings();

		bool& GetShowNotifi() { return ShowNotifi; }
};

#endif

