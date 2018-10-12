#pragma once
#include "afxcmn.h"


// CManaDlg 对话框

class CManaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManaDlg)

public:
	CManaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManaDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANA_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStaff;
	afx_msg void OnBnClickedAddstaff();
	afx_msg void OnBnClickedDelstaff();
	afx_msg void OnLvnItemActivateStafflist(NMHDR *pNMHDR, LRESULT *pResult);
	void PaintList();
	virtual BOOL OnInitDialog();
};
