// CommDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "CommDlg.h"
#include "CommInfo.h"
#include "afxdialogex.h"


// CCommDlg 对话框

IMPLEMENT_DYNAMIC(CCommDlg, CDialogEx)

CCommDlg::CCommDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMM_DLG, pParent)
	, m_sSearch(_T(""))
	, m_iCommPos(0)
	, m_sUserKind(_T(""))
	, m_iUserPos(0)
{

}

CCommDlg::~CCommDlg()
{
}

void CCommDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH_COMBO, m_comboSearch);
	DDX_Text(pDX, IDC_SEARCH, m_sSearch);
	DDX_Control(pDX, IDC_COMMLIST, CommList);
}


BEGIN_MESSAGE_MAP(CCommDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_COMMLIST, &CCommDlg::OnItemactivateCommlist)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_COMMLIST, &CCommDlg::OnColumnclickCommlist)
	ON_BN_CLICKED(IDC_SEARCH_BTN, &CCommDlg::OnBnClickedSearchBtn)
	ON_BN_CLICKED(IDC_COMM_ADD, &CCommDlg::OnBnClickedCommAdd)
	ON_BN_CLICKED(IDC_COMM_CHANGE, &CCommDlg::OnBnClickedCommChange)
	ON_BN_CLICKED(IDC_COMM_DELETE, &CCommDlg::OnBnClickedCommDelete)
END_MESSAGE_MAP()


// CCommDlg 消息处理程序


void CCommDlg::PaintListItem()
{
	CommList.DeleteAllItems();
	m_iCommPos = -1;
	if (!CommSet.IsOpen())
		CommSet.Open();
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int i, j;
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
			for (j = 1; j < CommSet.GetODBCFieldCount() - 1; j++)
			{
				CommSet.GetFieldValue((short)j, string);
				CommList.SetItemText(i, j - 1, string.GetBuffer(string.GetLength()));
			}
			CommSet.MoveNext();
			i++;
			CommList.SetRedraw(TRUE);
		}
	}
	CommSet.Close();
}


BOOL CCommDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	int i;
	if (CommSet.IsEOF())
		MessageBox(_T("请先录入数据"), _T("系统提示"));
	CODBCFieldInfo DbFi;
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 1; i < CommSet.GetODBCFieldCount() - 1; i++)
	{
		CommSet.GetODBCFieldInfo(i, DbFi);
		Lc.iSubItem = i - 1;
		Lc.fmt = LVCFMT_CENTER;
		if (DbFi.m_strName == _T("CommNum"))DbFi.m_strName = _T("商品号");
		else if (DbFi.m_strName == _T("CommName"))DbFi.m_strName = _T("商品名");
		else if (DbFi.m_strName == _T("CommKind"))DbFi.m_strName = _T("商品种类");
		else if (DbFi.m_strName == _T("Price"))DbFi.m_strName = _T("单价");
		else if (DbFi.m_strName == _T("Origin"))DbFi.m_strName = _T("产地");
		else if (DbFi.m_strName == _T("PhotoAddress"))DbFi.m_strName = _T("图片");
		else if (DbFi.m_strName == _T("Specifications"))DbFi.m_strName = _T("规格");
		else if (DbFi.m_strName == _T("Introduce"))DbFi.m_strName = _T("商品介绍");
		//else if (DbFi.m_strName == _T("Inventory"))DbFi.m_strName = _T("商品库存");
		m_comboSearch.AddString(DbFi.m_strName);
		Lc.cx = DbFi.m_strName.GetLength() * 25 + 25;
		Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
		CommList.InsertColumn(i, &Lc);
	}
	CommSet.Close();
	CCommDlg::PaintListItem();
	m_comboSearch.SetCurSel(0);
	if (m_sUserKind == _T("员工")) {
		GetDlgItem(IDC_COMM_ADD)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMM_DELETE)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCommDlg::OnItemactivateCommlist(NMHDR *pNMHDR, LRESULT *pResult)
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
			GetDlgItem(IDC_COMM_DELETE)->EnableWindow(TRUE);
			GetDlgItem(IDC_COMM_CHANGE)->EnableWindow(TRUE);
		}
		else if (m_sUserKind == _T("员工") && isItInString(UserSet.m_Duty, CommSet.m_CommName)) {
			GetDlgItem(IDC_COMM_CHANGE)->EnableWindow(TRUE);
		}
		else {
			GetDlgItem(IDC_COMM_DELETE)->EnableWindow(FALSE);
			GetDlgItem(IDC_COMM_CHANGE)->EnableWindow(FALSE);
		}
		UserSet.Close();
		CommSet.Close();
	}
	*pResult = 0;
}


void CCommDlg::OnColumnclickCommlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int sortNum = pNMLV->iSubItem;
	CODBCFieldInfo info;
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.GetODBCFieldInfo(sortNum + 1, info);
	if (CommSet.IsOpen())
		CommSet.Close();
	CommSet.m_strSort = info.m_strName;
	CCommDlg::PaintListItem();
	*pResult = 0;
}


void CCommDlg::OnBnClickedSearchBtn()
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
		CommSet.GetODBCFieldInfo(m_comboSearch.GetCurSel() + 1, info);
		if (CommSet.IsOpen())
			CommSet.Close();
		CommSet.m_strFilter = info.m_strName + _T("='") + m_sSearch + _T("'");
	}
	CCommDlg::PaintListItem();
	UpdateData(FALSE);
}


void CCommDlg::OnBnClickedCommAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CCommInfo commInfoDlg;
	commInfoDlg.m_iCommPos = -1;
	commInfoDlg.m_iUserPos = m_iUserPos;
	if (commInfoDlg.DoModal() == IDOK)
		CCommDlg::PaintListItem();
	UpdateData(FALSE);
}


void CCommDlg::OnBnClickedCommChange()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CCommInfo commInfoDlg;
	commInfoDlg.m_iCommPos = m_iCommPos;
	commInfoDlg.m_iUserPos = m_iUserPos;
	if (m_iCommPos >= 0) {
		if (!CommSet.IsOpen())
			CommSet.Open();
		if (!CommSet.IsEOF()) {
			CommSet.Move(m_iCommPos);
			if (!UserSet.IsOpen())
				UserSet.Open();
			UserSet.Move(m_iUserPos);
			commInfoDlg.m_sCommNum = CommSet.m_CommNum;
			commInfoDlg.m_sCommName = CommSet.m_CommName;
			commInfoDlg.m_sCommKind = CommSet.m_CommKind;
			commInfoDlg.m_sPhotoAddress = CommSet.m_PhotoAddress;
			commInfoDlg.m_sOrigin = CommSet.m_Origin;
			commInfoDlg.m_sIntroduce = CommSet.m_Introduce;
			commInfoDlg.m_sSpecification = CommSet.m_Specifications;
			commInfoDlg.m_sPrice = CommSet.m_Price;
			CommSet.Close();
			UserSet.Close();
			commInfoDlg.DoModal();
			CCommDlg::PaintListItem();
		}
	}
}


void CCommDlg::OnBnClickedCommDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int nRes = MessageBox(_T("确定删除"), _T("系统提示"), MB_OKCANCEL);
	if (nRes == IDCANCEL)
		return;
	UpdateData(TRUE);
	if (m_iCommPos >= 0) {
		if (!CommSet.IsOpen())
			CommSet.Open();
		if (!CommSet.IsEOF()) {
			CommSet.Move(m_iCommPos);
			if (!UserSet.IsOpen())
				UserSet.Open();
			UserSet.Move(m_iUserPos);
			CommSet.Delete();
			CommSet.Close();
			UserSet.Close();
			CCommDlg::PaintListItem();
		}
	}
	UpdateData(FALSE);
}
