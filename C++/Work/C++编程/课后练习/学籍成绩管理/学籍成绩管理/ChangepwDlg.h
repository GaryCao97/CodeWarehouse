#pragma once


// CChangepwDlg �Ի���

class CChangepwDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangepwDlg)

public:
	CChangepwDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangepwDlg();

// �Ի�������
	enum { IDD = IDD_ChangePw };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedchangepwReturn();
	CString pw_old;
	CString pw_new1;
	CString pw_new2;
	afx_msg void OnBnClickedchangepwSure();
};
