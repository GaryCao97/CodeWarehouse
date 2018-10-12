
// MFC1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC1.h"
#include "MFC1Dlg.h"
#include "Information.h"
#include "afxdialogex.h"
CInformation Set_3;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMFC1Dlg 对话框



CMFC1Dlg::CMFC1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMFC1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC1Dlg 消息处理程序

BOOL CMFC1Dlg::OnInitDialog()
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

	Set_3.Open();
	m_list.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE|LVS_EX_AUTOSIZECOLUMNS);
	if(Set_3.IsEOF())
		MessageBox(_T("请先录入数据"),_T("系统提示"));
	else
	{
		int i;
		CODBCFieldInfo DbFi;
		LV_COLUMN Lc;
		Lc.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
		for(i = 0;i < 13;i++)
		{
			Set_3.GetODBCFieldInfo(i,DbFi);
			Lc.iSubItem = i;
			Lc.fmt = LVCFMT_CENTER;
			Lc.cx = DbFi.m_strName.GetLength()*10+20;
			Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
			m_list.InsertColumn(i,&Lc);
		}
	}
	Set_3.Move(0);
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int i,j;
	i = 0;
	while(Set_3.IsEOF() == 0)
	{
		m_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		Set_3.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		m_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			Set_3.GetFieldValue((short)j,string);
			m_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		Set_3.MoveNext();
		i++;
		m_list.SetRedraw(TRUE);
	}
	
	Set_3.Close();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC1Dlg::OnPaint()
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
HCURSOR CMFC1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

