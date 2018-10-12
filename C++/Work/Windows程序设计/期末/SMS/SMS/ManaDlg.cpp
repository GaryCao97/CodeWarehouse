// ManaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "ManaDlg.h"
#include "afxdialogex.h"
#include "StaffAdd.h"


// CManaDlg �Ի���

IMPLEMENT_DYNAMIC(CManaDlg, CDialogEx)

CManaDlg::CManaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MANA_DLG, pParent)
{
	m_iStaffPos = -1;
}

CManaDlg::~CManaDlg()
{
}

void CManaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STAFFLIST, m_listStaff);
}


BEGIN_MESSAGE_MAP(CManaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADDSTAFF, &CManaDlg::OnBnClickedAddstaff)
	ON_BN_CLICKED(IDC_DELSTAFF, &CManaDlg::OnBnClickedDelstaff)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_STAFFLIST, &CManaDlg::OnLvnItemActivateStafflist)
END_MESSAGE_MAP()


// CManaDlg ��Ϣ�������


void CManaDlg::PaintList()
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


BOOL CManaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	if (!StaffSet.IsOpen())
		StaffSet.Open();
	m_listStaff.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (StaffSet.IsEOF())
		MessageBox(_T("����¼������"), _T("ϵͳ��ʾ"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < StaffSet.GetODBCFieldCount() - 1; i++)
	{
		StaffSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = i;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("Username"))DbFi.m_strName = _T("�û���");
		else if (DbFi.m_strName == _T("Post"))DbFi.m_strName = _T("ְλ");
		else if (DbFi.m_strName == _T("Duty"))DbFi.m_strName = _T("������");
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		m_listStaff.InsertColumn(i, &Lc);
	}
	StaffSet.Close();
	CManaDlg::PaintList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CManaDlg::OnBnClickedAddstaff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStaffAdd staffAdd;
	if(staffAdd.DoModal() == IDOK)
		CManaDlg::PaintList();
}


void CManaDlg::OnBnClickedDelstaff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nRes = MessageBox(_T("ȷ��ɾ��"), _T("ϵͳ��ʾ"), MB_OKCANCEL);
	if (nRes == IDCANCEL)
		return;
	else if (m_iStaffPos >= 0) {
		if (!StaffSet.IsOpen())
			StaffSet.Open();
		if (!StaffSet.IsEOF()) {
			StaffSet.Move(m_iStaffPos);
			StaffSet.Delete();
			StaffSet.Close();
			CManaDlg::PaintList();
		}
	}
}


void CManaDlg::OnLvnItemActivateStafflist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iStaffPos = m_listStaff.GetSelectionMark();
	*pResult = 0;
}

