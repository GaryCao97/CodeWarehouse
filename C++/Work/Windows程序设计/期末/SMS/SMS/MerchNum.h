#pragma once


// CMerchNum �Ի���

class CMerchNum : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchNum)

public:
	CMerchNum(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMerchNum();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_NUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
