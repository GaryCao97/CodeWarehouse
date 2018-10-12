#pragma once
#include "afxcmn.h"


// CChangeiDlg 对话框

class CChangeiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeiDlg)

public:
	CChangeiDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeiDlg();

// 对话框数据
	enum { IDD = IDD_ChangeI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedchangeiReturn();
	virtual BOOL OnInitDialog();
	CListCtrl changei_list;
	CString changei_class;
	double changei_S1;
	double changei_S2;
	double changei_S3;
	double changei_S4;
	double changei_S5;
	CString changei_name;
	CString changei_number;
	CString changei_school;
	CString changei_teacher;
	void PaintListItem(void);
	afx_msg void OnLvnItemActivatechangeiList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedchangeiChange();
	afx_msg void OnBnClickedchangeiDelete();
};
