#pragma once


// CForgetDlg �Ի���

class CForgetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CForgetDlg)

public:
	CForgetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CForgetDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sNumber;
	CString m_sPassword1;
	CString m_sPassword2;
	CString m_sYzm1;
	CString m_sYzm2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
