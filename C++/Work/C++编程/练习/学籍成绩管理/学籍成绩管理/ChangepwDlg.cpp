// ChangepwDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "ChangepwDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CUserSet Set;
extern int m;

// CChangepwDlg �Ի���

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


// CChangepwDlg ��Ϣ�������


void CChangepwDlg::OnBnClickedchangepwReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CChangepwDlg::OnCancel();
}


void CChangepwDlg::OnBnClickedchangepwSure()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
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
		MessageBox(_T("ԭ�������"),_T("ϵͳ��ʾ"));
	else if(pw_new1 != pw_new2)
		MessageBox(_T("��������ȷ�����룡"),_T("ϵͳ��ʾ"));
	Set.Close();
	UpdateData(FALSE);
	CChangepwDlg::OnCancel();
}
