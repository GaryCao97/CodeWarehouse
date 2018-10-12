#pragma once


// CForgetDlg 对话框

class CForgetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CForgetDlg)

public:
	CForgetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CForgetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sNumber;
	CString m_sPassword1;
	CString m_sPassword2;
	CString m_sYzm1;
	CString m_sYzm2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
