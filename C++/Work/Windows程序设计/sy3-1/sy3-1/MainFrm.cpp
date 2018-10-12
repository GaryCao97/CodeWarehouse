
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "sy3-1.h"

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
	ON_COMMAND(ID_NAME_ZHANGSAN, &CMainFrame::OnNameZhangsan)
	ON_UPDATE_COMMAND_UI(ID_NAME_ZHANGSAN, &CMainFrame::OnUpdateNameZhangsan)
	ON_COMMAND(ID_NAME_LISI, &CMainFrame::OnNameLisi)
	ON_UPDATE_COMMAND_UI(ID_NAME_LISI, &CMainFrame::OnUpdateNameLisi)
	ON_COMMAND(ID_DYN_FIRST, &CMainFrame::OnDynFirst)
	ON_COMMAND(ID_DYN_SECOND, &CMainFrame::OnDynSecond)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
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
	m_wndStatusBar.SetPaneText(2, strTime);
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnNameZhangsan()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("这是张三！！"), _T("张三"));
	m_bZhangSan = !m_bZhangSan;
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("动态菜单装载失败！"), _T("错误"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString strZS;
	if (m_bZhangSan) {
		strZS = _T("张三的动态菜单(&Z)");
		m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, strZS);
		m_addMenu.Detach();
	}
	else {
		for (int i = m_pMainmenu->GetMenuItemCount() - 1; i >= 0; i--) {
			m_pMainmenu->GetMenuStringW(i, strZS, MF_BYPOSITION);
			if (strZS == _T("张三的动态菜单(&Z)")) {
				m_pMainmenu->DeleteMenu(i, MF_BYPOSITION);
				break;
			}
		}
	}
	DrawMenuBar();
}

void CMainFrame::OnUpdateNameZhangsan(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bZhangSan);
}

void CMainFrame::OnNameLisi()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("这是李四！！"), _T("李四"));
	m_bLiSi = !m_bLiSi;
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("动态菜单装载失败！"), _T("错误"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString strZS;
	if (m_bLiSi) {
		strZS = _T("李四的动态菜单(&L)");
		m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, strZS);
		m_addMenu.Detach();
	}
	else {
		for (int i = m_pMainmenu->GetMenuItemCount() - 1; i >= 0; i--) {
			m_pMainmenu->GetMenuStringW(i, strZS, MF_BYPOSITION);
			if (strZS == _T("李四的动态菜单(&L)")) {
				m_pMainmenu->DeleteMenu(i, MF_BYPOSITION);
				break;
			}
		}
	}
	DrawMenuBar();
}

void CMainFrame::OnUpdateNameLisi(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bLiSi);
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
