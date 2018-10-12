#pragma once


// CStartDlg 对话框

class CStartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStartDlg)

public:
	CStartDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStartDlg();

// 对话框数据
	enum { IDD = IDD_Start };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedstartRestart();
	afx_msg void OnBnClickedstartInputi();
	afx_msg void OnBnClickedstartChangei();
	afx_msg void OnBnClickedstartOutputi();
	afx_msg void OnBnClickedstartSorti();
	afx_msg void OnBnClickedstartSearchi();
	afx_msg void OnBnClickedstartChangepw();
};
