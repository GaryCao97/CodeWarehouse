#pragma once
#include "afxcmn.h"


// CMerchInfo 对话框

class CMerchInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchInfo)

public:
	CMerchInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMerchInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listMerch;
	void PaintList();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddmerch();
	afx_msg void OnBnClickedChangemerch();
	afx_msg void OnBnClickedDelmerch();
	afx_msg void OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult);
};
