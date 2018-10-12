
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


