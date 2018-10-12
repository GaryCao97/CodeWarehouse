#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCommDlg 对话框

class CCommDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCommDlg)

public:
	CCommDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboSearch;
	CString m_sSearch;
	CListCtrl CommList;
	void PaintListItem();
	virtual BOOL OnInitDialog();
	int m_iCommPos;
	afx_msg void OnItemactivateCommlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickCommlist(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_sUserKind;
	afx_msg void OnBnClickedSearchBtn();
	afx_msg void OnBnClickedCommAdd();
	afx_msg void OnBnClickedCommChange();
	afx_msg void OnBnClickedCommDelete();
	int m_iUserPos;
};
