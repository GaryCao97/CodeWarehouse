
// DrawView.cpp : CDrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
//	ON_WM_SIZING()
END_MESSAGE_MAP()

// CDrawView 构造/析构

CDrawView::CDrawView()
	: m_iW(0)
	, m_iH(0)
{
	// TODO: 在此处添加构造代码
	m_bLButtonDown = FALSE;
	m_bErase = FALSE;
	pGrayPen = new CPen(PS_DOT, 0, RGB(128, 128, 128));
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘制

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CDrawView 打印

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	m_bLButtonDown = TRUE;
	p0 = point;
	pm = p0;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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

	// TODO: 在此处添加消息处理程序代码
	m_iW = cx;
	m_iH = cy;
}
