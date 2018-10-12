#pragma once


// CINP �Ի���

class CINP : public CDialogEx
{
	DECLARE_DYNAMIC(CINP)

public:
	CINP(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CINP();

	virtual void OnFinalRelease();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOISE};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	BOOL m_check1;
	int m_radio1;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	double m_pa;
	double m_pb;
	double m_ua;
	double m_ub;
	double m_gauess_mu;
	double m_gauess_sigma;
	double m_gauess_k;
	afx_msg void OnBnClickedOk();
};
