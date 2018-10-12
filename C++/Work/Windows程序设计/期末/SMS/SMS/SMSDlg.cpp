
// SMSDlg.cpp : 实现文件
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


// CSMSDlg 对话框



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


// CSMSDlg 消息处理程序

BOOL CSMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if (!StaffSet.IsOpen())
		StaffSet.Open();
	if (StaffSet.IsEOF())
		MessageBox(_T("请先录入员工信息"), _T("系统提示"));
	StaffSet.Close();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSMSDlg::OnPaint()
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
HCURSOR CSMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSMSDlg::OnStnClickedForget()
{
	// TODO: 在此添加控件通知处理程序代码
	CForget forgerDlg;
	forgerDlg.DoModal();
}


void CSMSDlg::OnBnClickedLoginStaff()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CStaffDlg staffDlg;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("请输入用户名和密码"), _T("系统提示"));
	else {
		if (StaffSet.IsOpen())
			StaffSet.Close();
		StaffSet.m_strFilter = _T("Username='") + m_sUsername + _T("'");
		StaffSet.Open();
		if (StaffSet.IsEOF())
			MessageBox(_T("用户名不存在"), _T("系统提示"));
		else {
			if(StaffSet.m_Password != m_sPassword)
				MessageBox(_T("用户名或密码错误"), _T("系统提示"));
			else{
				m_strUsername = m_sUsername;
				m_strPost = StaffSet.m_Post;
				m_strDuty = StaffSet.m_Duty;
				m_saDuty = DivideString(m_strDuty, _T("；"));
				StaffSet.Close();
				staffDlg.DoModal();
			}
		}
	}
}


void CSMSDlg::OnBnClickedLoginAdmin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CManaDlg manaDlg;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("请输入用户名和密码"), _T("系统提示"));
	else if (m_sUsername == _T("gary") && m_sPassword == _T("123456")) {
		manaDlg.DoModal();
	}
}
