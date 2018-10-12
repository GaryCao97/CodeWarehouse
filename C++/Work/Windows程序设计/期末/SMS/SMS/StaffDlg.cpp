// StaffDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "StaffDlg.h"
#include "afxdialogex.h"
#include "StaffInfo.h"
#include "MerchInfo.h"
#include "MerchSell.h"


// CStaffDlg 对话框

IMPLEMENT_DYNAMIC(CStaffDlg, CDialogEx)

CStaffDlg::CStaffDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STAFF_DLG, pParent)
{

}

CStaffDlg::~CStaffDlg()
{
}

void CStaffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStaffDlg, CDialogEx)
	ON_BN_CLICKED(IDC_STAFFINFO, &CStaffDlg::OnBnClickedStaffinfo)
	ON_BN_CLICKED(IDC_MERCHNUM, &CStaffDlg::OnBnClickedMerchnum)
	ON_BN_CLICKED(IDC_MERCHINFO, &CStaffDlg::OnBnClickedMerchinfo)
END_MESSAGE_MAP()


// CStaffDlg 消息处理程序


void CStaffDlg::OnBnClickedStaffinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CStaffInfo staffInfo;
	staffInfo.DoModal();
}


void CStaffDlg::OnBnClickedMerchinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CMerchInfo merchInfo;
	merchInfo.DoModal();
}


void CStaffDlg::OnBnClickedMerchnum()
{
	// TODO: 在此添加控件通知处理程序代码
	CMerchSell merchSell;
	merchSell.DoModal();
}
