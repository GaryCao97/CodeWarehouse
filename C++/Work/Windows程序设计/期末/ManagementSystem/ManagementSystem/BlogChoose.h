#pragma once


// CBlogChoose �Ի���

class CBlogChoose : public CDialogEx
{
	DECLARE_DYNAMIC(CBlogChoose)

public:
	CBlogChoose(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBlogChoose();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLOG_CHOOSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sBLOG;
	int m_iCommPos;
	afx_msg void OnBnClickedBtnBlogm();
	afx_msg void OnBnClickedBtnBlog();
};
