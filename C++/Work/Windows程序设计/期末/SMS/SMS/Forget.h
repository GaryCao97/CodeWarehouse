#pragma once


// CForget 对话框

class CForget : public CDialogEx
{
	DECLARE_DYNAMIC(CForget)

public:
	CForget(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CForget();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword1;
	CString m_sPassword2;
};
