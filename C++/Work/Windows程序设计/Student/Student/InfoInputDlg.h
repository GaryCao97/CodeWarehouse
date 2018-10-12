#pragma once


// InfoInputDlg 对话框

class InfoInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InfoInputDlg)

public:
	InfoInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InfoInputDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_INPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sName;
	CString m_sNumber;
	CString m_sClass;
	CString m_sPhoto;
	afx_msg void OnBnClickedButtonPhoto();
};
