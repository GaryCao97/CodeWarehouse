
// MouseKeyView.cpp : CMouseKeyView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MouseKey.h"
#endif

#include "MouseKeyDoc.h"
#include "MouseKeyView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseKeyView

IMPLEMENT_DYNCREATE(CMouseKeyView, CView)

BEGIN_MESSAGE_MAP(CMouseKeyView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMouseKeyView ����/����

CMouseKeyView::CMouseKeyView()
{
	// TODO: �ڴ˴���ӹ������

}

CMouseKeyView::~CMouseKeyView()
{
}

BOOL CMouseKeyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMouseKeyView ����

void CMouseKeyView::OnDraw(CDC* /*pDC*/)
{
	CMouseKeyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMouseKeyView ��ӡ

BOOL CMouseKeyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMouseKeyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMouseKeyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMouseKeyView ���

#ifdef _DEBUG
void CMouseKeyView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseKeyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseKeyDoc* CMouseKeyView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseKeyDoc)));
	return (CMouseKeyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseKeyView ��Ϣ�������


void CMouseKeyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	POINT p;
	GetCursorPos(&p);
	int iStepLen = 1;
	if (GetKeyState(VK_SHIFT) & 1 << 15) iStepLen = 5;
	if (GetKeyState(VK_CONTROL) & 1 << 15) iStepLen = 10;
	switch (nChar) { // �ж��û����� 
	case VK_UP:
		p.y -= iStepLen;
		break;
	case VK_DOWN:
		p.y += iStepLen;
		break;
	case VK_LEFT:
		p.x -= iStepLen;
		break;
	case VK_RIGHT:
		p.x += iStepLen;
		break;
	}
	SetCursorPos(p.x, p.y);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMouseKeyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString strPoint;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	strPoint.Format(_T("x=%d"), point.x);
	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);
	strPoint.Format(_T("y=%d"), point.y);
	pFrame->m_wndStatusBar.SetPaneText(2, strPoint);

	SetCursor(LoadCursor(NULL, IDC_CROSS));
	CView::OnMouseMove(nFlags, point);
}
