
// MSDlg.h : ͷ�ļ�
//

#pragma once


// CMSDlg �Ի���
class CMSDlg : public CDialogEx
{
// ����
public:
	CMSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MS_DLG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
	int m_iAdminNum;
	CString *m_sAdminUsername;
	CString *m_sAdminPassword;
	int m_iType;
	afx_msg void OnBnClickedNormal();
	afx_msg void OnBnClickedAdmin();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedForget();
};
