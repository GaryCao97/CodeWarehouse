#pragma once


// CCommOutDlg 对话框

class CCommOutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCommOutDlg)

public:
	CCommOutDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommOutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM_OUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sCommName;
	CString m_sCommNum;
	CString m_sCommKind;
	CString m_sSpecifi;
	CString m_sPrice;
	long m_llNum;
	CStatic m_picPhoto;
	int m_iCommPos;
	CString m_sAddress;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	int m_iYear;
	int m_iMouth;
	int m_iDay;
};
