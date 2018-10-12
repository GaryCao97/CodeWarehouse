#pragma once
#include "afxcmn.h"


// CUserMana �Ի���

class CUserMana : public CDialogEx
{
	DECLARE_DYNAMIC(CUserMana)

public:
	CUserMana(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserMana();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
