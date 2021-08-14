#include "Frame.h"

Frame::Frame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400))
{
  Centre();
}
