#pragma once
#include "afxcmn.h"


// CMerchSell �Ի���

class CMerchSell : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchSell)

public:
	CMerchSell(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMerchSell();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_SELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listMerch;
	void PaintList();
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnStock();
	afx_msg void OnBnClickedBtnSell();
	afx_msg void OnBnClickedBtnForms();
};
