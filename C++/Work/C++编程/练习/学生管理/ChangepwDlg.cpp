// ChangepwDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "ChangepwDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CUserSet Set;
extern int m;

// CChangepwDlg 对话框

IMPLEMENT_DYNAMIC(CChangepwDlg, CDialogEx)

CChangepwDlg::CChangepwDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangepwDlg::IDD, pParent)
	, pw_old(_T(""))
	, pw_new1(_T(""))
	, pw_new2(_T(""))
{

}

CChangepwDlg::~CChangepwDlg()
{
}

void CChangepwDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_changepw_old, pw_old);
	DDX_Text(pDX, IDC_changepw_new1, pw_new1);
	DDX_Text(pDX, IDC_changepw_new2, pw_new2);
}


BEGIN_MESSAGE_MAP(CChangepwDlg, CDialogEx)
	ON_BN_CLICKED(IDC_changepw_Return, &CChangepwDlg::OnBnClickedchangepwReturn)
	ON_BN_CLICKED(IDC_changepw_Sure, &CChangepwDlg::OnBnClickedchangepwSure)
END_MESSAGE_MAP()


// CChangepwDlg 消息处理程序


void CChangepwDlg::OnBnClickedchangepwReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CChangepwDlg::OnCancel();
}


void CChangepwDlg::OnBnClickedchangepwSure()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	if(!Set.IsOpen())
	Set.Open();
	Set.Move(m);
	if((pw_old == (CString)Set.m_Password) && (pw_new1 == pw_new2))
	{
		Set.Edit();
		Set.m_Password = (CStringW)pw_new1;
		Set.Update();
	}
	else if(pw_old != Set.m_Password)
		MessageBox(_T("原密码错误！"),_T("系统提示"));
	else if(pw_new1 != pw_new2)
		MessageBox(_T("请输入正确的密码！"),_T("系统提示"));
	Set.Close();
	UpdateData(FALSE);
	CChangepwDlg::OnCancel();
}
