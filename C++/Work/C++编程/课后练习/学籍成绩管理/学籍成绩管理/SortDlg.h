#pragma once
#include "afxcmn.h"


// CSortDlg �Ի���

class CSortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSortDlg)

public:
	CSortDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSortDlg();

// �Ի�������
	enum { IDD = IDD_Sort };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedsortReturn();
	CListCtrl sort_list;
	void PaintListItem(void);
	afx_msg void OnBnClickedsortname();
	afx_msg void OnBnClickedsortnumber();
	afx_msg void OnBnClickedsortschool();
	afx_msg void OnBnClickedsortclass();
	afx_msg void OnBnClickedsortTeacher();
	afx_msg void OnBnClickedsortlesson1();
	afx_msg void OnBnClickedsortlesson2();
	afx_msg void OnBnClickedsortlesson3();
	afx_msg void OnBnClickedsortlesson4();
	afx_msg void OnBnClickedsortlesson5();
	afx_msg void OnBnClickedsortlessonsum();
	afx_msg void OnBnClickedsortlessonaver();
};
