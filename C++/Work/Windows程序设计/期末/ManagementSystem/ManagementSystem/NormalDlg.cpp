// NormalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "NormalDlg.h"
#include "UserMana.h"
#include "CommDlg.h"
#include "CommNum.h"
#include "afxdialogex.h"


// CNormalDlg 对话框

IMPLEMENT_DYNAMIC(CNormalDlg, CDialogEx)

CNormalDlg::CNormalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NORMAL_MAIN, pParent)
	, m_sUser(_T(""))
	, m_iUserPos(0)
{

	m_sUserNumber = _T("");
	m_sUserKind = _T("");
}

CNormalDlg::~CNormalDlg()
{
}

void CNormalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_USER, m_sUser);
}


BEGIN_MESSAGE_MAP(CNormalDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_USER, &CNormalDlg::OnBnClickedBtnUser)
	ON_BN_CLICKED(IDC_BTN_COMM, &CNormalDlg::OnBnClickedBtnComm)
	ON_BN_CLICKED(IDC_BTN_NUM, &CNormalDlg::OnBnClickedBtnNum)
END_MESSAGE_MAP()


// CNormalDlg 消息处理程序


BOOL CNormalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int pos = 0;
	m_sUserNumber = m_sUser.Tokenize(_T("："), pos);
	m_sUserKind = m_sUser.Tokenize(_T("："), pos);
	//if (m_sUserKind == _T("员工")) {
	//	GetDlgItem(IDC_BTN_KIND)->EnableWindow(FALSE);
	//	GetDlgItem(IDC_BTN_IN)->EnableWindow(FALSE);
	//	GetDlgItem(IDC_BTN_OUT)->EnableWindow(FALSE);
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CNormalDlg::OnBnClickedBtnUser()
{
	// TODO: 在此添加控件通知处理程序代码
	CUserMana UserManage;
	UserManage.m_sUser = m_sUserNumber;
	UserManage.DoModal();
}


void CNormalDlg::OnBnClickedBtnComm()
{
	// TODO: 在此添加控件通知处理程序代码
	CCommDlg CommDlg;
	CommDlg.m_sUserKind = m_sUserKind;
	CommDlg.m_iUserPos = m_iUserPos;
	CommDlg.DoModal();
}


void CNormalDlg::OnBnClickedBtnNum()
{
	// TODO: 在此添加控件通知处理程序代码
	CCommNum NumDlg;
	NumDlg.m_sUserKind = m_sUserKind;
	NumDlg.m_iUserPos = m_iUserPos;
	NumDlg.DoModal();
}
