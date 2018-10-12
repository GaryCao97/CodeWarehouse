// MerchSell.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "MerchSell.h"
#include "afxdialogex.h"
#include "MerchNum.h"
#include "Forms.h"


// CMerchSell �Ի���

IMPLEMENT_DYNAMIC(CMerchSell, CDialogEx)

CMerchSell::CMerchSell(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MERCH_SELL, pParent)
{

}

CMerchSell::~CMerchSell()
{
}

void CMerchSell::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MERCHLIST, m_listMerch);
}


BEGIN_MESSAGE_MAP(CMerchSell, CDialogEx)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_MERCHLIST, &CMerchSell::OnLvnItemActivateMerchlist)
	ON_BN_CLICKED(IDC_BTN_STOCK, &CMerchSell::OnBnClickedBtnStock)
	ON_BN_CLICKED(IDC_BTN_SELL, &CMerchSell::OnBnClickedBtnSell)
	ON_BN_CLICKED(IDC_BTN_FORMS, &CMerchSell::OnBnClickedBtnForms)
END_MESSAGE_MAP()


// CMerchSell ��Ϣ�������


void CMerchSell::PaintList()
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


BOOL CMerchSell::OnInitDialog()
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
	CMerchSell::PaintList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CMerchSell::OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iMerchPos = m_listMerch.GetSelectionMark();
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	if (m_strPost == _T("����") && isItInString(m_strDuty, MerchSet.m_Merchkind)) {
		GetDlgItem(IDC_BTN_STOCK)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SELL)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BTN_STOCK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SELL)->EnableWindow(FALSE);
	}
	m_strForms = MerchSet.m_Forms;
	m_saForms = DivideString(m_strForms, _T(";"));
	MerchSet.Close();
	*pResult = 0;
}


void CMerchSell::OnBnClickedBtnStock()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchNum merchNum;
	merchNum.m_sTag = _T("��������");
	if (merchNum.DoModal() == IDOK)
		CMerchSell::PaintList();
}


void CMerchSell::OnBnClickedBtnSell()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMerchNum merchNum;
	merchNum.m_sTag = _T("��������");
	if (merchNum.DoModal() == IDOK)
		CMerchSell::PaintList();
}


void CMerchSell::OnBnClickedBtnForms()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CForms formsDlg;
	formsDlg.DoModal();
}
