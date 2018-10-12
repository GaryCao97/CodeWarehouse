
// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Info.h"
#include "InfoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInfoDlg �Ի���



CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO_DIALOG, pParent)
	, m_sName(_T(""))
	, m_sNumber(_T(""))
	, m_sClass(_T(""))
	, m_iMath(0)
	, m_iEng(0)
	, m_iCom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sGender = _T("");
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDX_Text(pDX, IDC_NUMBER, m_sNumber);
	DDX_Text(pDX, IDC_CLASS, m_sClass);
	DDX_Text(pDX, IDC_SCORE_MATH, m_iMath);
	DDV_MinMaxInt(pDX, m_iMath, 0, 100);
	DDX_Text(pDX, IDC_SCORE_ENG, m_iEng);
	DDV_MinMaxInt(pDX, m_iEng, 0, 100);
	DDX_Text(pDX, IDC_SCORE_COM, m_iCom);
	DDV_MinMaxInt(pDX, m_iCom, 0, 100);
}

BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInfoDlg::OnBnClickedCancel)
	ON_COMMAND(IDC_FEMALE_RADIO, &CInfoDlg::OnFemaleRadio)
	ON_COMMAND(IDC_MALE_RADIO, &CInfoDlg::OnMaleRadio)
END_MESSAGE_MAP()


// CInfoDlg ��Ϣ�������

BOOL CInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CInfoDlg::OnPaint()
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
HCURSOR CInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInfoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CString str;
	str.Format(_T("��ѧ��%d\nӢ�%d\n�������%d"), m_iMath, m_iEng, m_iCom);
	if (CTaskDialog::IsSupported()) {
		CTaskDialog taskDlg(_T(""), _T(""), _T(""));
		taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
		taskDlg.SetWindowTitle(_T("������Ϣ"));
		taskDlg.SetMainInstruction(m_sName);
		taskDlg.SetContent(
			_T("ѧ�ţ�") + m_sNumber 
			+ _T("\n�Ա�") + m_sGender 
			+ _T("\n�༶��") + m_sClass
		);
		taskDlg.SetExpansionArea(str, _T("�����ʾ�ɼ�"), _T("������سɼ�"));
		taskDlg.SetFooterIcon(MAKEINTRESOURCE(IDI_INFORMATION));
		taskDlg.SetFooterText(_T("Personal Information"));
		taskDlg.DoModal();
	}
	else {
		MessageBox(_T("ERROR"), _T("ERROR"));
	}
	CDialogEx::OnOK();
}


void CInfoDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CInfoDlg::OnFemaleRadio()
{
	// TODO: �ڴ���������������
	m_sGender = _T("Ů");
}


void CInfoDlg::OnMaleRadio()
{
	// TODO: �ڴ���������������
	m_sGender = _T("��");
}
