#pragma once


// CRegisterDlg �Ի���

class CRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDlg)

public:
	CRegisterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterDlg();

// �Ի�������
	enum { IDD = IDD_Register };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString register_password1;
	CString register_password2;
	CString register_safea;
	CString register_safeq;
	CString register_username;
	CString register_yzin;
	CString register_yzout;
	afx_msg void OnBnClickedregisterRegister();
	virtual BOOL OnInitDialog();
};
