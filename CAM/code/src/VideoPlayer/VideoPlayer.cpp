// VideoPlayer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VideoPlayer.h"
#include "VideoPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoPlayerApp

BEGIN_MESSAGE_MAP(CVideoPlayerApp, CWinApp)
	//{{AFX_MSG_MAP(CVideoPlayerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoPlayerApp construction

CVideoPlayerApp::CVideoPlayerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVideoPlayerApp object

CVideoPlayerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVideoPlayerApp initialization

BOOL CVideoPlayerApp::InitInstance()
{
	::CreateMutex(NULL, TRUE, m_pszExeName);
	if (GetLastError()==ERROR_ALREADY_EXISTS)
	{
		CWnd *pPrevWnd=CWnd::GetDesktopWindow()->GetWindow(GW_CHILD);
		while(pPrevWnd)
		{
			if (::GetProp(pPrevWnd->GetSafeHwnd(), m_pszExeName))
			{
				pPrevWnd->SetForegroundWindow();
				pPrevWnd->ShowWindow(SW_SHOWNORMAL);
				pPrevWnd->UpdateWindow();
				return FALSE;
			}
			pPrevWnd = pPrevWnd->GetWindow(GW_HWNDNEXT);
		}
		TRACE("Could not find previous instance main window!\n");
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CVideoPlayerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
