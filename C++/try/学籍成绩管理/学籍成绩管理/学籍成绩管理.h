
// ѧ���ɼ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cѧ���ɼ�����App:
// �йش����ʵ�֣������ ѧ���ɼ�����.cpp
//

class Cѧ���ɼ�����App : public CWinApp
{
public:
	Cѧ���ɼ�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cѧ���ɼ�����App theApp;