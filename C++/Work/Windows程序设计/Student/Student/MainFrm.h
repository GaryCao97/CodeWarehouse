
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CChildView    m_wndView;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	CStatusBar        m_wndStatusBar;
	CBitmap m_bitmaps_ZHANGSAN1;
	CBitmap m_bitmaps_LISI1;
	CBitmap m_bitmaps_ZHANGSAN2;
	CBitmap m_bitmaps_LISI2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDynFirst();
	afx_msg void OnDynSecond();
	afx_msg void OnDynAdd();
	afx_msg void OnDynDelete();
	afx_msg void OnNameLisi();
	afx_msg void OnUpdateNameLisi(CCmdUI *pCmdUI);
	afx_msg void OnNameZhangsan();
	afx_msg void OnUpdateNameZhangsan(CCmdUI *pCmdUI);
	afx_msg void OnScoreScore();
	afx_msg void OnInputInfo();
	afx_msg void OnCommandRange(UINT nID);
	CString m_sName[104];
	CString m_sNumber[104];
	CString m_sClass[104];
	CString m_sPhoto[104];
	bool m_bZhangSan;
	bool m_bLiSi;
	int m_iAnal;
	int m_iAlge;
	int m_iProb;
	int m_iProg;
	int m_iData;
	int m_iOrga;
	int m_iPoli;
	int m_iEngl;
	int m_iPhys;
	int newMenuNum;
	UINT MID;
	int GetPosFromMenu(CString target);
};


