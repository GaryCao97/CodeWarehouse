#pragma once


// CResetDlg 对话框

class CResetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResetDlg)

public:
	CResetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CResetDlg();

// 对话框数据
	enum { IDD = IDD_Forget_Reset };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedresetOk();
	CString reset_password1;
	CString reset_password2;
	CString reset_safea;
	CString reset_safeq;
	CString reset_username;
	CString reset_yzin;
	CString reset_yzout;
};
