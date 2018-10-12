
// sy3View.cpp : Csy3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "sy3.h"
#endif

#include "sy3Doc.h"
#include "sy3View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csy3View

IMPLEMENT_DYNCREATE(Csy3View, CView)

BEGIN_MESSAGE_MAP(Csy3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Csy3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Csy3View ����/����

Csy3View::Csy3View()
{
	// TODO: �ڴ˴���ӹ������

}

Csy3View::~Csy3View()
{
}

BOOL Csy3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Csy3View ����

void Csy3View::OnDraw(CDC* /*pDC*/)
{
	Csy3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//CBitmap m_bitmaps_ZHANGSAN, m_bitmaps_LISI;
	//m_bitmaps_ZHANGSAN.LoadBitmap(IDB_ZHANGSAN);
	//m_bitmaps_LISI.LoadBitmap(IDB_LISI);
	//CMenu m_pMainmenu;
	//m_pMainmenu.LoadMenuW(IDR_MAINFRAME);
	//CString str;
	//m_pMainmenu.GetMenuStringW(3, str, MF_BYPOSITION);
	//m_pMainmenu.SetMenuItemBitmaps(ID_NAME_ZHANGSAN, MF_BYCOMMAND, &m_bitmaps_ZHANGSAN, &m_bitmaps_LISI);
	//m_pMainmenu.GetSubMenu(3)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmaps_LISI, &m_bitmaps_LISI);
	//m_pMainmenu.GetSubMenu(3)->GetMenuStringW(0, str, MF_BYPOSITION);
	//MessageBox(str, _T("��ʾ"));
	//m_bitmaps_ZHANGSAN.Detach();
	//m_bitmaps_LISI.Detach();
}


// Csy3View ��ӡ


void Csy3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Csy3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Csy3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Csy3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Csy3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Csy3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Csy3View ���

#ifdef _DEBUG
void Csy3View::AssertValid() const
{
	CView::AssertValid();
}

void Csy3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csy3Doc* Csy3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csy3Doc)));
	return (Csy3Doc*)m_pDocument;
}
#endif //_DEBUG


// Csy3View ��Ϣ�������


void Csy3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString strPoint;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	strPoint.Format(_T("x=%d y=%d"), point.x, point.y);
	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);
	CView::OnMouseMove(nFlags, point);
}
