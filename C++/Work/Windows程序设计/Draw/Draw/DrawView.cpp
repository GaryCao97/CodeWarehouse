
// DrawView.cpp : CDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
//	ON_WM_SIZING()
END_MESSAGE_MAP()

// CDrawView ����/����

CDrawView::CDrawView()
	: m_iW(0)
	, m_iH(0)
{
	// TODO: �ڴ˴���ӹ������
	m_bLButtonDown = FALSE;
	m_bErase = FALSE;
	pGrayPen = new CPen(PS_DOT, 0, RGB(128, 128, 128));
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawView ����

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC *pdc = GetDC();
	CPen pen(PS_SOLID, 10, RGB(rand() % 256, rand() % 256, rand() % 256));
	CBrush brush(RGB(rand() % 256, rand() % 256, rand() % 256));
	pdc->SelectObject(pen);
	pdc->SelectObject(&brush);
	pdc->SetROP2(R2_COPYPEN);
	pdc->SetBkMode(TRANSPARENT);
	pdc->Ellipse(0, 0, m_iW, m_iH);
	ReleaseDC(pdc);
}


// CDrawView ��ӡ

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawView ���

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView ��Ϣ�������


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();
	m_bLButtonDown = TRUE;
	p0 = point;
	pm = p0;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCursor(LoadCursor(NULL, IDC_CROSS));
	if (m_bLButtonDown) {
		CDC *pDC = GetDC();
		pDC->SelectObject(pGrayPen);
		pDC->SetROP2(R2_XORPEN);
		pDC->SetBkMode(TRANSPARENT);
		//pDC->SelectStockObject(NULL_BRUSH);
		if (m_bErase) {
			pDC->MoveTo(p0);
			pDC->LineTo(pm);
		}
		else
			m_bErase = TRUE;
		pDC->MoveTo(p0);
		pDC->LineTo(pm);
		pm = point;
		ReleaseDC(pDC);
	}
	CView::OnMouseMove(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ReleaseCapture();
	if (m_bLButtonDown) {
		CDC *pDC = GetDC();
		pDC->SelectObject(pGrayPen);
		pDC->SetROP2(R2_XORPEN);
		pDC->SetBkMode(TRANSPARENT);
		//pDC->SelectStockObject(NULL_BRUSH);
		pDC->MoveTo(p0);
		pDC->LineTo(pm);
		pLinePen = new CPen(PS_SOLID, 10, RGB(rand() % 256, rand() % 256, rand() % 256));
		pDC->SelectObject(pLinePen);
		pDC->SetROP2(R2_COPYPEN);
		pDC->MoveTo(p0);
		pDC->LineTo(pm);
		m_bLButtonDown = FALSE;
		m_bErase = FALSE;
		ReleaseDC(pDC);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CDrawView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	m_iW = cx;
	m_iH = cy;
}
