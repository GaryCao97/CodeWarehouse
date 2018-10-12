#pragma once


// CChangepwDlg 对话框

class CChangepwDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangepwDlg)

public:
	CChangepwDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangepwDlg();

// 对话框数据
	enum { IDD = IDD_ChangePw };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedchangepwReturn();
	CString pw_old;
	CString pw_new1;
	CString pw_new2;
	afx_msg void OnBnClickedchangepwSure();
};
