
// KeyMouseView.cpp : CKeyMouseView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "KeyMouse.h"
#endif

#include "KeyMouseDoc.h"
#include "KeyMouseView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyMouseView

IMPLEMENT_DYNCREATE(CKeyMouseView, CView)

BEGIN_MESSAGE_MAP(CKeyMouseView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CKeyMouseView ����/����

CKeyMouseView::CKeyMouseView()
{
	// TODO: �ڴ˴���ӹ������

}

CKeyMouseView::~CKeyMouseView()
{
}

BOOL CKeyMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CKeyMouseView ����

void CKeyMouseView::OnDraw(CDC* /*pDC*/)
{
	CKeyMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CKeyMouseView ��ӡ

BOOL CKeyMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CKeyMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CKeyMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CKeyMouseView ���

#ifdef _DEBUG
void CKeyMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMouseDoc* CKeyMouseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMouseDoc)));
	return (CKeyMouseDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyMouseView ��Ϣ�������


void CKeyMouseView::OnMouseMove(UINT nFlags, CPoint point)
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


void CKeyMouseView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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
