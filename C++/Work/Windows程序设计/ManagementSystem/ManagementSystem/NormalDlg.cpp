// NormalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "NormalDlg.h"
#include "UserMana.h"
#include "CommDlg.h"
#include "CommNum.h"
#include "afxdialogex.h"


// CNormalDlg �Ի���

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


// CNormalDlg ��Ϣ�������


BOOL CNormalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int pos = 0;
	m_sUserNumber = m_sUser.Tokenize(_T("��"), pos);
	m_sUserKind = m_sUser.Tokenize(_T("��"), pos);
	//if (m_sUserKind == _T("Ա��")) {
	//	GetDlgItem(IDC_BTN_KIND)->EnableWindow(FALSE);
	//	GetDlgItem(IDC_BTN_IN)->EnableWindow(FALSE);
	//	GetDlgItem(IDC_BTN_OUT)->EnableWindow(FALSE);
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CNormalDlg::OnBnClickedBtnUser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CUserMana UserManage;
	UserManage.m_sUser = m_sUserNumber;
	UserManage.DoModal();
}


void CNormalDlg::OnBnClickedBtnComm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCommDlg CommDlg;
	CommDlg.m_sUserKind = m_sUserKind;
	CommDlg.m_iUserPos = m_iUserPos;
	CommDlg.DoModal();
}


void CNormalDlg::OnBnClickedBtnNum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCommNum NumDlg;
	NumDlg.m_sUserKind = m_sUserKind;
	NumDlg.m_iUserPos = m_iUserPos;
	NumDlg.DoModal();
}
