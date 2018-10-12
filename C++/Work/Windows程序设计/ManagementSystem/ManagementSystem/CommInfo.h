#pragma once
#include "afxwin.h"


// CCommInfo �Ի���

class CCommInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CCommInfo)

public:
	CCommInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sCommName;
	CString m_sCommNum;
	CString m_sCommKind;
	CString m_sIntroduce;
	CString m_sOrigin;
	CString m_sSpecification;
	CString m_sPrice;
	CString m_sPhotoAddress;
	CStatic m_picPhoto;
	afx_msg void OnBnClickedBtnPhoto();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	int m_iUserPos;
	int m_iCommPos;
};
