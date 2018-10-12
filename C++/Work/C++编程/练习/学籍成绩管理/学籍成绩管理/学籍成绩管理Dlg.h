
// 学籍成绩管理Dlg.h : 头文件
//

#pragma once


// CLoadDlg 对话框
class CLoadDlg : public CDialogEx
{
// 构造
public:
	CLoadDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_Loading };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString load_username;
	CString load_password;
	afx_msg void OnBnClickedloadLogin();
	afx_msg void OnBnClickedloadRegister();
	afx_msg void OnBnClickedButton1();
};
