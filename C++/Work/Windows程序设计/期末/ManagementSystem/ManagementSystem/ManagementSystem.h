
// ManagementSystem.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "UserSet.h"
#include "CommSet.h"


// CMSApp: 
// 有关此类的实现，请参阅 ManagementSystem.cpp
//

class CMSApp : public CWinApp
{
public:
	CMSApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMSApp theApp;

CString GetYzm();//生成验证码的函数
CStringArray* DivideString(CString Source, CString Separator);
bool isItInString(CString Duty, CString NameOrKind);
extern CUserSet UserSet;
extern CCommSet CommSet;