// StaffAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "StaffAdd.h"
#include "afxdialogex.h"


// CStaffAdd �Ի���

IMPLEMENT_DYNAMIC(CStaffAdd, CDialogEx)

CStaffAdd::CStaffAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDSTAFF, pParent)
	, m_sUsername(_T(""))
	, m_sPassword(_T(""))
	, m_sPost(_T(""))
	, m_sDuty(_T(""))
{

}

CStaffAdd::~CStaffAdd()
{
}

void CStaffAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	DDX_CBString(pDX, IDC_POST, m_sPost);
	DDX_Text(pDX, IDC_DUTY, m_sDuty);
}


BEGIN_MESSAGE_MAP(CStaffAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStaffAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// CStaffAdd ��Ϣ�������


void CStaffAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (!StaffSet.IsOpen())
		StaffSet.Open();
	if (m_sPassword == _T("") || m_sUsername == _T("") || m_sDuty == _T("") || m_sPost == _T(""))
		MessageBox(_T("������������Ϣ��"), _T("ϵͳ��ʾ"));
	else
	{
		CODBCFieldInfo info;
		if (StaffSet.IsOpen())
			StaffSet.Close();
		StaffSet.m_strFilter = _T("Username='") + m_sUsername + _T("'");
		if (!StaffSet.IsOpen())
			StaffSet.Open();
		if (!StaffSet.IsEOF()) {
			StaffSet.Close();
			StaffSet.m_strFilter = _T("");
			StaffSet.Open();
			MessageBox(_T("�û����Ѵ��ڣ�"), _T("ϵͳ��ʾ"));
		}
		else {
			StaffSet.Close();
			StaffSet.m_strFilter = _T("");
			StaffSet.Open();
			StaffSet.AddNew();
			StaffSet.m_Username = m_sUsername;
			StaffSet.m_Duty = m_sDuty;
			StaffSet.m_Post = m_sPost;
			StaffSet.m_Password = m_sPassword;
			StaffSet.Update();
			StaffSet.Close();
			UpdateData(FALSE);
			CDialogEx::OnOK();
		}
	}
	StaffSet.Close();
}
