#pragma once
#include "afxcmn.h"


// CSearchDlg 对话框

class CSearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchDlg)

public:
	CSearchDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSearchDlg();

// 对话框数据
	enum { IDD = IDD_Search };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedsearchReturn();
	virtual BOOL OnInitDialog();
	CListCtrl search_list;
	void PaintListItem(void);
	afx_msg void OnBnClickedsearchname();
	afx_msg void OnBnClickedsearchnumber();
	afx_msg void OnBnClickedsearchschool();
	afx_msg void OnBnClickedsearchclass();
	afx_msg void OnBnClickedsearchteacher();
	afx_msg void OnBnClickedsearchlesson1();
	afx_msg void OnBnClickedsearchlesson2();
	afx_msg void OnBnClickedsearchlesson3();
	afx_msg void OnBnClickedsearchlesson4();
	afx_msg void OnBnClickedsearchlesson5();
	afx_msg void OnBnClickedsearchlessonsum();
	afx_msg void OnBnClickedsearchlessonaver();
	CString search_edit;
};
