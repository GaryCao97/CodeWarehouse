// StaffInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "StaffInfo.h"
#include "afxdialogex.h"


// CStaffInfo 对话框

IMPLEMENT_DYNAMIC(CStaffInfo, CDialogEx)

CStaffInfo::CStaffInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STAFFINFO, pParent)
{

}

CStaffInfo::~CStaffInfo()
{
}

void CStaffInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STAFFLIST, m_listStaff);
}


BEGIN_MESSAGE_MAP(CStaffInfo, CDialogEx)
END_MESSAGE_MAP()


// CStaffInfo 消息处理程序

void CStaffInfo::PaintList()
{
	m_listStaff.DeleteAllItems();
	m_iStaffPos = -1;
	if (!StaffSet.IsOpen())
		StaffSet.Open();
	LV_ITEM item;
	CString string;
	int i = 0, j;
	if (!StaffSet.IsEOF()) {
		StaffSet.Move(0);
		while (StaffSet.IsEOF() == 0) {
			m_listStaff.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			StaffSet.GetFieldValue((short)0, string);
			item.pszText = string.GetBuffer(string.GetLength());
			m_listStaff.InsertItem(&item);
			for (j = 1; j < StaffSet.GetODBCFieldCount() - 1; j++) {
				StaffSet.GetFieldValue((short)j, string);
				m_listStaff.SetItemText(i, j - 1, string.GetBuffer(string.GetLength()));
			}
			StaffSet.MoveNext();
			i++;
			m_listStaff.SetRedraw(TRUE);
		}
	}
	StaffSet.Close();
}


BOOL CStaffInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (!StaffSet.IsOpen())
		StaffSet.Open();
	m_listStaff.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (StaffSet.IsEOF())
		MessageBox(_T("请先录入数据"), _T("系统提示"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < StaffSet.GetODBCFieldCount() - 1; i++)
	{
		StaffSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = i;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("Username"))DbFi.m_strName = _T("用户名");
		else if (DbFi.m_strName == _T("Post"))DbFi.m_strName = _T("职位");
		else if (DbFi.m_strName == _T("Duty"))DbFi.m_strName = _T("负责工作");
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		m_listStaff.InsertColumn(i, &Lc);
	}
	StaffSet.Close();
	CStaffInfo::PaintList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}