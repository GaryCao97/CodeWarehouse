#pragma once


// CBlogChoose 对话框

class CBlogChoose : public CDialogEx
{
	DECLARE_DYNAMIC(CBlogChoose)

public:
	CBlogChoose(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlogChoose();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLOG_CHOOSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sBLOG;
	int m_iCommPos;
	afx_msg void OnBnClickedBtnBlogm();
	afx_msg void OnBnClickedBtnBlog();
};
