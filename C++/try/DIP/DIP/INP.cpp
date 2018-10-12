// INP.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "INP.h"
#include "afxdialogex.h"


// CINP �Ի���

IMPLEMENT_DYNAMIC(CINP, CDialogEx)

CINP::CINP(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOISE, pParent)
	, m_check1(FALSE)
	, m_radio1(0)
	, m_pa(0)
	, m_pb(0)
	, m_ua(0)
	, m_ub(0)
	, m_gauess_mu(0)
	, m_gauess_sigma(0)
	, m_gauess_k(0)
{
	EnableAutomation();
}

CINP::~CINP()
{
}

void CINP::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CINP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECKSRC, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_pa);
	DDX_Text(pDX, IDC_EDIT2, m_pb);
	DDX_Text(pDX, IDC_EDIT3, m_ua);
	DDX_Text(pDX, IDC_EDIT4, m_ub);
	DDX_Text(pDX, IDC_EDIT5, m_gauess_mu);
	DDX_Text(pDX, IDC_EDIT6, m_gauess_sigma);
	DDX_Text(pDX, IDC_EDIT7, m_gauess_k);
}


BEGIN_MESSAGE_MAP(CINP, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CINP::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CINP::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CINP::OnBnClickedRadio3)
	ON_BN_CLICKED(IDOK, &CINP::OnBnClickedOk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CINP, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IINP ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {829D670C-6302-45BA-A535-3F54A71B73F2}
static const IID IID_IINP =
{ 0x829D670C, 0x6302, 0x45BA, { 0xA5, 0x35, 0x3F, 0x54, 0xA7, 0x1B, 0x73, 0xF2 } };

BEGIN_INTERFACE_MAP(CINP, CDialogEx)
	INTERFACE_PART(CINP, IID_IINP, Dispatch)
END_INTERFACE_MAP()


// CINP ��Ϣ�������


void CINP::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio1 = 0;
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
}


void CINP::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio1 = 1;
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
}


void CINP::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio1 = 2;
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);
}


void CINP::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
