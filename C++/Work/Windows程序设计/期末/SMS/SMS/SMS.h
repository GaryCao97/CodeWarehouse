
// SMS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Merch.h"
#include "Staff.h"


// CSMSApp: 
// �йش����ʵ�֣������ SMS.cpp
//

class CSMSApp : public CWinApp
{
public:
	CSMSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSMSApp theApp;
extern CStaff StaffSet;
extern CMerch MerchSet;
extern CString m_strPost;
extern CString m_strDuty;
extern CString m_strUsername;
extern CString m_strForms;
extern CStringArray* m_saDuty;
extern CStringArray* m_saForms;
extern int m_iStaffPos;
extern int m_iMerchPos;
CStringArray* DivideString(CString Source, CString Separator);
bool isItInString(CString Duty, CString NameOrKind);
