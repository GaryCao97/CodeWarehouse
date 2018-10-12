// ForgetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "ForgetDlg.h"
#include "ResetDlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"
extern CUserSet Set;
int z;
// CForgetDlg 对话框

IMPLEMENT_DYNAMIC(CForgetDlg, CDialogEx)

CForgetDlg::CForgetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CForgetDlg::IDD, pParent)
	, forget_yzout(_T(""))
	, forget_yzin(_T(""))
	, forget_username(_T(""))
{

}

CForgetDlg::~CForgetDlg()
{
}

void CForgetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_forget_YzOut, forget_yzout);
	DDX_Text(pDX, IDC_forget_YzIn, forget_yzin);
	DDX_Text(pDX, IDC_forget_Username, forget_username);
}


BEGIN_MESSAGE_MAP(CForgetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_forget_Return, &CForgetDlg::OnBnClickedforgetReturn)
	ON_BN_CLICKED(IDC_forget_Change, &CForgetDlg::OnBnClickedforgetChange)
END_MESSAGE_MAP()


// CForgetDlg 消息处理程序


BOOL CForgetDlg::OnInitDialog()
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
	forget_yzout = yzm;
	UpdateData(FALSE);

	return TRUE;
}


void CForgetDlg::OnBnClickedforgetReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CForgetDlg::OnCancel();
}


void CForgetDlg::OnBnClickedforgetChange()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(!Set.IsOpen())
	Set.Open();
	Set.Move(0);
	int n = 0;
	for(z = 0;z < Set.GetRecordCount();z++)
	{
		if(forget_username == (CString)Set.m_Username)
		{
			n = 1;
			break;
		}
		Set.MoveNext();
	}
	CString yzin = forget_yzin;
	CString yzout = forget_yzout;
	yzin.MakeLower();
	yzout.MakeLower();
	if(n == 0)
		MessageBox(_T("用户名不存在！"),_T("系统提示"));
	else if(n == 1)
	{
		if((yzin == yzout))
		{
			CResetDlg open;
			int y = open.DoModal();
			if(y == IDOK)
				CForgetDlg::OnCancel();
		}
		else
			MessageBox(_T("验证码错误！"),_T("系统提示"));
	}
	UpdateData(FALSE);
	Set.Close();
}
