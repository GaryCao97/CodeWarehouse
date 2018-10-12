#pragma once


// CLoadDlg 对话框

class CLoadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoadDlg)

public:
	CLoadDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoadDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	int m_iType;
	afx_msg void OnBnClickedNormal();
	afx_msg void OnBnClickedAdmin();
	afx_msg void OnBnClickedOk();
};
