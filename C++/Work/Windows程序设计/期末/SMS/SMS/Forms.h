#pragma once
#include "afxcmn.h"


// CForms �Ի���

class CForms : public CDialogEx
{
	DECLARE_DYNAMIC(CForms)

public:
	CForms(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CForms();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listForms;
	int m_iType;
	int m_iYear;
	int m_iMonth;
	int m_iDay;
	afx_msg void OnBnClickedBymouth();
	afx_msg void OnBnClickedByday();
	virtual BOOL OnInitDialog();
	void PaintList(CStringArray* sa);
	CStringArray* GetDateArrayByDay(CStringArray* Source);
	CStringArray* GetDateArrayByMonth(CStringArray* Source);
	afx_msg void OnEnChangeYear();
	afx_msg void OnEnChangeMonth();
	afx_msg void OnEnChangeDay();
	bool isFirst;
};
