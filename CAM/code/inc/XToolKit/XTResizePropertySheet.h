//:Ignore
// XTResizePropertySheet.h: interface for the CXTResizePropertySheet class.
//
// This file is a part of the Xtreme Toolkit for MFC.
// �1998-2003 Codejock Software, All Rights Reserved.
//
// This source code can only be used under the terms and conditions 
// outlined in the accompanying license agreement.
//
// support@codejock.com
// http://www.codejock.com
//--------------------------------------------------------------------
// Based on the resizable classes created by Torben B. Haagh. Used by permission.
// http://www.codeguru.com/dialog/torbenResizeDialog.shtml
//--------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////
//:End Ignore

#if !defined(__XTRESIZEPROPERTYSHEET_H__)
#define __XTRESIZEPROPERTYSHEET_H__

//:Ignore
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//:End Ignore

//////////////////////////////////////////////////////////////////////
// CXTResizePropertySheet is a multiple inheritance class derived from
// CPropertySheet and CXTResize.  CXTResizePropertySheet is used to create
// a resizable CPropertySheet type object that allows its dialog items
// to be resized or moved dynamically.
//
class _XT_EXT_CLASS CXTResizePropertySheet : public CPropertySheet, public CXTResize
{
	DECLARE_DYNCREATE(CXTResizePropertySheet);

public:

    // Constructs a CXTResizePropertySheet object.
    //
	CXTResizePropertySheet(
		// ID of the caption to be used for the property sheet.
        const UINT nCaption = 0,
		// Points to the parent window of the property sheet.  If NULL, the parent
		// window will be the main window of the application.
        CWnd* pParent = 0,
		// The index of the page that will initially be on top. Default is the
		// first page added to the sheet.
        const UINT nSelectPage = 0,
		// Flags that are to be passed to CXTResize that specify the attributes
		// of the resizing property page.  They can be one or more of the following,
		// and can be combined using the or (|) operator:
		//[ul]
        //[li][b]SZ_NOSIZEICON[/b] - Do not add size icon.[/li]
        //[li][b]SZ_NOHORISONTAL[/b] - No horizontal resizing.[/li]
        //[li][b]SZ_NOVERTICAL[/b] - No vertical resizing.[/li]
        //[li][b]SZ_NOMINSIZE[/b] - Do not require a minimum size.[/li]
        //[li][b]SZ_NOCLIPCHILDREN[/b] - Do not set clip children style.[/li]
        //[li][b]SZ_NOTRANSPARENTGROUP[/b] - Do not set transparent style
		//       for group boxes.[/li]
		//[/ul]
        const UINT nFlags = 0);
    
    // Constructs a CXTResizePropertySheet object.
    //
	CXTResizePropertySheet(
		// Points to a string containing the caption to be used for the property
		// sheet.  It [b]cannot[/b] be NULL.
        LPCTSTR pszCaption,
		// Points to the parent window of the property sheet. If NULL, the parent
		// window will be the main window of the application.
        CWnd* pParent = 0,
		// The index of the page that will initially be on top. The default is the
		// first page added to the sheet.
        const UINT nSelectPage = 0,
		// Flags that are to be passed to CXTResize that specify the attributes
		// of the resizing property page.  They can be one or more of the following,
		// and can be combined using the or (|) operator:
		//[ul]
        //[li][b]SZ_NOSIZEICON[/b] - Do not add size icon.[/li]
        //[li][b]SZ_NOHORISONTAL[/b] - No horizontal resizing.[/li]
        //[li][b]SZ_NOVERTICAL[/b] - No vertical resizing.[/li]
        //[li][b]SZ_NOMINSIZE[/b] - Do not require a minimum size.[/li]
        //[li][b]SZ_NOCLIPCHILDREN[/b] - Do not set clip children style.[/li]
        //[li][b]SZ_NOTRANSPARENTGROUP[/b] - Do not set transparent style
		//       for group boxes.[/li]
		//[/ul]
        const UINT nFlags = 0);

	//:Ignore
	CXTNoFlickerWnd <CTabCtrl> m_tabCtrl;
	//:End Ignore

protected:
	
	// This member function determines if the property sheet is in wizard mode.
	// Returns TRUE if the property sheet is a wizard, otherwise returns FALSE.
	//
	BOOL IsWizard();

//:Ignore
	//{{AFX_MSG(CXTResizePropertySheet)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO *lpMMI);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	afx_msg BOOL OnPageChanging(NMHDR* pNotifyStruct, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
//:End Ignore

	friend CXTResizePropertyPage;
};

//:Ignore
//////////////////////////////////////////////////////////////////////

AFX_INLINE BOOL CXTResizePropertySheet::IsWizard() {
	return (m_psh.dwFlags & PSH_WIZARD); 
}

//////////////////////////////////////////////////////////////////////
//:End Ignore

#endif // !defined(__XTRESIZEPROPERTYSHEET_H__)
