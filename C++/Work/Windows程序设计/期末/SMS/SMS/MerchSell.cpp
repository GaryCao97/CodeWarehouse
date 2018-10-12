// MerchSell.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "MerchSell.h"
#include "afxdialogex.h"
#include "MerchNum.h"
#include "Forms.h"


// CMerchSell 对话框

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


// CMerchSell 消息处理程序


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

	// TODO:  在此添加额外的初始化

	if (!MerchSet.IsOpen())
		MerchSet.Open();
	m_listMerch.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (MerchSet.IsEOF())
		MessageBox(_T("请先录入数据"), _T("系统提示"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < MerchSet.GetODBCFieldCount() - 2; i++)
	{
		MerchSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = i;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("Merchnum"))DbFi.m_strName = _T("商品编号");
		else if (DbFi.m_strName == _T("Merchname"))DbFi.m_strName = _T("商品名称");
		else if (DbFi.m_strName == _T("Merchkind"))DbFi.m_strName = _T("商品种类");
		else if (DbFi.m_strName == _T("Introduction"))DbFi.m_strName = _T("商品介绍");
		else if (DbFi.m_strName == _T("Price"))DbFi.m_strName = _T("商品单价");
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		m_listMerch.InsertColumn(i, &Lc);
	}
	MerchSet.Close();
	CMerchSell::PaintList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CMerchSell::OnLvnItemActivateMerchlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_iMerchPos = m_listMerch.GetSelectionMark();
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	if (m_strPost == _T("经理") && isItInString(m_strDuty, MerchSet.m_Merchkind)) {
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
	// TODO: 在此添加控件通知处理程序代码
	CMerchNum merchNum;
	merchNum.m_sTag = _T("进货数：");
	if (merchNum.DoModal() == IDOK)
		CMerchSell::PaintList();
}


void CMerchSell::OnBnClickedBtnSell()
{
	// TODO: 在此添加控件通知处理程序代码
	CMerchNum merchNum;
	merchNum.m_sTag = _T("销售数：");
	if (merchNum.DoModal() == IDOK)
		CMerchSell::PaintList();
}


void CMerchSell::OnBnClickedBtnForms()
{
	// TODO: 在此添加控件通知处理程序代码
	CForms formsDlg;
	formsDlg.DoModal();
}
