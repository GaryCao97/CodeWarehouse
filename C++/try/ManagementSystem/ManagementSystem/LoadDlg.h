#pragma once


// CLoadDlg �Ի���

class CLoadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoadDlg)

public:
	CLoadDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoadDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	int m_iType;
	afx_msg void OnBnClickedNormal();
	afx_msg void OnBnClickedAdmin();
	afx_msg void OnBnClickedOk();
};
