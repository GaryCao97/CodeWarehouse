// LoadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "LoadDlg.h"
#include "afxdialogex.h"


// CLoadDlg �Ի���

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


// CLoadDlg ��Ϣ�������


void CLoadDlg::OnBnClickedNormal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iType = 0;
}


void CLoadDlg::OnBnClickedAdmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iType = 1;
}


void CLoadDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
