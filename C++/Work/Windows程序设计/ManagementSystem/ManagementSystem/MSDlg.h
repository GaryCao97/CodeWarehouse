
// MSDlg.h : 头文件
//

#pragma once


// CMSDlg 对话框
class CMSDlg : public CDialogEx
{
// 构造
public:
	CMSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MS_DLG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	int m_iAdminNum;
	CString *m_sAdminUsername;
	CString *m_sAdminPassword;
	int m_iType;
	afx_msg void OnBnClickedNormal();
	afx_msg void OnBnClickedAdmin();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedForget();
};
