#pragma once


// CStaffDlg �Ի���

class CStaffDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffDlg)

public:
	CStaffDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFF_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffinfo();
	afx_msg void OnBnClickedMerchnum();
	afx_msg void OnBnClickedMerchinfo();
};
