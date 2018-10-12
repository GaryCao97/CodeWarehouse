// Forms.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "Forms.h"
#include "afxdialogex.h"


// CForms 对话框

IMPLEMENT_DYNAMIC(CForms, CDialogEx)

CForms::CForms(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMS, pParent)
	, m_iType(0)
	, isFirst(true)
{
	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	m_iYear = st.wYear;
	m_iMonth = st.wMonth;
	m_iDay = st.wDay;
}

CForms::~CForms()
{
}

void CForms::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FORMLIST, m_listForms);
	DDX_Text(pDX, IDC_YEAR, m_iYear);
	DDX_Text(pDX, IDC_MONTH, m_iMonth);
	DDX_Text(pDX, IDC_DAY, m_iDay);
}


BEGIN_MESSAGE_MAP(CForms, CDialogEx)
	ON_BN_CLICKED(IDC_BYMONTH, &CForms::OnBnClickedBymouth)
	ON_BN_CLICKED(IDC_BYDAY, &CForms::OnBnClickedByday)
	ON_EN_CHANGE(IDC_YEAR, &CForms::OnEnChangeYear)
	ON_EN_CHANGE(IDC_MONTH, &CForms::OnEnChangeMonth)
	ON_EN_CHANGE(IDC_DAY, &CForms::OnEnChangeDay)
END_MESSAGE_MAP()


// CForms 消息处理程序


void CForms::OnBnClickedBymouth()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 1;
	GetDlgItem(IDC_SPIN_DAY)->EnableWindow(FALSE);
}


void CForms::OnBnClickedByday()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iType = 0;
	GetDlgItem(IDC_SPIN_DAY)->EnableWindow(TRUE);
}


BOOL CForms::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CheckDlgButton(IDC_BYDAY, 1);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_YEAR))->SetRange(0, 2333);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_MONTH))->SetRange(1, 12);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_DAY))->SetRange(1, 31);
	m_listForms.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	CString str1 = _T("日期");
	CString str2 = _T("信息");
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	Lc.iSubItem = 0;
	Lc.fmt = LVCFMT_LEFT;
	Lc.cx = 13 * 25;
	Lc.pszText = str1.GetBuffer(str1.GetLength());
	m_listForms.InsertColumn(0, &Lc);
	Lc.iSubItem = 0;
	Lc.cx = 20 * 25;
	Lc.pszText = str2.GetBuffer(str2.GetLength());
	m_listForms.InsertColumn(1, &Lc);
	PaintList(m_saForms);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CForms::PaintList(CStringArray* sa)
{
	m_listForms.DeleteAllItems();
	if (sa != NULL) {
		LV_ITEM item;
		CString str;
		int i;
		for (i = 0; i < sa->GetCount(); i++) {
			str = (*sa)[i];
			m_listForms.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			item.pszText = str.GetBuffer(str.GetLength());
			CStringArray* strA = DivideString(str, _T(" "));
			m_listForms.InsertItem(&item);
			m_listForms.SetItemText(i, 0, (*strA)[0].GetBuffer((*strA)[0].GetLength()));
			m_listForms.SetItemText(i, 1, (*strA)[1].GetBuffer((*strA)[1].GetLength()));
			m_listForms.SetRedraw(TRUE);
		}
	}
}


CStringArray* CForms::GetDateArrayByMonth(CStringArray* Source)
{
	CStringArray *arr = new CStringArray();
	CString strDate, strYMD;
	GetDlgItemText(IDC_YEAR, strYMD);
	strDate += strYMD + _T("年");
	GetDlgItemText(IDC_MONTH, strYMD);
	strDate += strYMD + _T("月");
	int p = 0;
	for (int i = 0; i < Source->GetCount(); i++) {
		p = 0;
		CString str = (*Source)[i].Tokenize(_T("月"), p) + _T("月");
		if (str == strDate)
			arr->Add((*Source)[i]);
	}
	if (arr->GetCount() > 0)
		return arr;
	else return NULL;
}


CStringArray* CForms::GetDateArrayByDay(CStringArray* Source)
{
	CStringArray *arr = new CStringArray();
	CString strDate, strYMD;
	GetDlgItemText(IDC_YEAR, strYMD);
	strDate += strYMD + _T("年");
	GetDlgItemText(IDC_MONTH, strYMD);
	strDate += strYMD + _T("月");
	GetDlgItemText(IDC_DAY, strYMD);
	strDate += strYMD + _T("日");
	int p = 0;
	for (int i = 0; i < Source->GetCount(); i++) {
		p = 0;
		CString str = (*Source)[i].Tokenize(_T(" "), p);
		if (str == strDate)
			arr->Add((*Source)[i]);
	}
	if (arr->GetCount() > 0)
		return arr;
	else return NULL;
}


void CForms::OnEnChangeYear()
{
	CStringArray* strArray;
	if (m_iType == 0)
		strArray = GetDateArrayByDay(m_saForms);
	else strArray = GetDateArrayByMonth(m_saForms);
	if(!isFirst)
		PaintList(strArray);
}


void CForms::OnEnChangeMonth()
{
	CStringArray* strArray;
	if (m_iType == 0)
		strArray = GetDateArrayByDay(m_saForms);
	else strArray = GetDateArrayByMonth(m_saForms);
	if (!isFirst)
		PaintList(strArray);
}


void CForms::OnEnChangeDay()
{
	CStringArray* strArray;
	if (m_iType == 0)
		strArray = GetDateArrayByDay(m_saForms);
	else strArray = GetDateArrayByMonth(m_saForms);
	if (!isFirst)
		PaintList(strArray);
	else isFirst = false;
}
