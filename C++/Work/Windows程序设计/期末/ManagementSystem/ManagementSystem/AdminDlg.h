#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CAdminDlg 对话框

class CAdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMIN_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUserAdd();
	afx_msg void OnBnClickedUserChange();
	afx_msg void OnBnClickedUserDelete();
	afx_msg void OnBnClickedSearchBtn();
	CListCtrl UserList;
	virtual BOOL OnInitDialog();
	void PaintListItem();
	int m_iUserPos;
	afx_msg void OnItemactivateUserlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickUserlist(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_comboSearch;
	CString m_sSearch;
};
