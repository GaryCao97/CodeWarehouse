// RegisterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CUserSet Set;

// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDlg::IDD, pParent)
	, register_password1(_T(""))
	, register_password2(_T(""))
	, register_safea(_T(""))
	, register_safeq(_T(""))
	, register_username(_T(""))
	, register_yzin(_T(""))
	, register_yzout(_T(""))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_register_password1, register_password1);
	DDX_Text(pDX, IDC_register_password2, register_password2);
	DDX_Text(pDX, IDC_register_SafeA, register_safea);
	DDX_Text(pDX, IDC_register_SafeQ, register_safeq);
	DDX_Text(pDX, IDC_register_Username, register_username);
	DDX_Text(pDX, IDC_register_YzIn, register_yzin);
	DDX_Text(pDX, IDC_register_YzOut, register_yzout);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_register_Register, &CRegisterDlg::OnBnClickedregisterRegister)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


BOOL CRegisterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	register_yzout = yzm;
	UpdateData(FALSE);
	return TRUE;
}


void CRegisterDlg::OnBnClickedregisterRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(!Set.IsOpen())
	Set.Open();
	Set.Move(0);
	int n = 0;
	for(int i = 1;i <= Set.GetRecordCount();i++)
	{
		if(register_username == (CString)Set.m_Username)
		{
			n = 1;
			break;
		}
		Set.MoveNext();
	}
	CString yzin = register_yzin;
	CString yzout = register_yzout;
	yzin.MakeLower();
	yzout.MakeLower();
	if(n == 0)
	{
		if((register_password1 == register_password2) && (yzin == yzout) && (register_safeq != _T("")) && (register_safea != _T("")) && (register_password1 != _T("")))
		{
			Set.AddNew();
			Set.m_Username = (CStringW)register_username;
			Set.m_Password = (CStringW)register_password1;
			Set.m_SafeQ = (CStringW)register_safeq;
			Set.m_SafeA = (CStringW)register_safea;
			Set.Update();
			Set.Requery();
			CRegisterDlg::OnCancel();
		}
		else if(register_password1 != register_password2 )
			MessageBox(_T("密码错误！"),_T("系统提示"));
		else if(register_yzin != register_yzout)
			MessageBox(_T("验证码错误！"),_T("系统提示"));
	}
	else if(n == 1)
	{
		MessageBox(_T("用户名已被使用！"),_T("系统提示"));
	}
	Set.Close();
	UpdateData(FALSE);
}
