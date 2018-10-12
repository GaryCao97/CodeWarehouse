
// ѧ���ɼ�����Dlg.cpp : ʵ���ļ�
//


#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "ѧ���ɼ�����Dlg.h"
#include "StartDlg.h"
#include "RegisterDlg.h"
#include "OutputDlg.h"
#include "ForgetDlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CUserSet Set;
int m;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLoadDlg �Ի���



CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoadDlg::IDD, pParent)
	, load_username(_T(""))
	, load_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_load_Username, load_username);
	DDX_Text(pDX, IDC_load_Password, load_password);
}

BEGIN_MESSAGE_MAP(CLoadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_load_Register, &CLoadDlg::OnBnClickedloadRegister)
	ON_BN_CLICKED(IDC_load_Login, &CLoadDlg::OnBnClickedloadLogin)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoadDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoadDlg ��Ϣ�������

BOOL CLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//SQLConfigDataSource(NULL, ODBC_ADD_SYS_DSN, "Microsoft Access Driver (*.mdb)\0", "DSN = TryDB\0DBQ = D:\\Database\\try.mdb\0DEFAULTDIR = D:\\DATABASE\0\0");
	Set.Open();
	if(Set.IsEOF())
		MessageBox(_T("����ע�ᣡ"),_T("ϵͳ��ʾ"));
	Set.Close();
	srand(time(0));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLoadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLoadDlg::OnPaint()
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
HCURSOR CLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLoadDlg::OnBnClickedloadRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegisterDlg open;
	open.DoModal();
}



void CLoadDlg::OnBnClickedloadLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	Set.Open();
	Set.Move(0);
	int n = 0;
	for(m = 0;m < Set.GetRecordCount();m++)
	{
		if(load_username == (CString)Set.m_Username)
		{
			n = 1;
			break;
		}
		Set.MoveNext();
	}
	if(n == 0)
		MessageBox(_T("�û��������ڣ�"),_T("ϵͳ��ʾ"));
	else if(n == 1)
	{
		if(load_password == (CString)Set.m_Password)
		{
			ShowWindow(SW_HIDE);
			CStartDlg open;
			int o = open.DoModal();
			if(o == IDOK)
			{
				CLoadDlg::CLoadDlg();
				ShowWindow(SW_SHOW);
				load_password = _T("");
				load_username = _T("");
			}
			else if (o == IDCANCEL)
				CLoadDlg::OnCancel();
		}
		else
			MessageBox(_T("�������"),_T("ϵͳ��ʾ"));
	}
	UpdateData(FALSE);
	Set.Close();
}





void CLoadDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CForgetDlg open;
	open.DoModal();
}
