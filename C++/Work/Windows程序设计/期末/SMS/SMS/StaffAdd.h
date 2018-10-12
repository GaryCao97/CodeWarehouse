#pragma once


// CStaffAdd 对话框

class CStaffAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffAdd)

public:
	CStaffAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDSTAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	CString m_sPost;
	CString m_sDuty;
	afx_msg void OnBnClickedOk();
};
