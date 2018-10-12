
// sy3View.cpp : Csy3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Csy3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Csy3View 构造/析构

Csy3View::Csy3View()
{
	// TODO: 在此处添加构造代码

}

Csy3View::~Csy3View()
{
}

BOOL Csy3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Csy3View 绘制

void Csy3View::OnDraw(CDC* /*pDC*/)
{
	Csy3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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
	//MessageBox(str, _T("提示"));
	//m_bitmaps_ZHANGSAN.Detach();
	//m_bitmaps_LISI.Detach();
}


// Csy3View 打印


void Csy3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Csy3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Csy3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Csy3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// Csy3View 诊断

#ifdef _DEBUG
void Csy3View::AssertValid() const
{
	CView::AssertValid();
}

void Csy3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csy3Doc* Csy3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csy3Doc)));
	return (Csy3Doc*)m_pDocument;
}
#endif //_DEBUG


// Csy3View 消息处理程序


void Csy3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString strPoint;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	strPoint.Format(_T("x=%d y=%d"), point.x, point.y);
	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);
	CView::OnMouseMove(nFlags, point);
}
