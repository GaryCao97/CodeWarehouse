#pragma once
#include "afxwin.h"


// CMerchOne 对话框

class CMerchOne : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchOne)

public:
	CMerchOne(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMerchOne();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_ONE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sIntroduct;
	CComboBox m_comboMerchkind;
	CString m_sMerchkind;
	CString m_sMerchname;
	CString m_sMerchnum;
	CString m_sPrice;
	bool m_bIsAdd;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
