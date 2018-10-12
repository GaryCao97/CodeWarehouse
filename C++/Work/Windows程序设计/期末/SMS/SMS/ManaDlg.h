#pragma once
#include "afxcmn.h"


// CManaDlg �Ի���

class CManaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManaDlg)

public:
	CManaDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManaDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANA_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStaff;
	afx_msg void OnBnClickedAddstaff();
	afx_msg void OnBnClickedDelstaff();
	afx_msg void OnLvnItemActivateStafflist(NMHDR *pNMHDR, LRESULT *pResult);
	void PaintList();
	virtual BOOL OnInitDialog();
};
