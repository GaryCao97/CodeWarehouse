
// SMSDlg.h : ͷ�ļ�
//

#pragma once


// CSMSDlg �Ի���
class CSMSDlg : public CDialogEx
{
// ����
public:
	CSMSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMS_DIALOG };
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
	afx_msg void OnStnClickedForget();
	afx_msg void OnBnClickedLoginStaff();
	afx_msg void OnBnClickedLoginAdmin();
};
