#pragma once


// InfoInputDlg �Ի���

class InfoInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InfoInputDlg)

public:
	InfoInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InfoInputDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_INPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sName;
	CString m_sNumber;
	CString m_sClass;
	CString m_sPhoto;
	afx_msg void OnBnClickedButtonPhoto();
};
