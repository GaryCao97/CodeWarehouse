#pragma once
#include "afxcmn.h"


// COutputDlg 对话框

class COutputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COutputDlg)

public:
	COutputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COutputDlg();

// 对话框数据
	enum { IDD = IDD_Output };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl output_list;
	afx_msg void OnBnClickedoutputReturn();
};
