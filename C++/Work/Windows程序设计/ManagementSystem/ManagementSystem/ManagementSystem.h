
// ManagementSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "UserSet.h"
#include "CommSet.h"


// CMSApp: 
// �йش����ʵ�֣������ ManagementSystem.cpp
//

class CMSApp : public CWinApp
{
public:
	CMSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMSApp theApp;

CString GetYzm();//������֤��ĺ���
CStringArray* DivideString(CString Source, CString Separator);
bool isItInString(CString Duty, CString NameOrKind);
extern CUserSet UserSet;
extern CCommSet CommSet;