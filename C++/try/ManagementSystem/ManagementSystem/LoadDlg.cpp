// LoadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "LoadDlg.h"
#include "afxdialogex.h"


// CLoadDlg 对话框

IMPLEMENT_DYNAMIC(CLoadDlg, CDialogEx)

CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOAD, pParent)
	, m_sUsername(_T(""))
	, m_sPassword(_T(""))
{
	CheckDlgButton(IDC_NORMAL, 1);
	m_iType = 0;
}

CLoadDlg::~CLoadDlg()
{
}

void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NORMAL, &CLoadDlg::OnBnClickedNormal)
	ON_BN_CLICKED(IDC_ADMIN, &CLoadDlg::OnBnClickedAdmin)
	ON_BN_CLICKED(IDOK, &CLoadDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoadDlg 消息处理程序


void CLoadDlg::OnBnClickedNormal()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 0;
}


void CLoadDlg::OnBnClickedAdmin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 1;
}


void CLoadDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	if (m_iType == 1) {
		if (m_sUsername == _T("gary") && m_sPassword == _T("463129368")) {
			CDialogEx::OnOK();
		}
	}
	else {
		CDialogEx::OnOK();
	}
}
