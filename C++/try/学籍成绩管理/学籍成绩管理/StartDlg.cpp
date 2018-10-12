// StartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "StartDlg.h"
#include "ChangepwDlg.h"
#include "ChangeiDlg.h"
#include "InputDlg.h"
#include "OutputDlg.h"
#include "SearchDlg.h"
#include "SortDlg.h"
#include "学籍成绩管理Dlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"


// CStartDlg 对话框

IMPLEMENT_DYNAMIC(CStartDlg, CDialogEx)

CStartDlg::CStartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStartDlg::IDD, pParent)
{

}

CStartDlg::~CStartDlg()
{
}

void CStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStartDlg, CDialogEx)
	ON_BN_CLICKED(IDC_start_Restart, &CStartDlg::OnBnClickedstartRestart)
	ON_BN_CLICKED(IDC_start_InputI, &CStartDlg::OnBnClickedstartInputi)
	ON_BN_CLICKED(IDC_start_ChangeI, &CStartDlg::OnBnClickedstartChangei)
	ON_BN_CLICKED(IDC_start_OutputI, &CStartDlg::OnBnClickedstartOutputi)
	ON_BN_CLICKED(IDC_start_SortI, &CStartDlg::OnBnClickedstartSorti)
	ON_BN_CLICKED(IDC_start_SearchI, &CStartDlg::OnBnClickedstartSearchi)
	ON_BN_CLICKED(IDC_start_ChangePW, &CStartDlg::OnBnClickedstartChangepw)
END_MESSAGE_MAP()


// CStartDlg 消息处理程序


void CStartDlg::OnBnClickedstartRestart()
{
	// TODO: 在此添加控件通知处理程序代码
	CStartDlg::OnOK();
}


void CStartDlg::OnBnClickedstartInputi()
{
	// TODO: 在此添加控件通知处理程序代码
	CInputDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartChangei()
{
	// TODO: 在此添加控件通知处理程序代码
	CChangeiDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartOutputi()
{
	// TODO: 在此添加控件通知处理程序代码
	COutputDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartSorti()
{
	// TODO: 在此添加控件通知处理程序代码
	CSortDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartSearchi()
{
	// TODO: 在此添加控件通知处理程序代码
	CSearchDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartChangepw()
{
	// TODO: 在此添加控件通知处理程序代码
	CChangepwDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}
