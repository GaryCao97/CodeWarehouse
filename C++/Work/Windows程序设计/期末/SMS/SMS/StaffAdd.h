#pragma once


// CStaffAdd �Ի���

class CStaffAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffAdd)

public:
	CStaffAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDSTAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	CString m_sPost;
	CString m_sDuty;
	afx_msg void OnBnClickedOk();
};
