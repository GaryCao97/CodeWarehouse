// StartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "StartDlg.h"
#include "ChangepwDlg.h"
#include "ChangeiDlg.h"
#include "InputDlg.h"
#include "OutputDlg.h"
#include "SearchDlg.h"
#include "SortDlg.h"
#include "ѧ���ɼ�����Dlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"


// CStartDlg �Ի���

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


// CStartDlg ��Ϣ�������


void CStartDlg::OnBnClickedstartRestart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStartDlg::OnOK();
}


void CStartDlg::OnBnClickedstartInputi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInputDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartChangei()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CChangeiDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartOutputi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	COutputDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartSorti()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSortDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartSearchi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSearchDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}


void CStartDlg::OnBnClickedstartChangepw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CChangepwDlg open;
	open.DoModal();
	CStartDlg::CStartDlg();
}
