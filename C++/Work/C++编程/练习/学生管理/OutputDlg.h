#pragma once
#include "afxcmn.h"


// COutputDlg �Ի���

class COutputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COutputDlg)

public:
	COutputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COutputDlg();

// �Ի�������
	enum { IDD = IDD_Output };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl output_list;
	afx_msg void OnBnClickedoutputReturn();
};
