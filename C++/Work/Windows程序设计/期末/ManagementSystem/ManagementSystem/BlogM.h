#pragma once


// CBlogM �Ի���

class CBlogM : public CDialogEx
{
	DECLARE_DYNAMIC(CBlogM)

public:
	CBlogM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlogM();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_listBlog;
	CString m_sBLOG;
	int m_iCommPos;
	virtual BOOL OnInitDialog();
	void PaintList(CStringArray* sa);
	CStringArray* strArr;
	int m_iDate;
	CStringArray* GetDateArray(CStringArray* Source);
	int m_iYear;
	int m_iMouth;
	void OnBnClickedReset();
	afx_msg void OnEnChangeYear();
	afx_msg void OnEnChangeMouth();
};
