// StaffDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "StaffDlg.h"
#include "afxdialogex.h"
#include "StaffInfo.h"
#include "MerchInfo.h"
#include "MerchSell.h"


// CStaffDlg �Ի���

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


// CStaffDlg ��Ϣ�������


void CStaffDlg::OnBnClickedStaffinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStaffInfo staffInfo;
	staffInfo.DoModal();
}


void CStaffDlg::OnBnClickedMerchinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchInfo merchInfo;
	merchInfo.DoModal();
}


void CStaffDlg::OnBnClickedMerchnum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchSell merchSell;
	merchSell.DoModal();
}
