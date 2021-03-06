
// DigitalImageProcessingView.cpp: CDigitalImageProcessingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DigitalImageProcessing.h"
#endif

#include "DigitalImageProcessingDoc.h"
#include "DigitalImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDigitalImageProcessingView

IMPLEMENT_DYNCREATE(CDigitalImageProcessingView, CScrollView)

BEGIN_MESSAGE_MAP(CDigitalImageProcessingView, CScrollView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDigitalImageProcessingView 构造/析构

CDigitalImageProcessingView::CDigitalImageProcessingView()
{
	// TODO: 在此处添加构造代码

}

CDigitalImageProcessingView::~CDigitalImageProcessingView()
{
}

BOOL CDigitalImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDigitalImageProcessingView 绘图

void CDigitalImageProcessingView::OnDraw(CDC* pDC)
{
	CDigitalImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (!pDoc->m_sImage.IsNull())
		pDoc->m_sImage.Draw(pDC->m_hDC, 0, 0);
	if (!pDoc->m_rImage.IsNull())
		pDoc->m_rImage.Draw(pDC->m_hDC, pDoc->m_sImage.GetWidth() + 10, 0);
	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	if (!pDoc->m_sImage.IsNull()) {
		sizeTotal.cx = pDoc->m_sImage.GetWidth();
		sizeTotal.cy = pDoc->m_sImage.GetHeight();
		if (!pDoc->m_rImage.IsNull()) {
			sizeTotal.cx += pDoc->m_rImage.GetWidth() + 10;
			sizeTotal.cy = (pDoc->m_sImage.GetHeight() > pDoc->m_rImage.GetHeight()) ? pDoc->m_sImage.GetHeight() : pDoc->m_rImage.GetHeight();
		}
	}
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDigitalImageProcessingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDigitalImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDigitalImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDigitalImageProcessingView 诊断

#ifdef _DEBUG
void CDigitalImageProcessingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDigitalImageProcessingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDigitalImageProcessingDoc* CDigitalImageProcessingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDigitalImageProcessingDoc)));
	return (CDigitalImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDigitalImageProcessingView 消息处理程序
