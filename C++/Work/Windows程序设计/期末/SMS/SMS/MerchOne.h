#pragma once
#include "afxwin.h"


// CMerchOne �Ի���

class CMerchOne : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchOne)

public:
	CMerchOne(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMerchOne();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_ONE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
