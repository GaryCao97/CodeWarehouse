#pragma once


// CNormalDlg �Ի���

class CNormalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNormalDlg)

public:
	CNormalDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNormalDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NORMAL_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUser;
	CString m_sUserNumber;
	CString m_sUserKind;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnUser();
	afx_msg void OnBnClickedBtnComm();
	afx_msg void OnBnClickedBtnNum();
	int m_iUserPos;
};
