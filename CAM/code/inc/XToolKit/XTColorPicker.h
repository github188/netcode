//:Ignore
// XTColorPicker.h : interface for the CXTColorPicker class.
//
// This file is a part of the Xtreme Toolkit for MFC.
// �1998-2003 Codejock Software, All Rights Reserved.
//
// This source code can only be used under the terms and conditions 
// outlined in the accompanying license agreement.
//
// support@codejock.com
// http://www.codejock.com
//
//////////////////////////////////////////////////////////////////////
//:End Ignore

#if !defined(__XTCOLORPICKER_H__)
#define __XTCOLORPICKER_H__

//:Ignore
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//:End Ignore

// class forwards
class CXTColorPopup;

//////////////////////////////////////////////////////////////////////
// CXTColorPicker is a CButton derived class.  It displays a color picker
// popup window (CXTColorPopup) for Office&trade; style color selection.
//
class _XT_EXT_CLASS CXTColorPicker : public CButton
{
    DECLARE_DYNAMIC(CXTColorPicker)

public:
    
    // Constructs a CXTColorPicker object.
    //
    CXTColorPicker();

    // Destroys a CXTColorPicker object, handles cleanup and de-allocation.
    //
    virtual ~CXTColorPicker();

protected:

    // Represents the style for the color picker.
	DWORD m_dwPopup;
    // An RGB value that represents the color for the display color.
	COLORREF m_clrSelected;
	// An RGB value that represents the color for the default color.
	COLORREF m_clrDefault;
	// TRUE if the color picker displays text.
	BOOL m_bShowText;
	// TRUE if the color picker text is colorized, only valid if m_bShowText is TRUE.
	BOOL m_bColorText;
	// TRUE if the popup window is currently active.
	BOOL m_bPopupActive;
	// 'true' for initialization.
	bool m_bInitControl;

public:

    //  This member function will set the color value for the color picker.
    //
    virtual void SetColor(
		// An RGB value that represents the new RGB color for the control.
        COLORREF clr);

    // This member function will return the currently selected color. Returns
	// an RGB color value that represents the currently selected color.
    //
    virtual COLORREF GetColor() const;

    // This member function will display any text associated with the color picker
	// button control.  If the button has text, then it will be displayed..
    //
    virtual void ShowText(
		// TRUE to display button text.
        BOOL bShowText);

    // This member function will determine if text is displayed for the color picker
	// button control. Returns TRUE if the color picker displays text, otherwise 
	// returns FALSE.
    //
    virtual BOOL IsTextShown() const;

	// This member function will display any text associated with the color picker
	// button control in color.
	//
	virtual void ShowTextInColor(
		// TRUE to display the button text in color.
		BOOL bColorText);

	// This member function will determine if the text for the color picker button
	// control is displayed in color.  Returns TRUE if the button text is in color;
	// otherwise returns FALSE.
	//
	virtual BOOL IsTextInColor() const;

    // This member function will set the default RGB color value for the
    // color picker.
    //
    virtual void SetDefaultColor(
		// An RGB value that represents the default color for the color picker.
        COLORREF clrDefault);

    // This member function will return the default RGB color value for
	// the color picker. Returns an RGB value that represents the default
	// color value for the color picker.
	//
    virtual COLORREF GetDefaultColor() const;

    // Call this member function to modify the color picker style.  Styles 
    // to be added or removed can be combined by using the bitwise OR (|) 
    // operator. It can be one or more of the following:
    //[ul]
    //[li][b]CPS_XT_NOFILL[/b] - The color picker will display a No Fill
	//       button rather than the default Automatic Color button.[/li]
    //[li][b]CPS_XT_EXTENDED[/b] - The color picker will display 40 extended
	//       colors rather than the default 16 colors.[/li]
    //[li][b]CPS_XT_MORECOLORS[/b] - The color picker will display a More
	//       Colors button which will display a CXTColorDialog.[/li]
    //[li][b]CPS_XT_SHOW3DSELECTION[/b] - Displays the color selection
	//       box with a 3D raised border in CXTColorDialog.[/li]
    //[li][b]CPS_XT_SHOWHEXVALUE[/b] - Displays the hex equivalent of the
	//       selected color.[/li]
    //[/ul]
    virtual void ModifyCPStyle(
		// Specifies the window styles to be removed during style 
        // modification.
        DWORD dwRemove,
		// Specifies the window styles to be added during style 
        // modification.
        DWORD dwAdd);

    // This member function will activate the color picker and display the 
    // color popup window.
    //
    virtual void ShowPopupWindow();

protected:

	// This member function is called to return the contrast color for the color picker
	// button.  The contrast color is used when text is displayed to contrast with the
	// currently selected color.  For example, if the currently selected color is WHITE then
	// BLACK would be returned so the text is legible.  Returns an RGB value either BLACK or WHITE.
	//
	virtual COLORREF GetContrastColor() const;

    //:Ignore
    //{{AFX_VIRTUAL(CXTColorPicker)
    public:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    protected:
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL
    //:End Ignore

protected:
    //:Ignore
    //{{AFX_MSG(CXTColorPicker)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    //}}AFX_MSG
    afx_msg LRESULT OnSelChange(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropDown(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnCloseUp(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnSelEndOK(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnSelEndCancel(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnSelNoFill(WPARAM wParam, LPARAM lParam);
    afx_msg void OnShowPopup();
	afx_msg LRESULT OnInitControl(WPARAM wParam, LPARAM lParam);
    //:End Ignore

    DECLARE_MESSAGE_MAP()
};

//:Ignore
//////////////////////////////////////////////////////////////////////

AFX_INLINE COLORREF CXTColorPicker::GetColor() const {
    return m_clrSelected;
}
AFX_INLINE void CXTColorPicker::ShowText(BOOL bShowText) {
    m_bShowText = bShowText; RedrawWindow();
}
AFX_INLINE BOOL CXTColorPicker::IsTextShown() const {
    return m_bShowText;
}
AFX_INLINE void CXTColorPicker::ShowTextInColor(BOOL bColorText) {
	m_bColorText = bColorText; RedrawWindow();
}
AFX_INLINE BOOL CXTColorPicker::IsTextInColor() const {
	return m_bColorText;
}
AFX_INLINE void CXTColorPicker::SetDefaultColor(COLORREF clrDefault) {
    m_clrDefault = clrDefault; RedrawWindow();
}
AFX_INLINE COLORREF CXTColorPicker::GetDefaultColor() const {
    return m_clrDefault;
}
AFX_INLINE void CXTColorPicker::ModifyCPStyle(DWORD dwRemove, DWORD dwAdd) {
    m_dwPopup &= ~dwRemove; m_dwPopup |= dwAdd; RedrawWindow();
}

//////////////////////////////////////////////////////////////////////
//:End Ignore

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // #if !defined(__XTCOLORPICKER_H__)
