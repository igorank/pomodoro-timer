#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/datetime.h>

class Timer : public wxStaticText
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

#endif
