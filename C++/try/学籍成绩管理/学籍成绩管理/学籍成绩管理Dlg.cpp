
// 学籍成绩管理Dlg.cpp : 实现文件
//


#include "stdafx.h"
#include "学籍成绩管理.h"
#include "学籍成绩管理Dlg.h"
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CLoadDlg 对话框



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


// CLoadDlg 消息处理程序

BOOL CLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//SQLConfigDataSource(NULL, ODBC_ADD_SYS_DSN, "Microsoft Access Driver (*.mdb)\0", "DSN = TryDB\0DBQ = D:\\Database\\try.mdb\0DEFAULTDIR = D:\\DATABASE\0\0");
	Set.Open();
	if(Set.IsEOF())
		MessageBox(_T("请先注册！"),_T("系统提示"));
	Set.Close();
	srand(time(0));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLoadDlg::OnBnClickedloadRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegisterDlg open;
	open.DoModal();
}



void CLoadDlg::OnBnClickedloadLogin()
{
	// TODO: 在此添加控件通知处理程序代码
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
		MessageBox(_T("用户名不存在！"),_T("系统提示"));
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
			MessageBox(_T("密码错误！"),_T("系统提示"));
	}
	UpdateData(FALSE);
	Set.Close();
}





void CLoadDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CForgetDlg open;
	open.DoModal();
}
