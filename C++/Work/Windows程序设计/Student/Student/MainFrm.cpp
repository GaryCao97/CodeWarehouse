
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_POINT,
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
	m_wndStatusBar.SetPaneText(3, strTime);
	CFrameWnd::OnTimer(nIDEvent);
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


void CMainFrame::OnDynAdd()
{
	// TODO: �ڴ���������������
	CMenu m_addMenu, *m_pMainmenu;
	if (!m_addMenu.LoadMenuW(IDR_DYN)) {
		MessageBox(_T("��̬�˵�װ��ʧ�ܣ�"), _T("����"));
		return;
	}
	m_pMainmenu = GetMenu();
	CString str;
	str = _T("�ҵĶ�̬�˵�(&M)");
	m_pMainmenu->InsertMenuW(4, MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT)m_addMenu.GetSubMenu(0)->m_hMenu, str);
	m_addMenu.Detach();
	DrawMenuBar();
}


void CMainFrame::OnDynDelete()
{
	// TODO: �ڴ���������������
	CMenu *m_pMainmenu;
	m_pMainmenu = GetMenu();
	int position = GetPosFromMenu(_T("�ҵĶ�̬�˵�(&M)"));
	if (position >= 0) m_pMainmenu->DeleteMenu(position, MF_BYPOSITION);
	DrawMenuBar();
}



void CMainFrame::OnNameLisi()
{
	// TODO: �ڴ���������������
	m_bLiSi = !m_bLiSi;
	if (m_bLiSi) {
		if (CTaskDialog::IsSupported()) {
			CTaskDialog taskDlg(_T(""), _T(""), _T(""));
			// ��������Ի������ͼ��
			taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetWindowTitle(_T("ѧ����Ϣ"));
			taskDlg.SetMainInstruction(_T("����������"));
			taskDlg.SetContent(_T("ѧ�ţ�") + m_sNumber[1] + _T("\n�༶��") + m_sClass[1] + _T("\nͼƬ��ַ��") + m_sPhoto[1]);
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
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bLiSi);
}


void CMainFrame::OnNameZhangsan()
{
	// TODO: �ڴ���������������
	m_bZhangSan = !m_bZhangSan;
	if (m_bZhangSan) {
		if (CTaskDialog::IsSupported()) {
			CTaskDialog taskDlg(_T(""), _T(""), _T(""));
			// ��������Ի������ͼ��
			taskDlg.SetMainIcon(MAKEINTRESOURCE(IDI_INFORMATION));
			taskDlg.SetWindowTitle(_T("ѧ����Ϣ"));
			taskDlg.SetMainInstruction(_T("����������"));
			taskDlg.SetContent(_T("ѧ�ţ�") + m_sNumber[0] + _T("\n�༶��") + m_sClass[0] + _T("\nͼƬ��ַ��") + m_sPhoto[0]);
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
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bZhangSan);
}


void CMainFrame::OnScoreScore()
{
	// TODO: �ڴ���������������
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
	CPropertySheet ps(_T("�γ̳ɼ�"));
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
			taskDlg.SetWindowTitle(_T("ѧ����Ϣ"));
			taskDlg.SetMainInstruction(_T("������") + m_sName[nNumFromId]);
			taskDlg.SetContent(_T("ѧ�ţ�") + m_sNumber[nNumFromId] + _T("\n�༶��") + m_sClass[nNumFromId] + _T("\nͼƬ��ַ��") + m_sPhoto[nNumFromId]);
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
	// TODO: �ڴ���������������
	InfoInputDlg dlg;
	int pos = -1;
	if (dlg.DoModal() == IDOK) {
		CMenu *m_pMenu;
		m_pMenu = GetMenu();
		m_pMenu = m_pMenu->GetSubMenu(GetPosFromMenu(_T("����(&N)")));
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
			m_pMenu = m_pMenu->GetSubMenu(GetPosFromMenu(_T("����(&N)")));
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
