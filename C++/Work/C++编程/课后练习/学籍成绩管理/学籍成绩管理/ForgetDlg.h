#pragma once


// CForgetDlg 对话框

class CForgetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CForgetDlg)

public:
	CForgetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CForgetDlg();

// 对话框数据
	enum { IDD = IDD_Forget };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString forget_yzout;
	afx_msg void OnBnClickedforgetReturn();
	afx_msg void OnBnClickedforgetChange();
	CString forget_yzin;
	CString forget_username;
};
