#pragma once
#include "afxwin.h"


// CCommInDlg �Ի���

class CCommInDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCommInDlg)

public:
	CCommInDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommInDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM_IN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
