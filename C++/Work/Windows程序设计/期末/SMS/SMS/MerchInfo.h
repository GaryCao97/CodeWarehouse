#pragma once
#include "afxcmn.h"


// CMerchInfo �Ի���

class CMerchInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CMerchInfo)

public:
	CMerchInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMerchInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERCH_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listMerch;
	void PaintList();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddmerch();
	afx_msg void OnBnClickedChangemerch();
	afx_msg void OnBnClickedDelmerch();
	afx_msg void OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult);
};
