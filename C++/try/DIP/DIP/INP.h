#pragma once


// CINP 对话框

class CINP : public CDialogEx
{
	DECLARE_DYNAMIC(CINP)

public:
	CINP(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CINP();

	virtual void OnFinalRelease();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOISE};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
