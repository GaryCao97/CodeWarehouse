
// SMSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "SMSDlg.h"
#include "afxdialogex.h"
#include "Forget.h"
#include "ManaDlg.h"
#include "StaffDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSMSDlg �Ի���



CSMSDlg::CSMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SMS_DIALOG, pParent)
	, m_sUsername(_T(""))
	, m_sPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
}

BEGIN_MESSAGE_MAP(CSMSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_FORGET, &CSMSDlg::OnStnClickedForget)
	ON_BN_CLICKED(IDC_LOGIN_STAFF, &CSMSDlg::OnBnClickedLoginStaff)
	ON_BN_CLICKED(IDC_LOGIN_ADMIN, &CSMSDlg::OnBnClickedLoginAdmin)
END_MESSAGE_MAP()


// CSMSDlg ��Ϣ�������

BOOL CSMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if (!StaffSet.IsOpen())
		StaffSet.Open();
	if (StaffSet.IsEOF())
		MessageBox(_T("����¼��Ա����Ϣ"), _T("ϵͳ��ʾ"));
	StaffSet.Close();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSMSDlg::OnStnClickedForget()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CForget forgerDlg;
	forgerDlg.DoModal();
}


void CSMSDlg::OnBnClickedLoginStaff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CStaffDlg staffDlg;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("�������û���������"), _T("ϵͳ��ʾ"));
	else {
		if (StaffSet.IsOpen())
			StaffSet.Close();
		StaffSet.m_strFilter = _T("Username='") + m_sUsername + _T("'");
		StaffSet.Open();
		if (StaffSet.IsEOF())
			MessageBox(_T("�û���������"), _T("ϵͳ��ʾ"));
		else {
			if(StaffSet.m_Password != m_sPassword)
				MessageBox(_T("�û������������"), _T("ϵͳ��ʾ"));
			else{
				m_strUsername = m_sUsername;
				m_strPost = StaffSet.m_Post;
				m_strDuty = StaffSet.m_Duty;
				m_saDuty = DivideString(m_strDuty, _T("��"));
				StaffSet.Close();
				staffDlg.DoModal();
			}
		}
	}
}


void CSMSDlg::OnBnClickedLoginAdmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CManaDlg manaDlg;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("�������û���������"), _T("ϵͳ��ʾ"));
	else if (m_sUsername == _T("gary") && m_sPassword == _T("123456")) {
		manaDlg.DoModal();
	}
}
