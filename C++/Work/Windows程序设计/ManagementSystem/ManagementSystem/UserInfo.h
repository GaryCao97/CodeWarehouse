#pragma once


// CUserInfo �Ի���

class CUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInfo)

public:
	CUserInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_sUsername;
	CString m_sNumber;
	CString m_sKind;
	CString m_sDuty;
	CString m_sYzm1;
	CString m_sYzm2;
	int m_iStyle;
	CString m_sRealName;
	bool m_bNorA;// true����N,false����A
};
