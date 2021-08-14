#include "Frame.h"

Frame::Frame(const wxString& title, int width, int height) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	Centre();
	SetIcon(wxIcon("data\\icon.ico", wxBITMAP_TYPE_ICO));
}
