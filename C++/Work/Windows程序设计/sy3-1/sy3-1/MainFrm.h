
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CChildView    m_wndView;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	CStatusBar        m_wndStatusBar;
	bool m_bZhangSan;
	bool m_bLiSi;
	CBitmap m_bitmaps_ZHANGSAN1;
	CBitmap m_bitmaps_LISI1;
	CBitmap m_bitmaps_ZHANGSAN2;
	CBitmap m_bitmaps_LISI2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNameZhangsan();
	afx_msg void OnUpdateNameZhangsan(CCmdUI *pCmdUI);
	afx_msg void OnNameLisi();
	afx_msg void OnUpdateNameLisi(CCmdUI *pCmdUI);
	afx_msg void OnDynFirst();
	afx_msg void OnDynSecond();
};


