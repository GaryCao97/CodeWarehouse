// CommNum.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "CommNum.h"
#include "CommInDlg.h"
#include "CommOutDlg.h"
#include "BlogChoose.h"
#include "afxdialogex.h"


// CCommNum 对话框

IMPLEMENT_DYNAMIC(CCommNum, CDialogEx)

CCommNum::CCommNum(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMM_NUM, pParent)
	, m_sSearch(_T(""))
	, m_iUserPos(-1)
	, m_iCommPos(-1)
	, m_sUserKind(_T(""))
{
	if (!CommSet.IsOpen())
		CommSet.Open();
	col = new int[CommSet.GetODBCFieldCount()];
	CommSet.Close();
}

CCommNum::~CCommNum()
{
}

void CCommNum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH_COMBO, m_comboSearch);
	DDX_Text(pDX, IDC_SEARCH, m_sSearch);
	DDX_Control(pDX, IDC_COMMLIST, CommList);
}


BEGIN_MESSAGE_MAP(CCommNum, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH_BTN, &CCommNum::OnBnClickedSearchBtn)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_COMMLIST, &CCommNum::OnColumnclickCommlist)
	ON_BN_CLICKED(IDC_INCOMM, &CCommNum::OnBnClickedIncomm)
	ON_BN_CLICKED(IDC_OUTCOMM, &CCommNum::OnBnClickedOutcomm)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_COMMLIST, &CCommNum::OnItemactivateCommlist)
	ON_BN_CLICKED(IDC_INVENTORY, &CCommNum::OnClickedInventory)
END_MESSAGE_MAP()


// CCommNum 消息处理程序


void CCommNum::PaintListItem()
{
	CommList.DeleteAllItems();
	//m_iCommPos = -1;
	if (!CommSet.IsOpen())
		CommSet.Open();
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int i, j, k;
	i = 0;
	if (!CommSet.IsEOF()) {
		CommSet.Move(0);
		while (CommSet.IsEOF() == 0)
		{
			CommList.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			CommSet.GetFieldValue((short)0, string);
			item.pszText = string.GetBuffer(string.GetLength());
			CommList.InsertItem(&item);
			for (j = 1, k = 0; j < CommSet.GetODBCFieldCount(); j++)
			{
				if (j == col[k]) {
					CommSet.GetFieldValue((short)j, string);
					CommList.SetItemText(i, k, string.GetBuffer(string.GetLength()));
					k++;
				}
			}
			CommSet.MoveNext();
			i++;
			CommList.SetRedraw(TRUE);
		}
	}
	CommSet.Close();
}


BOOL CCommNum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i, j;
	if (CommSet.IsEOF())
		MessageBox(_T("请先录入数据"), _T("系统提示"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1, j = 0; i < CommSet.GetODBCFieldCount(); i++, j++)
	{
		CommSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = j + 1;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("CommNum"))DbFi.m_strName = _T("商品号");
		else if (DbFi.m_strName == _T("CommName"))DbFi.m_strName = _T("商品名");
		else if (DbFi.m_strName == _T("CommKind"))DbFi.m_strName = _T("商品种类");
		else if (DbFi.m_strName == _T("Price"))DbFi.m_strName = _T("单价");
		else if (DbFi.m_strName == _T("Specifications"))DbFi.m_strName = _T("规格");
		else if (DbFi.m_strName == _T("Inventory"))DbFi.m_strName = _T("商品库存");
		else {
			j--;
			continue;
		}
		col[j] = i;
		m_comboSearch.AddString(DbFi.m_strName);
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		CommList.InsertColumn(j + 1, &Lc);
	}
	CommSet.Close();
	CCommNum::PaintListItem();
	m_comboSearch.SetCurSel(0);
	if (m_sUserKind == _T("员工")) {
		GetDlgItem(IDC_INCOMM)->EnableWindow(FALSE);
		GetDlgItem(IDC_OUTCOMM)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCommNum::OnBnClickedSearchBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_sSearch == _T("")) {
		if (CommSet.IsOpen())
			CommSet.Close();
		MessageBox(_T("请输入查找内容！"), _T("系统提示"));
		CommSet.m_strFilter = _T("");
	}
	else {
		CODBCFieldInfo info;
		if (!CommSet.IsOpen())
			CommSet.Open();
		CommSet.GetODBCFieldInfo(col[m_comboSearch.GetCurSel()], info);
		if (CommSet.IsOpen())
			CommSet.Close();
		CommSet.m_strFilter = info.m_strName + _T("='") + m_sSearch + _T("'");
	}
	CCommNum::PaintListItem();
	UpdateData(FALSE);
}


void CCommNum::OnColumnclickCommlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int sortNum = col[pNMLV->iSubItem];
	CODBCFieldInfo info;
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.GetODBCFieldInfo(sortNum, info);
	if (CommSet.IsOpen())
		CommSet.Close();
	CommSet.m_strSort = info.m_strName;
	CCommNum::PaintListItem();
	*pResult = 0;
}


void CCommNum::OnItemactivateCommlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_iCommPos = CommList.GetSelectionMark();
	if (m_iUserPos >= 0) {
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.Move(m_iUserPos);
		if (!CommSet.IsOpen())
			CommSet.Open();
		CommSet.Move(m_iCommPos);
		if (m_sUserKind == _T("经理") && isItInString(UserSet.m_Duty, CommSet.m_CommKind)) {
			GetDlgItem(IDC_INCOMM)->EnableWindow(TRUE);
			GetDlgItem(IDC_OUTCOMM)->EnableWindow(TRUE);
		}
		else {
			GetDlgItem(IDC_INCOMM)->EnableWindow(FALSE);
			GetDlgItem(IDC_OUTCOMM)->EnableWindow(FALSE);
		}
		UserSet.Close();
		CommSet.Close();
	}
	*pResult = 0;
}


void CCommNum::OnBnClickedIncomm()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	CCommInDlg inDlg;
	inDlg.m_iCommPos = m_iCommPos;
	inDlg.m_sCommKind = CommSet.m_CommKind;
	inDlg.m_sCommName = CommSet.m_CommName;
	inDlg.m_sCommNum = CommSet.m_CommNum;
	inDlg.m_sPrice = CommSet.m_Price;
	inDlg.m_sSpecifi = CommSet.m_Specifications;
	inDlg.m_sAddress = CommSet.m_PhotoAddress;
	CommSet.Close();
	if(inDlg.DoModal() == IDOK)
		CCommNum::PaintListItem();
}


void CCommNum::OnBnClickedOutcomm()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	CCommOutDlg outDlg;
	outDlg.m_iCommPos = m_iCommPos;
	outDlg.m_sCommKind = CommSet.m_CommKind;
	outDlg.m_sCommName = CommSet.m_CommName;
	outDlg.m_sCommNum = CommSet.m_CommNum;
	outDlg.m_sPrice = CommSet.m_Price;
	outDlg.m_sSpecifi = CommSet.m_Specifications;
	outDlg.m_sAddress = CommSet.m_PhotoAddress;
	CommSet.Close();
	if (outDlg.DoModal() == IDOK)
		CCommNum::PaintListItem();
}

void CCommNum::OnClickedInventory()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	CBlogChoose bd;
	bd.m_sBLOG = CommSet.m_Blog;
	bd.m_iCommPos = m_iCommPos;
	CommSet.Close();
	bd.DoModal();
}
