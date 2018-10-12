// AdminDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "AdminDlg.h"
#include "UserInfo.h"
#include "afxdialogex.h"


// CAdminDlg �Ի���

IMPLEMENT_DYNAMIC(CAdminDlg, CDialogEx)

CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADMIN_MAIN, pParent)
	, m_iUserPos(-1)
	, m_sSearch(_T(""))
{

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERLIST, UserList);
	DDX_Control(pDX, IDC_SEARCH_COMBO, m_comboSearch);
	DDX_Text(pDX, IDC_SEARCH, m_sSearch);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialogEx)
	ON_BN_CLICKED(IDC_USER_ADD, &CAdminDlg::OnBnClickedUserAdd)
	ON_BN_CLICKED(IDC_USER_CHANGE, &CAdminDlg::OnBnClickedUserChange)
	ON_BN_CLICKED(IDC_USER_DELETE, &CAdminDlg::OnBnClickedUserDelete)
	ON_BN_CLICKED(IDC_SEARCH_BTN, &CAdminDlg::OnBnClickedSearchBtn)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_USERLIST, &CAdminDlg::OnItemactivateUserlist)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_USERLIST, &CAdminDlg::OnColumnclickUserlist)
END_MESSAGE_MAP()


// CAdminDlg ��Ϣ�������

void CAdminDlg::PaintListItem()
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
		while (!UserSet.IsEOF())
		{
			UserList.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			UserSet.GetFieldValue((short)0, string);
			item.pszText = string.GetBuffer(string.GetLength());
			UserList.InsertItem(&item);
			for (j = 1; j < UserSet.GetODBCFieldCount()-1; j++)
			{
				UserSet.GetFieldValue((short)j, string);
				UserList.SetItemText(i, j-1, string.GetBuffer(string.GetLength()));
			}
			UserSet.MoveNext();
			i++;
			UserList.SetRedraw(TRUE);
		}
	}
	UserSet.Close();
}


BOOL CAdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (!UserSet.IsOpen())
		UserSet.Open();
	UserList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (UserSet.IsEOF())
		MessageBox(_T("����¼������"), _T("ϵͳ��ʾ"));
	CString str;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < UserSet.GetODBCFieldCount()-1; i++)
	{
		UserSet.GetODBCFieldInfo(i, str);
		Lc.iSubItem = i - 1;
		Lc.fmt = LVCFMT_CENTER;
		if (str == _T("Username"))str = _T("�û���");
		else if (str == _T("Number"))str = _T("����");
		else if (str == _T("Realname"))str = _T("Ա������");
		else if (str == _T("Kind"))str = _T("����");
		else if (str == _T("Duty"))str = _T("������Ʒ/����");
		m_comboSearch.AddString(str);
		Lc.cx = str.GetLength() * 25 + 25;
		Lc.pszText = str.GetBuffer(str.GetLength());
		UserList.InsertColumn(i, &Lc);
	}
	UserSet.Close();
	CAdminDlg::PaintListItem();
	m_comboSearch.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAdminDlg::OnBnClickedUserAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUserInfo userInfoDlg;
	userInfoDlg.m_iStyle = -1;
	if (userInfoDlg.DoModal() == IDOK)
		CAdminDlg::PaintListItem();
	UpdateData(FALSE);
}


void CAdminDlg::OnBnClickedUserChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUserInfo userInfoDlg;
	userInfoDlg.m_iStyle = m_iUserPos;
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
		if (userInfoDlg.DoModal() == IDOK)
			CAdminDlg::PaintListItem();
	}
	UpdateData(FALSE);
}


void CAdminDlg::OnBnClickedUserDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nRes = MessageBox(_T("ȷ��ɾ��"), _T("ϵͳ��ʾ"), MB_OKCANCEL);
	if (nRes == IDCANCEL)
		return;
	UpdateData(TRUE);
	if (m_iUserPos >= 0) {
		if (!UserSet.IsOpen())
			UserSet.Open();
		if (!UserSet.IsEOF()) {
			UserSet.Move(m_iUserPos);
			UserSet.Delete();
			UserSet.Close();
			CAdminDlg::PaintListItem();
		}
	}
	UpdateData(FALSE);
}


void CAdminDlg::OnBnClickedSearchBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_sSearch == _T("")) {
		MessageBox(_T("������������ݣ�"), _T("ϵͳ��ʾ"));
		UserSet.m_strFilter = _T("");
		CAdminDlg::PaintListItem();
	}
	else {
		CString str;
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.GetODBCFieldInfo(m_comboSearch.GetCurSel() + 1, str);
		if (UserSet.IsOpen())
			UserSet.Close();
		UserSet.m_strFilter = str + _T("='") + m_sSearch + _T("'");
		UserSet.m_sFilterTitle = str;
		UserSet.m_sFilterKeyWord = m_sSearch;
		CAdminDlg::PaintListItem();
	}
	UpdateData(FALSE);
}


void CAdminDlg::OnItemactivateUserlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	m_iUserPos = UserList.GetSelectionMark();
}


void CAdminDlg::OnColumnclickUserlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int sortNum = pNMLV->iSubItem;
	CString str;
	if (!UserSet.IsOpen())
		UserSet.Open();
	UserSet.GetODBCFieldInfo(sortNum+1, str);
	if (UserSet.IsOpen())
		UserSet.Close();
	UserSet.m_strSort = str;
	CAdminDlg::PaintListItem();
	*pResult = 0;
}
