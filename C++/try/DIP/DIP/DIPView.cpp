
// DIPView.cpp: CDIPView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DIP.h"
#endif

#include "DIPDoc.h"
#include "DIPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDIPView

IMPLEMENT_DYNCREATE(CDIPView, CScrollView)

BEGIN_MESSAGE_MAP(CDIPView, CScrollView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDIPView 构造/析构

CDIPView::CDIPView()
{
	// TODO: 在此处添加构造代码

}

CDIPView::~CDIPView()
{
}

BOOL CDIPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDIPView 绘图

void CDIPView::OnDraw(CDC* pDC)
{
	CDIPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (!pDoc->m_sImage.IsNull())
		pDoc->m_sImage.Draw(pDC->m_hDC, 0, 0);
	if (!pDoc->m_rImage.IsNull())
		pDoc->m_rImage.Draw(pDC->m_hDC, pDoc->m_sImage.GetWidth() + 10, 0);

	CSize sizeTotal;
	sizeTotal.cx = (pDoc->m_sImage.IsNull() ? 100 : pDoc->m_sImage.GetWidth()) + (pDoc->m_rImage.IsNull() ? 100 : pDoc->m_rImage.GetWidth()) + 10;
	sizeTotal.cy = (pDoc->m_sImage.IsNull() ? 100 : pDoc->m_sImage.GetHeight());
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDIPView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDIPView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDIPView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDIPView 诊断

#ifdef _DEBUG
void CDIPView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDIPView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDIPDoc* CDIPView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDIPDoc)));
	return (CDIPDoc*)m_pDocument;
}
#endif //_DEBUG


// CDIPView 消息处理程序
