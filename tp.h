
// tp.h : main header file for the tp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CtpApp:
// See tp.cpp for the implementation of this class
//

class CtpApp : public CWinApp
{
public:
	CtpApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtpApp theApp;
