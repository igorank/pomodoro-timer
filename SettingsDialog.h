#ifndef SETTINGSDIALOG_H_INCLUDED
#define SETTINGSDIALOG_H_INCLUDED

#include <wx/wxprec.h>
	#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/spinctrl.h>


class SettingsDialog : public wxDialog
{
	public:
		SettingsDialog(const wxString& title);
};

#endif