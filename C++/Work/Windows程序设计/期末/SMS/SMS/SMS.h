
// SMS.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "Merch.h"
#include "Staff.h"


// CSMSApp: 
// 有关此类的实现，请参阅 SMS.cpp
//

class CSMSApp : public CWinApp
{
public:
	CSMSApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

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
