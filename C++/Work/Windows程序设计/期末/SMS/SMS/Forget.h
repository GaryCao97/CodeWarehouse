#pragma once


// CForget �Ի���

class CForget : public CDialogEx
{
	DECLARE_DYNAMIC(CForget)

public:
	CForget(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CForget();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword1;
	CString m_sPassword2;
};
