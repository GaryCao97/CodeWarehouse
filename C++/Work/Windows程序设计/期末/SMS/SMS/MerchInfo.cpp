// MerchInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "MerchInfo.h"
#include "afxdialogex.h"
#include "MerchOne.h"


// CMerchInfo �Ի���

IMPLEMENT_DYNAMIC(CMerchInfo, CDialogEx)

CMerchInfo::CMerchInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MERCH_INFO, pParent)
{

}

CMerchInfo::~CMerchInfo()
{
}

void CMerchInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MERCHLIST, m_listMerch);
}


BEGIN_MESSAGE_MAP(CMerchInfo, CDialogEx)
	ON_BN_CLICKED(IDC_ADDMERCH, &CMerchInfo::OnBnClickedAddmerch)
	ON_BN_CLICKED(IDC_CHANGEMERCH, &CMerchInfo::OnBnClickedChangemerch)
	ON_BN_CLICKED(IDC_DELMERCH, &CMerchInfo::OnBnClickedDelmerch)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_MERCHLIST, &CMerchInfo::OnLvnItemActivateMerchlist)
END_MESSAGE_MAP()


// CMerchInfo ��Ϣ�������


void CMerchInfo::PaintList()
{
	m_listMerch.DeleteAllItems();
	m_iMerchPos = -1;
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	LV_ITEM item;
	CString string;
	int i = 0, j;
	if (!MerchSet.IsEOF()) {
		MerchSet.Move(0);
		while (MerchSet.IsEOF() == 0) {
			m_listMerch.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			MerchSet.GetFieldValue((short)0, string);
			item.pszText = string.GetBuffer(string.GetLength());
			m_listMerch.InsertItem(&item);
			for (j = 1; j < MerchSet.GetODBCFieldCount() - 1; j++) {
				MerchSet.GetFieldValue((short)j, string);
				m_listMerch.SetItemText(i, j - 1, string.GetBuffer(string.GetLength()));
			}
			MerchSet.MoveNext();
			i++;
			m_listMerch.SetRedraw(TRUE);
		}
	}
	MerchSet.Close();

}


BOOL CMerchInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	if (!MerchSet.IsOpen())
		MerchSet.Open();
	m_listMerch.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (MerchSet.IsEOF())
		MessageBox(_T("����¼������"), _T("ϵͳ��ʾ"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < MerchSet.GetODBCFieldCount() - 2; i++)
	{
		MerchSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = i;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("Merchnum"))DbFi.m_strName = _T("��Ʒ���");
		else if (DbFi.m_strName == _T("Merchname"))DbFi.m_strName = _T("��Ʒ����");
		else if (DbFi.m_strName == _T("Merchkind"))DbFi.m_strName = _T("��Ʒ����");
		else if (DbFi.m_strName == _T("Introduction"))DbFi.m_strName = _T("��Ʒ����");
		else if (DbFi.m_strName == _T("Price"))DbFi.m_strName = _T("��Ʒ����");
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		m_listMerch.InsertColumn(i, &Lc);
	}
	MerchSet.Close();
	CMerchInfo::PaintList();
	if(m_strPost == _T("Ա��"))
		GetDlgItem(IDC_ADDMERCH)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHANGEMERCH)->EnableWindow(FALSE);
	GetDlgItem(IDC_DELMERCH)->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CMerchInfo::OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iMerchPos = m_listMerch.GetSelectionMark();
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	if (m_strPost == _T("����") && isItInString(m_strDuty, MerchSet.m_Merchkind)) {
		GetDlgItem(IDC_CHANGEMERCH)->EnableWindow(TRUE);
		GetDlgItem(IDC_DELMERCH)->EnableWindow(TRUE);
	}
	else if (m_strPost == _T("Ա��") && isItInString(m_strDuty, MerchSet.m_Merchname)) {
		GetDlgItem(IDC_CHANGEMERCH)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_CHANGEMERCH)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELMERCH)->EnableWindow(FALSE);
	}
	MerchSet.Close();
	*pResult = 0;
}


void CMerchInfo::OnBnClickedAddmerch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchOne merchOne;
	if(merchOne.DoModal() == IDOK)
		CMerchInfo::PaintList();
}


void CMerchInfo::OnBnClickedChangemerch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchOne merchOne;
	merchOne.m_bIsAdd = false;
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	merchOne.m_sIntroduct = MerchSet.m_Introduction;
	merchOne.m_sMerchkind = MerchSet.m_Merchkind;
	merchOne.m_sMerchname = MerchSet.m_Merchname;
	merchOne.m_sMerchnum = MerchSet.m_Merchnum;
	merchOne.m_sPrice = MerchSet.m_Price;
	MerchSet.Close();
	if (merchOne.DoModal() == IDOK)
		CMerchInfo::PaintList();
}


void CMerchInfo::OnBnClickedDelmerch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nRes = MessageBox(_T("ȷ��ɾ��"), _T("ϵͳ��ʾ"), MB_OKCANCEL);
	if (nRes == IDCANCEL)
		return;
	else if (m_iMerchPos >= 0) {
		if (!MerchSet.IsOpen())
			MerchSet.Open();
		if (!MerchSet.IsEOF()) {
			MerchSet.Move(m_iMerchPos);
			MerchSet.Delete();
			MerchSet.Close();
			CMerchInfo::PaintList();
		}
	}
}