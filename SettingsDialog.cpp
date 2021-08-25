#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(const wxString& title) :
	wxDialog(nullptr, 1, title, wxDefaultPosition, wxSize(350, 330))
{
	wxPanel* panel = new wxPanel(this, 1);

	Centre();
	ShowModal();

	Destroy();
}