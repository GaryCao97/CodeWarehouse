#pragma once


// CForgetDlg �Ի���

class CForgetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CForgetDlg)

public:
	CForgetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CForgetDlg();

// �Ի�������
	enum { IDD = IDD_Forget };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString forget_yzout;
	afx_msg void OnBnClickedforgetReturn();
	afx_msg void OnBnClickedforgetChange();
	CString forget_yzin;
	CString forget_username;
};
