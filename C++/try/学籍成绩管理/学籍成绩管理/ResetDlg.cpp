// ResetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "ResetDlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"
extern CUserSet Set;
extern int z;

// CResetDlg 对话框

IMPLEMENT_DYNAMIC(CResetDlg, CDialogEx)

CResetDlg::CResetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResetDlg::IDD, pParent)
	, reset_password1(_T(""))
	, reset_password2(_T(""))
	, reset_safea(_T(""))
	, reset_safeq(_T(""))
	, reset_username(_T(""))
	, reset_yzin(_T(""))
	, reset_yzout(_T(""))
{

}

CResetDlg::~CResetDlg()
{
}

void CResetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_reset_password1, reset_password1);
	DDX_Text(pDX, IDC_reset_password2, reset_password2);
	DDX_Text(pDX, IDC_reset_SafeA, reset_safea);
	DDX_Text(pDX, IDC_reset_SafeQ, reset_safeq);
	DDX_Text(pDX, IDC_reset_Username, reset_username);
	DDX_Text(pDX, IDC_reset_YzIn, reset_yzin);
	DDX_Text(pDX, IDC_reset_YzOut, reset_yzout);
}


BEGIN_MESSAGE_MAP(CResetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_reset_OK, &CResetDlg::OnBnClickedresetOk)
END_MESSAGE_MAP()


// CResetDlg 消息处理程序

BOOL CResetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	UpdateData(TRUE);
	CString yzm;
	int i = 1;
	while(i <= 5)
	{
		char x;
		do
		{
			x = rand() % 123;
		}while(x < 48 || (x > 57 && x < 65) || (x > 90 && x < 97) || x > 122);
		yzm = yzm + x;
		i++;
	}
	reset_yzout = yzm;
	if(!Set.IsOpen())
	Set.Open();
	Set.Move(z);
	reset_username = Set.m_Username;
	reset_safeq = Set.m_SafeQ;
	Set.Close();
	UpdateData(FALSE);

	return TRUE;
}

void CResetDlg::OnBnClickedresetOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(!Set.IsOpen())
	Set.Open();
	Set.Move(z);
	CString yzin = reset_yzin;
	CString yzout = reset_yzout;
	yzin.MakeLower();
	yzout.MakeLower();
	if((reset_password1 == reset_password2) && (reset_safeq == Set.m_SafeQ) && (reset_password1 != _T("")) && (yzin == yzout))
	{
		Set.Edit();
		Set.m_Password = reset_password1;
		Set.Update();
		Set.Close();
		CResetDlg::OnOK();
	}
	else
		MessageBox(_T("密码错误！"),_T("系统提示"));
	Set.Close();
	UpdateData(FALSE);
}


