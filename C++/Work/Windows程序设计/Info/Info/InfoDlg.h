
// InfoDlg.h : ͷ�ļ�
//

#pragma once


// CInfoDlg �Ի���
class CInfoDlg : public CDialogEx
{
// ����
public:
	CInfoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_DIALOG };
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
	CString m_sName;
	CString m_sNumber;
	CString m_sClass;
	int m_iMath;
	int m_iEng;
	int m_iCom;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnFemaleRadio();
	afx_msg void OnMaleRadio();
	CString m_sGender;
};
