#pragma once
#include "afxcmn.h"


// CBlog �Ի���

class CBlog : public CDialogEx
{
	DECLARE_DYNAMIC(CBlog)

public:
	CBlog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlog();

// �Ի�������
	enum { IDD = IDD_BLOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listBlog;
	CString m_sBLOG;
	int m_iCommPos;
	virtual BOOL OnInitDialog();
	void PaintList(CStringArray* sa);
	CStringArray* strArr;
	int m_iDate;
	CStringArray* GetDateArray(CStringArray* Source);
	int m_iYear;
	int m_iMouth;
	int m_iDay;
	void OnBnClickedReset();
	afx_msg void OnEnChangeYear();
	afx_msg void OnEnChangeMouth();
	afx_msg void OnEnChangeDay();
};
