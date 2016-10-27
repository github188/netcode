//:Ignore
// XTSortClass.h interface for the CXTSortClass  class.
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

#if !defined(__XTSORTCLASS_H__)
#define __XTSORTCLASS_H__

//:Ignore
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//:End Ignore

//////////////////////////////////////////////////////////////////////
// XT_DATA_TYPE - Enumeration used by CXTSortClass for specifying what
// type of sorting to perform.
//
typedef enum XT_DATA_TYPE
{
	// Sort type int.
	DT_INT = 1,
	// Sort type string.
	DT_STRING,
	// Sort type date / time.
	DT_DATETIME,
	// Sort type decimal.
	DT_DEC	
};

//////////////////////////////////////////////////////////////////////
// CXTSortClass is a stand alone class.  This class will sort a list control
// by a column of text, integer, float or date/time type.  It could be
// easily extended for other data types.  To use this class, instantiate
// a CXTSortClass object, passing in a pointer to the list control as
// the first argument and the column index as the second argument.
//
// Example:
//
//[pre]CXTSortClass sortClass(pListCtrl, 0);[/pre]
//
// Then call the sort method setting ascending as the first argument either
// TRUE or FALSE, and the type of sort to perform in the second argument.
//
// Example:
//
//[pre]sortClass.Sort(TRUE, DT_STRING);[/pre]
//
class _XT_EXT_CLASS CXTSortClass
{

public:
	
    // Constructs a CXTSortClass object.
    //
	CXTSortClass(
        // Pointer to a CListCtrl object.
        CListCtrl* pListCtrl,
        // Index of the column to be sorted.
        const int nCol);

	// Destroys a CXTSortClass object, handles cleanup and de-allocation.
    //
    virtual ~CXTSortClass();

protected:

	// Pointer to the CListCtrl object to perform the sort on.
	CListCtrl* m_pListCtrl;

public:

	// This member function is called to perform the actual sort procedure.
    //
	virtual void Sort(
        // 'true' to sort ascending.
        bool bAsc,
        // The type of sort to perform can be one of the following:
        //[ul]
        //[li][b]DT_INT[/b] - Sort type int.[/li]
        //[li][b]DT_STRING[/b] - Sort type string.[/li]
        //[li][b]DT_DATETIME[/b] - Sort type date / time.[/li]
        //[li][b]DT_DEC[/b] - Sort type decimal.[/li]
        //[/ul]
        XT_DATA_TYPE eType);

protected:

	// This callback member function is called to compare two data items during
	// sorting operations.  The comparison function must return a negative
	// value if the first item should precede the second, and a positive value
	// if the first item should follow the second, or zero if the two items
	// are equivalent.
    //
	static int CALLBACK Compare(
        // Specify the item data for the two items being compared.
        LPARAM lParam1,
        // Specify the item data for the two items being compared.
        LPARAM lParam2,
        // Specifies the application defined value that is passed to the
		// comparison function.
        LPARAM lParamSort);
};

//////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // #if !defined(__XTSORTCLASS_H__)
