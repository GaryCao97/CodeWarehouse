
// KeyMouseView.cpp : CKeyMouseView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CKeyMouseView 构造/析构

CKeyMouseView::CKeyMouseView()
{
	// TODO: 在此处添加构造代码

}

CKeyMouseView::~CKeyMouseView()
{
}

BOOL CKeyMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CKeyMouseView 绘制

void CKeyMouseView::OnDraw(CDC* /*pDC*/)
{
	CKeyMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CKeyMouseView 打印

BOOL CKeyMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CKeyMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CKeyMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CKeyMouseView 诊断

#ifdef _DEBUG
void CKeyMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMouseDoc* CKeyMouseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMouseDoc)));
	return (CKeyMouseDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyMouseView 消息处理程序


void CKeyMouseView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	POINT p;
	GetCursorPos(&p);
	int iStepLen = 1;
	if (GetKeyState(VK_SHIFT) & 1 << 15) iStepLen = 5;
	if (GetKeyState(VK_CONTROL) & 1 << 15) iStepLen = 10;
	switch (nChar) { // 判断用户按键 
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
