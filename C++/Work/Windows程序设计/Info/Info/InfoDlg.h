
// InfoDlg.h : 头文件
//

#pragma once


// CInfoDlg 对话框
class CInfoDlg : public CDialogEx
{
// 构造
public:
	CInfoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
