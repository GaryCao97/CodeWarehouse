// Forget.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "Forget.h"
#include "afxdialogex.h"


// CForget 对话框

IMPLEMENT_DYNAMIC(CForget, CDialogEx)

CForget::CForget(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORGET, pParent)
	, m_sUsername(_T(""))
	, m_sPassword1(_T(""))
	, m_sPassword2(_T(""))
{

}

CForget::~CForget()
{
}

void CForget::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword1);
	DDX_Text(pDX, IDC_PASSWORD2, m_sPassword2);
}


BEGIN_MESSAGE_MAP(CForget, CDialogEx)
END_MESSAGE_MAP()


// CForget 消息处理程序
