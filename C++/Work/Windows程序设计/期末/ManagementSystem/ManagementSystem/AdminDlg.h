#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CAdminDlg �Ի���

class CAdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMIN_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
