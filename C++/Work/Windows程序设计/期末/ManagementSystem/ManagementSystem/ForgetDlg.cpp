// ForgetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "ForgetDlg.h"
#include "afxdialogex.h"


// CForgetDlg �Ի���

IMPLEMENT_DYNAMIC(CForgetDlg, CDialogEx)

CForgetDlg::CForgetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORGET, pParent)
	, m_sUsername(_T(""))
	, m_sNumber(_T(""))
	, m_sPassword1(_T(""))
	, m_sPassword2(_T(""))
	, m_sYzm1(_T(""))
	, m_sYzm2(_T(""))
{

}

CForgetDlg::~CForgetDlg()
{
}

void CForgetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_F_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_F_NUMBER, m_sNumber);
	DDX_Text(pDX, IDC_F_PASSWORD1, m_sPassword1);
	DDX_Text(pDX, IDC_F_PASSWORD2, m_sPassword2);
	DDX_Text(pDX, IDC_F_YZM1, m_sYzm1);
	DDX_Text(pDX, IDC_F_YZM2, m_sYzm2);
}


BEGIN_MESSAGE_MAP(CForgetDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CForgetDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CForgetDlg ��Ϣ�������


BOOL CForgetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_sYzm2 = GetYzm();
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CForgetDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString yzm1 = m_sYzm1;
	CString yzm2 = m_sYzm2;
	yzm1 = yzm1.MakeLower();
	yzm2 = yzm2.MakeLower();
	if (yzm1 != yzm2) {
		MessageBox(_T("��֤�����"), _T("ϵͳ��ʾ"));
		CForgetDlg::OnInitDialog();
	}
	else if (m_sPassword1 != m_sPassword2){
		MessageBox(_T("��������Ӧ����ͬ��"), _T("ϵͳ��ʾ"));
		CForgetDlg::OnInitDialog();
	}
	else {
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.Move(0);
		int n = 0;
		while (!UserSet.IsEOF()){
			if (m_sNumber != (CString)UserSet.m_Number)
				UserSet.MoveNext();
			else if (m_sUsername != (CString)UserSet.m_Username) {
				MessageBox(_T("��������ȷ���û�����"), _T("ϵͳ��ʾ"));
				break;
			}
			else {
				n = 1;
				UserSet.Edit();
				UserSet.m_Password = m_sPassword1;
				UserSet.Update();
				MessageBox(_T("�޸ĳɹ���"), _T("ϵͳ��ʾ"));
				break;
			}
		}
		UserSet.Close();
		if (n == 1)
			CDialogEx::OnOK();
	}
	UpdateData(FALSE);
}
