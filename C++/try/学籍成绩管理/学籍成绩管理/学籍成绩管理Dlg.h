
// ѧ���ɼ�����Dlg.h : ͷ�ļ�
//

#pragma once


// CLoadDlg �Ի���
class CLoadDlg : public CDialogEx
{
// ����
public:
	CLoadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_Loading };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString load_username;
	CString load_password;
	afx_msg void OnBnClickedloadLogin();
	afx_msg void OnBnClickedloadRegister();
	afx_msg void OnBnClickedButton1();
};
