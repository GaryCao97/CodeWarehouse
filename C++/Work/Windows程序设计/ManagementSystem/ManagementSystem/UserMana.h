#pragma once
#include "afxcmn.h"


// CUserMana 对话框

class CUserMana : public CDialogEx
{
	DECLARE_DYNAMIC(CUserMana)

public:
	CUserMana(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserMana();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl UserList;
	void PaintListItem();
	virtual BOOL OnInitDialog();
	int m_iUserPos;
	afx_msg void OnItemactivateUserlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickUserlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnChange();
	CString m_sUser;
};
