
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_POINT,
	ID_INDICATOR_TIME,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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

	// ����һ����ͼ��ռ�ÿ�ܵĹ�����
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("δ�ܴ�����ͼ����\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// ������ʱ������ʱ��IDΪ1����ʱʱ��Ϊ1000ms����1s
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ����ͼ��һ�γ��Ը�����
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString strTime;
	// ��ȡϵͳ��ǰʱ�䣬�����浽curTime   
	CTime curTime = CTime::GetCurrentTime();
	// ��ʽ��curTime�����ַ������浽strTime   
	strTime = curTime.Format(_T("%H:%M:%S"));
	// ��״̬����ʱ�䴰������ʾϵͳʱ���ַ���   
	m_wndStatusBar.SetPaneText(2, strTime);
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnNameZhangsan()
{
	// TODO: �ڴ���������������
	MessageBox(_T("������������"), _T("����"));
	m_bZhangSan = !m_bZhangSan;
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("��̬�˵�װ��ʧ�ܣ�"), _T("����"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString strZS;
	if (m_bZhangSan) {
		strZS = _T("�����Ķ�̬�˵�(&Z)");
		m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, strZS);
		m_addMenu.Detach();
	}
	else {
		for (int i = m_pMainmenu->GetMenuItemCount() - 1; i >= 0; i--) {
			m_pMainmenu->GetMenuStringW(i, strZS, MF_BYPOSITION);
			if (strZS == _T("�����Ķ�̬�˵�(&Z)")) {
				m_pMainmenu->DeleteMenu(i, MF_BYPOSITION);
				break;
			}
		}
	}
	DrawMenuBar();
}

void CMainFrame::OnUpdateNameZhangsan(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bZhangSan);
}

void CMainFrame::OnNameLisi()
{
	// TODO: �ڴ���������������
	MessageBox(_T("�������ģ���"), _T("����"));
	m_bLiSi = !m_bLiSi;
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("��̬�˵�װ��ʧ�ܣ�"), _T("����"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString strZS;
	if (m_bLiSi) {
		strZS = _T("���ĵĶ�̬�˵�(&L)");
		m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, strZS);
		m_addMenu.Detach();
	}
	else {
		for (int i = m_pMainmenu->GetMenuItemCount() - 1; i >= 0; i--) {
			m_pMainmenu->GetMenuStringW(i, strZS, MF_BYPOSITION);
			if (strZS == _T("���ĵĶ�̬�˵�(&L)")) {
				m_pMainmenu->DeleteMenu(i, MF_BYPOSITION);
				break;
			}
		}
	}
	DrawMenuBar();
}

void CMainFrame::OnUpdateNameLisi(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bLiSi);
}

void CMainFrame::OnDynFirst()
{
	// TODO: �ڴ���������������
	MessageBox(_T("��ѡ����first"), _T("first"), MB_OK | MB_ICONQUESTION);
}

void CMainFrame::OnDynSecond()
{
	// TODO: �ڴ���������������
	MessageBox(_T("��ѡ����second"), _T("second"), MB_OK | MB_ICONQUESTION);
}
