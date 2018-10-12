// UserMana.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "UserMana.h"
#include "UserInfo.h"
#include "afxdialogex.h"


// CUserMana 对话框

IMPLEMENT_DYNAMIC(CUserMana, CDialogEx)

CUserMana::CUserMana(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_USER_DLG, pParent)
	, m_iUserPos(-1)
	, m_sUser(_T(""))
{

}

CUserMana::~CUserMana()
{
}

void CUserMana::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERLIST, UserList);
}


BEGIN_MESSAGE_MAP(CUserMana, CDialogEx)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_USERLIST, &CUserMana::OnItemactivateUserlist)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_USERLIST, &CUserMana::OnColumnclickUserlist)
	ON_BN_CLICKED(IDC_BTN_CHANGE, &CUserMana::OnBnClickedBtnChange)
END_MESSAGE_MAP()


// CUserMana 消息处理程序

void CUserMana::PaintListItem()
{
	UserList.DeleteAllItems();
	m_iUserPos = -1;
	if (!UserSet.IsOpen())
		UserSet.Open();
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int i, j;
	i = 0;
	if (!UserSet.IsEOF()) {
		UserSet.Move(0);
		while (UserSet.IsEOF() == 0)
		{
			UserList.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			UserSet.GetFieldValue((short)0, string);
			item.pszText = string.GetBuffer(string.GetLength());
			UserList.InsertItem(&item);
			for (j = 1; j < UserSet.GetODBCFieldCount() - 2; j++)
			{
				UserSet.GetFieldValue((short)j, string);
				UserList.SetItemText(i, j - 1, string.GetBuffer(string.GetLength()));
			}
			UserSet.MoveNext();
			i++;
			UserList.SetRedraw(TRUE);
		}
	}
	UserSet.Close();
}


BOOL CUserMana::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (!UserSet.IsOpen())
		UserSet.Open();
	UserList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (UserSet.IsEOF())
		MessageBox(_T("请先录入数据"), _T("系统提示"));
	CString str;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < UserSet.GetODBCFieldCount() - 2; i++)
	{
		UserSet.GetODBCFieldInfo(i, str);
		Lc.iSubItem = i - 1;
		Lc.fmt = LVCFMT_CENTER;
		if (str == _T("Username"))str = _T("用户名");
		else if (str == _T("Number"))str = _T("工号");
		else if (str == _T("Realname"))str = _T("员工姓名");
		else if (str == _T("Kind"))str = _T("工种");
		else if (str == _T("Duty"))str = _T("负责商品/种类");
		Lc.cx = str.GetLength() * 25 + 25;
		Lc.pszText = str.GetBuffer(str.GetLength());
		UserList.InsertColumn(i, &Lc);
	}
	UserSet.Close();
	CUserMana::PaintListItem();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CUserMana::OnItemactivateUserlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_iUserPos = UserList.GetSelectionMark();
	if (m_iUserPos >= 0) {
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.Move(m_iUserPos);
		if (m_sUser == (CString)UserSet.m_Number) {
			GetDlgItem(IDC_BTN_CHANGE)->EnableWindow(TRUE);
		}
		else {
			GetDlgItem(IDC_BTN_CHANGE)->EnableWindow(FALSE);
		}
		UserSet.Close();
	}
}


void CUserMana::OnColumnclickUserlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int sortNum = pNMLV->iSubItem;
	CString info;
	if (!UserSet.IsOpen())
		UserSet.Open();
	UserSet.GetODBCFieldInfo(sortNum + 1, info);
	if (UserSet.IsOpen())
		UserSet.Close();
	UserSet.m_strSort = info;
	CUserMana::PaintListItem();
	*pResult = 0;
}


void CUserMana::OnBnClickedBtnChange()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CUserInfo userInfoDlg;
	userInfoDlg.m_iStyle = m_iUserPos;
	userInfoDlg.m_bNorA = true;
	if (m_iUserPos >= 0) {
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.Move(m_iUserPos);
		userInfoDlg.m_sUsername = UserSet.m_Username;
		userInfoDlg.m_sRealName = UserSet.m_Realname;
		userInfoDlg.m_sNumber = UserSet.m_Number;
		userInfoDlg.m_sKind = UserSet.m_Kind;
		userInfoDlg.m_sDuty = UserSet.m_Duty;
		UserSet.Close();
		MessageBox(_T("修改信息后，密码初始化为工号后6位，修改密码请使用忘记密码！"), _T("系统提示"));
		if (userInfoDlg.DoModal() == IDOK)
			CUserMana::PaintListItem();
		
	}
	UpdateData(FALSE);
}
