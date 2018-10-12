
// MSDlg.cpp : 实现文件
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


// CMSDlg 对话框



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


// CMSDlg 消息处理程序

BOOL CMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CheckDlgButton(IDC_NORMAL, 1);
	m_sAdminUsername[0] = _T("gary");
	m_sAdminPassword[0] = _T("123456");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMSDlg::OnPaint()
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
HCURSOR CMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMSDlg::OnBnClickedNormal()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 0;
}


void CMSDlg::OnBnClickedAdmin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 1;
}


void CMSDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int tag = -1,i;
	if (m_sUsername == _T("") || m_sPassword == _T(""))
		MessageBox(_T("请输入用户名和密码！"), _T("系统提示"));
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
			MessageBox(_T("请先添加员工信息！"), _T("系统提示"));
		}
		else {
			UserSet.Move(0);
			int i = 0;
			while (!UserSet.IsEOF()) {
				if (m_sUsername != (CString)UserSet.m_Username)
					UserSet.MoveNext();
				else if (m_sPassword != (CString)UserSet.m_Password) {
					MessageBox(_T("用户名或密码错误！"), _T("系统提示"));
					break;
				}
				else {
					tag = i;
					m_sInfo = (CString)UserSet.m_Number + _T("：") + (CString)UserSet.m_Kind;
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
	// TODO: 在此添加控件通知处理程序代码
	CForgetDlg open;
	if (!UserSet.IsOpen())
		UserSet.Open();
	if (UserSet.IsEOF()) {
		MessageBox(_T("请先添加员工信息！"), _T("系统提示"));
		UserSet.Close();
	}
	else
		open.DoModal();
}
