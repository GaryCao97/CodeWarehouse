#pragma once


// CMerchNum 对话框

class CMerchNum : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchNum)

public:
	CMerchNum(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMerchNum();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_NUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	long m_llNum;
	CString m_sTag;
	int m_iYear;
	int m_iMonth;
	int m_iDay;
	afx_msg void OnBnClickedOk();
	CString m_sMerchnum;
	CString m_sMerchname;
	CComboBox m_comboMerchkind;
	CString m_sMerchkind;
	CString m_sPrice;
};
