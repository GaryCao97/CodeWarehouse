
// KeyMouseView.h : CKeyMouseView 类的接口
//

#pragma once


class CKeyMouseView : public CView
{
protected: // 仅从序列化创建
	CKeyMouseView();
	DECLARE_DYNCREATE(CKeyMouseView)

// 特性
public:
	CKeyMouseDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CKeyMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // KeyMouseView.cpp 中的调试版本
inline CKeyMouseDoc* CKeyMouseView::GetDocument() const
   { return reinterpret_cast<CKeyMouseDoc*>(m_pDocument); }
#endif

