
// KeyMouse.h : KeyMouse Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CKeyMouseApp:
// �йش����ʵ�֣������ KeyMouse.cpp
//

class CKeyMouseApp : public CWinApp
{
public:
	CKeyMouseApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKeyMouseApp theApp;
