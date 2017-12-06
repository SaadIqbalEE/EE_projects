
// Echolon_solver.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CEcholon_solverApp:
// See Echolon_solver.cpp for the implementation of this class
//

class CEcholon_solverApp : public CWinApp
{
public:
	CEcholon_solverApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CEcholon_solverApp theApp;