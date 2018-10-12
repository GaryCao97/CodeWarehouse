
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Student.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
	ON_COMMAND(ID_DYN_FIRST, &CMainFrame::OnDynFirst)
	ON_COMMAND(ID_DYN_SECOND, &CMainFrame::OnDynSecond)
	ON_COMMAND(ID_DYN_ADD, &CMainFrame::OnDynAdd)
	ON_COMMAND(ID_DYN_DELETE, &CMainFrame::OnDynDelete)
	ON_COMMAND(ID_NAME_LISI, &CMainFrame::OnNameLisi)
	ON_UPDATE_COMMAND_UI(ID_NAME_LISI, &CMainFrame::OnUpdateNameLisi)
	ON_COMMAND(ID_NAME_ZHANGSAN, &CMainFrame::OnNameZhangsan)
	ON_UPDATE_COMMAND_UI(ID_NAME_ZHANGSAN, &CMainFrame::OnUpdateNameZhangsan)
	ON_COMMAND(ID_SCORE_SCORE, &CMainFrame::OnScoreScore)
	ON_COMMAND(ID_INPUT_INFO, &CMainFrame::OnInputInfo)
	ON_COMMAND_RANGE(MY_ID, MY_ID_MAX, &CMainFrame::OnCommandRange)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_POINT,
	ID_INDICATOR_POINT,
	ID_INDICATOR_TIME,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	m_bZhangSan = FALSE;
	m_bLiSi = FALSE;
	m_iAnal = 80;
	m_iAlge = 70;
	m_iProb = 88;
	m_iProg = 76;
	m_iData = 94;
	m_iOrga = 85;
	m_iPoli = 68;
	m_iEngl = 88;
	m_iPhys = 63;
	newMenuNum = 2;
	MID = MY_ID;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 创建一个视图以占用框架的工作区
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// 启动定时器，定时器ID为1，定时时间为1000ms，即1s
	SetTimer(1, 1000, NULL);

	m_bitmaps_ZHANGSAN1.LoadBitmap(IDB_ZHANGSAN);
	m_bitmaps_LISI1.LoadBitmap(IDB_LISI);
	m_bitmaps_ZHANGSAN2.LoadBitmap(IDB_ZHANGSAN_UN);
	m_bitmaps_LISI2.LoadBitmap(IDB_LISI_UN);
	CMenu *m_pMainmenu;
	m_pMainmenu = GetMenu();
	m_pMainmenu->SetMenuItemBitmaps(ID_NAME_ZHANGSAN, MF_BYCOMMAND, &m_bitmaps_ZHANGSAN1, &m_bitmaps_ZHANGSAN2);
	m_pMainmenu->SetMenuItemBitmaps(ID_NAME_LISI, MF_BYCOMMAND, &m_bitmaps_LISI1, &m_bitmaps_LISI2);
	m_bitmaps_ZHANGSAN1.Detach();
	m_bitmaps_LISI1.Detach();
	m_bitmaps_ZHANGSAN2.Detach();
	m_bitmaps_LISI2.Detach();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString strTime;
	// 获取系统当前时间，并保存到curTime   
	CTime curTime = CTime::GetCurrentTime();
	// 格式化curTime，将字符串保存到strTime   
	strTime = curTime.Format(_T("%H:%M:%S"));
	// 在状态栏的时间窗格中显示系统时间字符串   
	m_wndStatusBar.SetPaneText(3, strTime);
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnDynFirst()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("你选择了first"), _T("first"), MB_OK | MB_ICONQUESTION);
}

void CMainFrame::OnDynSecond()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("你选择了second"), _T("second"), MB_OK | MB_ICONQUESTION);
}


void CMainFrame::OnDynAdd()
{
	// TODO: 在此添加命令处理程序代码
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("动态菜单装载失败！"), _T("错误"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString str;
	str = _T("我的动态菜单(&M)");
	m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, str);
	m_addMenu.Detach();
	DrawMenuBar();
}


void CMainFrame::OnDynDelete()
{
	// TODO: 在此添加命令处理程序代码
	CMenu *m_pMainmenu;
	m_pMainmenu = GetMenu();
	int position = GetPosFromMenu(_T("我的动态菜单(&M)"));
	if (position >= 0) m_pMainmenu->DeleteMenu(position, MF_BYPOSITION);
	DrawMenuBar();
}



void CMainFrame::OnNameLisi()
{
	// TODO: 在此添加命令处理程序代码
	m_bLiSi = !m_bLiSi;
	if (m_bLiSi) {
		if (CTaskDialog::IsSupported()) {
			CTaskDialog taskDlg(_T(""), _T(""), _T(""));
			// 设置任务对话框的主图标
			taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetWindowTitle(_T("学生信息"));
			taskDlg.SetMainInstruction(_T("姓名：李四"));
			taskDlg.SetContent(_T("学号：") + m_sNumber[1] + _T("\n班级：") + m_sClass[1] + _T("\n图片地址：") + m_sPhoto[1]);
			taskDlg.SetFooterIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetFooterText(_T("Student Information"));
			taskDlg.DoModal();
		}
		else {
			MessageBox(_T("ERROR"), _T("ERROR"));
		}
	}
}


void CMainFrame::OnUpdateNameLisi(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bLiSi);
}


void CMainFrame::OnNameZhangsan()
{
	// TODO: 在此添加命令处理程序代码
	m_bZhangSan = !m_bZhangSan;
	if (m_bZhangSan) {
		if (CTaskDialog::IsSupported()) {
			CTaskDialog taskDlg(_T(""), _T(""), _T(""));
			// 设置任务对话框的主图标
			taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetWindowTitle(_T("学生信息"));
			taskDlg.SetMainInstruction(_T("姓名：张三"));
			taskDlg.SetContent(_T("学号：") + m_sNumber[0] + _T("\n班级：") + m_sClass[0] + _T("\n图片地址：") + m_sPhoto[0]);
			taskDlg.SetFooterIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetFooterText(_T("Student Information"));
			taskDlg.DoModal();
		}
		else {
			MessageBox(_T("ERROR"), _T("ERROR"));
		}
	}
}


void CMainFrame::OnUpdateNameZhangsan(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bZhangSan);
}


void CMainFrame::OnScoreScore()
{
	// TODO: 在此添加命令处理程序代码
	CMathPg pgMath;
	CCompPg pgComp;
	CCommPg pgComm;
	pgMath.m_iAlge = m_iAlge;
	pgMath.m_iAnal = m_iAnal;
	pgMath.m_iProb = m_iProb;
	pgComp.m_iData = m_iData;
	pgComp.m_iOrga = m_iOrga;
	pgComp.m_iProg = m_iProg;
	pgComm.m_iEngl = m_iEngl;
	pgComm.m_iPhys = m_iPhys;
	pgComm.m_iPoli = m_iPoli;
	CPropertySheet ps(_T("课程成绩"));
	ps.AddPage(&pgMath);
	ps.AddPage(&pgComp);
	ps.AddPage(&pgComm);
	if (ps.DoModal() == IDOK) {
		m_iAlge = pgMath.m_iAlge;
		m_iAnal = pgMath.m_iAnal;
		m_iProb = pgMath.m_iProb;
		m_iData = pgComp.m_iData;
		m_iOrga = pgComp.m_iOrga;
		m_iProg = pgComp.m_iProg;
		m_iEngl = pgComm.m_iEngl;
		m_iPhys = pgComm.m_iPhys;
		m_iPoli = pgComm.m_iPoli;
	}
}

void CMainFrame::OnCommandRange(UINT nID)
{
	CString stringsssss;
	stringsssss.Format(_T("%d"), nID - 14464);
	//MessageBox(stringsssss, _T("ERROR"));
	int nNumFromId = (nID - 14464) + 2;
	if (nNumFromId < 100) {
		if (CTaskDialog::IsSupported()) {
			CTaskDialog taskDlg(_T(""), _T(""), _T(""));
			taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetWindowTitle(_T("学生信息"));
			taskDlg.SetMainInstruction(_T("姓名：") + m_sName[nNumFromId]);
			taskDlg.SetContent(_T("学号：") + m_sNumber[nNumFromId] + _T("\n班级：") + m_sClass[nNumFromId] + _T("\n图片地址：") + m_sPhoto[nNumFromId]);
			taskDlg.SetFooterIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetFooterText(_T("Student Information"));
			taskDlg.DoModal();
		}
		else {
			MessageBox(_T("ERROR"), _T("ERROR"));
		}
	}
}

void CMainFrame::OnInputInfo()
{
	// TODO: 在此添加命令处理程序代码
	InfoInputDlg dlg;
	int pos = -1;
	if (dlg.DoModal() == IDOK) {
		CMenu *m_pMenu;
		m_pMenu = GetMenu();
		m_pMenu = m_pMenu->GetSubMenu(GetPosFromMenu(_T("姓名(&N)")));
		CString str;
		for (int i = m_pMenu->GetMenuItemCount() - 1; i >= 0; i--) {
			m_pMenu->GetMenuStringW(i, str, MF_BYPOSITION);
			MessageBox(str + dlg.m_sName, _T("ERROR"));
			if (str == dlg.m_sName + _T("...")) {
				pos = i / 2;
				break;
			}
		}
		if (pos >= 0) {
			m_sName[pos] = dlg.m_sName;
			m_sClass[pos] = dlg.m_sClass;
			m_sNumber[pos] = dlg.m_sNumber;
			m_sPhoto[pos] = dlg.m_sPhoto;
		}
		else if (MID < MY_ID_MAX) {
			m_sName[newMenuNum] = dlg.m_sName;
			m_sClass[newMenuNum] = dlg.m_sClass;
			m_sNumber[newMenuNum] = dlg.m_sNumber;
			m_sPhoto[newMenuNum] = dlg.m_sPhoto;
			newMenuNum++;
			m_pMenu = GetMenu();
			m_pMenu = m_pMenu->GetSubMenu(GetPosFromMenu(_T("姓名(&N)")));
			CString strM = dlg.m_sName + _T("...");
			if (MID < MY_ID_MAX) {
				m_pMenu->AppendMenuW(MF_SEPARATOR);
				m_pMenu->AppendMenuW(MF_STRING, MID++, strM);
			}
		}
	}
}


int CMainFrame::GetPosFromMenu(CString target)
{
	CMenu *m_pMainMenu;
	m_pMainMenu = GetMenu();
	CString str;
	int i, pos = -1;
	for (i = m_pMainMenu->GetMenuItemCount() - 1; i >= 0; i--) {
		m_pMainMenu->GetMenuStringW(i, str, MF_BYPOSITION);
		if (str == target) {
			pos = i;
			break;
		}
	}
	return pos;
}
