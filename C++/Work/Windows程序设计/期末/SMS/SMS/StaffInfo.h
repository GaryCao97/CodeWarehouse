#pragma once
#include "afxcmn.h"


// CStaffInfo �Ի���

class CStaffInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffInfo)

public:
	CStaffInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFFINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStaff;
	void PaintList();
	virtual BOOL OnInitDialog();
};
