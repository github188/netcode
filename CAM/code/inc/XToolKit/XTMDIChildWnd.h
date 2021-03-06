//:Ignore
// XTMDIChildWnd.h interface for the CXTMDIChildWnd class.
//
// This file is a part of the Xtreme Toolkit for MFC.
// ?998-2003 Codejock Software, All Rights Reserved.
//
// This source code can only be used under the terms and conditions 
// outlined in the accompanying license agreement.
//
// support@codejock.com
// http://www.codejock.com
//
//////////////////////////////////////////////////////////////////////
//:End Ignore
#include "BCGPMDIChildWnd.h"
#if !defined(__XTMDICHILDWND_H__)
#define __XTMDICHILDWND_H__

//:Ignore
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//:End Ignore


//////////////////////////////////////////////////////////////////////
// CXTMDIChildWnd is a multiple inheritance class derived from CMDIChildWnd
// and CXTFrameImpl. CXTMDIChildWnd extends the standard CMDIChildWnd class
// to allow CXTDockWindow and CXTToolBar docking, customization, and cool
// menu support.
//
class _XT_EXT_CLASS CXTMDIChildWnd : public CBCGPMDIChildWnd, public CXTFrameImpl
{
	DECLARE_DYNCREATE(CXTMDIChildWnd)

public:

    // Constructs a CXTMDIChildWnd object.
    //
	CXTMDIChildWnd();

	// Destroys a CXTMDIChildWnd object, handles cleanup and de-allocation.
    //
    virtual ~CXTMDIChildWnd();

    // This member function is called by the frame window to restore the
	// settings of the control bar.
    //
    virtual void LoadBarState(
        // Name of a section in the initialization file or a key in the
		// Windows registry where state information is stored.
        LPCTSTR lpszProfileName);

    // This member function is called by the frame window to save the settings
	// of the control bar.
    //
    virtual void SaveBarState(
        // Name of a section in the initialization file or a key in the
		// Windows registry where state information is stored.
        LPCTSTR lpszProfileName) const;

    // Call this function to enable a control bar to be docked.  The sides
	// specified must match one of the sides enabled for docking in the destination
	// frame window, or the control bar cannot be docked to that frame window.
    //
    void EnableDocking(
        // Specifies whether the control bar supports docking and the sides
		// of its parent window to which the control bar can be docked, if supported.
        // The style can be one or more of the following: 
        //[ul]
        //[li][b]CBRS_ALIGN_TOP[/b] - Allows docking at the top of the
		//       client area.[/li]
        //[li][b]CBRS_ALIGN_BOTTOM[/b] - Allows docking at the bottom of
		//       the client area.[/li]
        //[li][b]CBRS_ALIGN_LEFT[/b] - Allows docking on the left side
		//       of the client area.[/li]
        //[li][b]CBRS_ALIGN_RIGHT[/b] - Allows docking on the right side
		//       of the client area.[/li]
        //[li][b]CBRS_ALIGN_ANY[/b] - Allows docking on any side of the
		//       client area.[/li]
        //[li][b]CBRS_FLOAT_MULTI[/b] - Allows multiple control bars to
		//       be floated in a single mini-frame window.[/li]
        //[/ul]
        // If 0 (that is, indicating no flags), the control bar will not
		// dock.
        DWORD dwDockStyle);

    // Call this function to enable a control bar to be docked. The sides
	// specified must match one of the sides enabled for docking in the destination
	// frame window, or the control bar cannot be docked to that frame window.
    //
    void EnableDockingEx(
        // Specifies whether the control bar supports docking and the sides
		// of its parent window to which the control bar can be docked, if supported.
        // The style can be one or more of the following: 
        //[ul]
        //[li][b]CBRS_ALIGN_TOP[/b] - Allows docking at the top of the
		//       client area.[/li]
        //[li][b]CBRS_ALIGN_BOTTOM[/b] - Allows docking at the bottom of
		//       the client area.[/li]
        //[li][b]CBRS_ALIGN_LEFT[/b] - Allows docking on the left side
		//       of the client area.[/li]
        //[li][b]CBRS_ALIGN_RIGHT[/b] - Allows docking on the right side
		//       of the client area.[/li]
        //[li][b]CBRS_ALIGN_ANY[/b] - Allows docking on any side of the
		//       client area.[/li]
        //[li][b]CBRS_FLOAT_MULTI[/b] - Allows multiple control bars to
		//       be floated in a single mini-frame window.[/li]
        //[/ul]
        // If 0 (that is, indicating no flags), the control bar will not
		// dock.
        DWORD dwDockStyle,
        // Specifies the splitters, inside dockbars, look.
        // It can be one of the following: 
        //[ul]
        //[li][b]CBRS_XT_NONFLAT[/b] - Thick devstudio like non-flat splitters.[/li]
        //[li][b]CBRS_XT_SEMIFLAT[/b] - Thin 3D non-flat splitters.[/li]
        //[li][b]CBRS_XT_FLAT[/b] - Flat splitters.[/li]
        //[/ul]
        DWORD dwFlatStyle);

    // This member function causes a control bar to be docked to the frame
	// window.  The control bar will be docked to one of the sides of the
	// frame window specified in the calls to both CXTDockWindow::EnableDocking
	// and CXTFrameWnd::EnableDocking.  The side chosen is determined by the
	// dockbar specified by 'pDockBar'.
    //
    void DockControlBar(
        // Points to the control bar to be docked.
        CControlBar* pBar,
        // Points to the dockbar the control bar is docked to.
        CDockBar* pDockBar,
        // Determines, in screen coordinates, where the control bar will
		// be docked in the non-client area of the destination frame window.
        LPCRECT lpRect = NULL);

    // This member function causes a control bar to be docked to the frame
	// window.  The control bar will be docked to one of the sides of the
	// frame window specified in the calls to both CXTDockWindow::EnableDocking
	// and CXTFrameWnd::EnableDocking.  The side chosen is determined by 
    // 'nDockBarID'.
    //
    void DockControlBar(
        // Points to the control bar to be docked.
        CControlBar* pBar,
        // Determines which sides of the frame window to consider for docking.
		// It can be 0, or one or more of the following: 
        //[ul]
        //[li][b]AFX_IDW_DOCKBAR_TOP[/b] - Dock to the top side of the
		//       frame window.[/li]
        //[li][b]AFX_IDW_DOCKBAR_BOTTOM[/b] - Dock to the bottom side of
		//       the frame window.[/li]
        //[li][b]AFX_IDW_DOCKBAR_LEFT[/b] - Dock to the left side of the
		//       frame window.[/li]
        //[li][b]AFX_IDW_DOCKBAR_RIGHT[/b] - Dock to the right side of
		//       the frame window.[/li]
        //[/ul]
        // If 0, the control bar can be docked to any side enabled for
		// docking in the destination frame window.
        UINT nDockBarID = 0,
        // Determines, in screen coordinates, where the control bar will
		// be docked in the non-client area of the destination frame window.
        LPCRECT lpRect = NULL);

    // This member function will redock a control bar specified by 'pBar2'
	// to the left of a newly docked control bar specified by 'pBar1'. 
    //
    virtual void DockControlBarLeftOf(
        // A CControlBar pointer to the control bar to be docked.
        CControlBar* pBar1,
        // A CControlBar pointer to the already docked control bar to be
		// redocked on the left of 'pBar1'.
        CControlBar* pBar2);

    // Call this function to display the Customize Toolbar dialog box.
	// This dialog box allows the user to customize the toolbar by adding
	// and deleting buttons.
    //
	void Customize();

protected:

    // Cool menu hook.
	CXTCoolMenu m_hookCoolMenus; 

	//:Ignore
    //{{AFX_VIRTUAL(CXTMDIChildWnd)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs, UINT uIcon);
    virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	//}}AFX_VIRTUAL
    //:End Ignore

	//:Ignore
    //{{AFX_MSG(CXTMDIChildWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg void OnCustomizeBar();
	afx_msg void OnUpdateChevron(CCmdUI* pCmdUI);
    //:End Ignore

	DECLARE_MESSAGE_MAP()

	friend class CXTMDIFrameWnd;
};

//:Ignore
//////////////////////////////////////////////////////////////////////

AFX_INLINE void CXTMDIChildWnd::Customize() {
	OnCustomizeBar();
}

//////////////////////////////////////////////////////////////////////
//:End Ignore

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // #if !defined(__XTMDICHILDWND_H__)
