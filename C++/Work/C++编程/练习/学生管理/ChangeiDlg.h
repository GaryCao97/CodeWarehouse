#pragma once
#include "afxcmn.h"


// CChangeiDlg �Ի���

class CChangeiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeiDlg)

public:
	CChangeiDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeiDlg();

// �Ի�������
	enum { IDD = IDD_ChangeI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedchangeiReturn();
	virtual BOOL OnInitDialog();
	CListCtrl changei_list;
	CString changei_class;
	double changei_S1;
	double changei_S2;
	double changei_S3;
	double changei_S4;
	double changei_S5;
	CString changei_name;
	CString changei_number;
	CString changei_school;
	CString changei_teacher;
	void PaintListItem(void);
	afx_msg void OnLvnItemActivatechangeiList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedchangeiChange();
	afx_msg void OnBnClickedchangeiDelete();
};
