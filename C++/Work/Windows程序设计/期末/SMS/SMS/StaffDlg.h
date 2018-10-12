#pragma once


// CStaffDlg 对话框

class CStaffDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffDlg)

public:
	CStaffDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFF_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffinfo();
	afx_msg void OnBnClickedMerchnum();
	afx_msg void OnBnClickedMerchinfo();
};
