
// MSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "MSDlg.h"
#include "ForgetDlg.h"
#include "AdminDlg.h"
#include "NormalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMSDlg �Ի���



CMSDlg::CMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MS_DLG, pParent)
	, m_sUsername(_T(""))
	, m_sPassword(_T(""))
{
	m_iType = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iAdminNum = 1;
	m_sAdminUsername = new CString[m_iAdminNum];
	m_sAdminPassword = new CString[m_iAdminNum];
}

void CMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
}

BEGIN_MESSAGE_MAP(CMSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NORMAL, &CMSDlg::OnBnClickedNormal)
	ON_BN_CLICKED(IDC_ADMIN, &CMSDlg::OnBnClickedAdmin)
	ON_BN_CLICKED(IDOK, &CMSDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_FORGET, &CMSDlg::OnBnClickedForget)
END_MESSAGE_MAP()


// CMSDlg ��Ϣ�������

BOOL CMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CheckDlgButton(IDC_NORMAL, 1);
	m_sAdminUsername[0] = _T("gary");
	m_sAdminPassword[0] = _T("123456");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMSDlg::OnPaint()
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
HCURSOR CMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMSDlg::OnBnClickedNormal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iType = 0;
}


void CMSDlg::OnBnClickedAdmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iType = 1;
}


void CMSDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int tag = -1,i;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("�������û��������룡"), _T("ϵͳ��ʾ"));
	else if (m_iType == 1) {
		for (tag = 0,i = 0; i < m_iAdminNum; i++) {
			if (m_sUsername == m_sAdminUsername[i] && m_sPassword == m_sAdminPassword[i]) {
				tag = 1;
				break;
			}
		}
		if (tag == 1) {
			ShowWindow(SW_HIDE);
			CAdminDlg AdminDlg;
			if (AdminDlg.DoModal() == IDOK) {
				ShowWindow(SW_SHOW);
			}
			else {
				ShowWindow(SW_SHOW);
				CDialogEx::OnOK();
			}
		}
	}
	else {
		CString m_sInfo;
		if (!UserSet.IsOpen())
			UserSet.Open();
		if (UserSet.IsEOF()) {
			MessageBox(_T("�������Ա����Ϣ��"), _T("ϵͳ��ʾ"));
		}
		else {
			UserSet.Move(0);
			int i = 0;
			while (!UserSet.IsEOF()) {
				if (m_sUsername != (CString)UserSet.m_Username)
					UserSet.MoveNext();
				else if (m_sPassword != (CString)UserSet.m_Password) {
					MessageBox(_T("�û������������"), _T("ϵͳ��ʾ"));
					break;
				}
				else {
					tag = i;
					m_sInfo = (CString)UserSet.m_Number + _T("��") + (CString)UserSet.m_Kind;
					break;
				}
				i++;
			}
			if (tag >= 0) {
				ShowWindow(SW_HIDE);
				CNormalDlg NormalDlg;
				NormalDlg.m_sUser = m_sInfo;
				NormalDlg.m_iUserPos = tag;
				if (NormalDlg.DoModal() == IDOK) {
					ShowWindow(SW_SHOW);
				}
				else {
					ShowWindow(SW_SHOW);
					CDialogEx::OnOK();
				}
			}
		}
		UserSet.Close();
	}
	UpdateData(FALSE);
	//CDialogEx::OnOK();
}


void CMSDlg::OnBnClickedForget()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CForgetDlg open;
	if (!UserSet.IsOpen())
		UserSet.Open();
	if (UserSet.IsEOF()) {
		MessageBox(_T("�������Ա����Ϣ��"), _T("ϵͳ��ʾ"));
		UserSet.Close();
	}
	else
		open.DoModal();
}
