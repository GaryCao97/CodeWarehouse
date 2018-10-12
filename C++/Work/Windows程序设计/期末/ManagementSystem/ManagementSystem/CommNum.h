#pragma once
#include "afxwin.h"


// CCommNum 对话框

class CCommNum : public CDialogEx
{
	DECLARE_DYNAMIC(CCommNum)

public:
	CCommNum(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommNum();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM_NUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int *col;
	CComboBox m_comboSearch;
	CString m_sSearch;
	CListCtrl CommList;
	afx_msg void OnBnClickedSearchBtn();
	void PaintListItem();
	virtual BOOL OnInitDialog();
	afx_msg void OnColumnclickCommlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedIncomm();
	afx_msg void OnBnClickedOutcomm();
	int m_iUserPos;
	int m_iCommPos;
	afx_msg void OnItemactivateCommlist(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_sUserKind;
	afx_msg void OnClickedInventory();
};
