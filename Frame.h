#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "StartButton.h"
#include "StopButton.h"
#include "PauseButton.h"
#include "Timer.h"
#include "SettingsDialog.h"

const int windowWidth = 400;
const int windowHeight = 400;

class Frame : public wxFrame
{
    private:
        wxDECLARE_EVENT_TABLE();

        void OnSettings(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
    public:
        wxPanel* parent;
        StartButton* startbutton;
        StopButton* stopbutton;
        PauseButton* pausebutton;
        SettingsDialog* settingsdlg;
        Timer* timer;

        Frame(const wxString& title, int width, int height);
};

#endif
