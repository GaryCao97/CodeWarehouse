#pragma once
#include "afxcmn.h"


// CStaffInfo 对话框

class CStaffInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffInfo)

public:
	CStaffInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFFINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStaff;
	void PaintList();
	virtual BOOL OnInitDialog();
};
