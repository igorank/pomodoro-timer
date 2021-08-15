#include <wx/wx.h>
#include <wx/datetime.h>

class Timer : wxStaticText
{
	public:
		Timer(wxWindow* parent, wxWindowID id, const wxString& label);

		wxTimer m_Timer;
		wxDateTime StartTime;

		void StartTimer(wxCommandEvent&);
		void StopTimer(wxCommandEvent&);
		void OnUpdateDisplayedTime(wxTimerEvent&);
		void UpdateDisplayedTime();
};

