
// InfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Info.h"
#include "InfoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInfoDlg 对话框



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


// CInfoDlg 消息处理程序

BOOL CInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInfoDlg::OnPaint()
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
HCURSOR CInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CString str;
	str.Format(_T("数学：%d\n英语：%d\n计算机：%d"), m_iMath, m_iEng, m_iCom);
	if (CTaskDialog::IsSupported()) {
		CTaskDialog taskDlg(_T(""), _T(""), _T(""));
		taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
		taskDlg.SetWindowTitle(_T("个人信息"));
		taskDlg.SetMainInstruction(m_sName);
		taskDlg.SetContent(
			_T("学号：") + m_sNumber 
			+ _T("\n性别：") + m_sGender 
			+ _T("\n班级：") + m_sClass
		);
		taskDlg.SetExpansionArea(str, _T("点击显示成绩"), _T("点击隐藏成绩"));
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
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CInfoDlg::OnFemaleRadio()
{
	// TODO: 在此添加命令处理程序代码
	m_sGender = _T("女");
}


void CInfoDlg::OnMaleRadio()
{
	// TODO: 在此添加命令处理程序代码
	m_sGender = _T("男");
}
