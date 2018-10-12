// Blog.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Blog.h"
#include "afxdialogex.h"


// CBlog 对话框

IMPLEMENT_DYNAMIC(CBlog, CDialogEx)

CBlog::CBlog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlog::IDD, pParent)
	, m_sBLOG(_T(""))
	, m_iCommPos(0)
{
	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	m_iYear=st.wYear;
	m_iMouth=st.wMonth;
	m_iDay=st.wDay;
}

CBlog::~CBlog()
{
}

void CBlog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BLOGLIST, m_listBlog);
	DDX_Text(pDX, IDC_YEAR, m_iYear);
	DDX_Text(pDX, IDC_MOUTH, m_iMouth);
	DDX_Text(pDX, IDC_DAY, m_iDay);
}


BEGIN_MESSAGE_MAP(CBlog, CDialogEx)
	ON_BN_CLICKED(IDC_RESET, &CBlog::OnBnClickedReset)
	ON_EN_CHANGE(IDC_YEAR, &CBlog::OnEnChangeYear)
	ON_EN_CHANGE(IDC_MOUTH, &CBlog::OnEnChangeMouth)
	ON_EN_CHANGE(IDC_DAY, &CBlog::OnEnChangeDay)
END_MESSAGE_MAP()


// CBlog 消息处理程序



BOOL CBlog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	strArr = DivideString(m_sBLOG, _T(";"));
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_YEAR))->SetRange(0,2333);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_MOUTH))->SetRange(1,12);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_DAY))->SetRange(1,31);
	m_listBlog.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_AUTOSIZECOLUMNS | LVS_EX_FULLROWSELECT);
	CString str1 = _T("日期");
	CString str2 = _T("信息");
	LV_COLUMN Lc;
	Lc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	Lc.iSubItem = 0;
	Lc.fmt = LVCFMT_LEFT;
	Lc.cx = 13 * 25;
	Lc.pszText = str1.GetBuffer(str1.GetLength());
	m_listBlog.InsertColumn(0, &Lc);
	Lc.iSubItem = 0;
	Lc.cx = 20 * 25;
	Lc.pszText = str2.GetBuffer(str2.GetLength());
	m_listBlog.InsertColumn(1, &Lc);
	PaintList(strArr);
	return TRUE;
}


void CBlog::PaintList(CStringArray* sa)
{
	m_listBlog.DeleteAllItems();
	if(sa){
		LV_ITEM item;
		CString str;
		int i;
		for (i = 0; i < sa->GetCount(); i++) {
			str = (*sa)[i];
			m_listBlog.SetRedraw(FALSE);
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			item.pszText = str.GetBuffer(str.GetLength());
			CStringArray* strA = DivideString(str, _T(" "));
			m_listBlog.InsertItem(&item);
			m_listBlog.SetItemText(i, 0, (*strA)[0].GetBuffer((*strA)[0].GetLength()));
			m_listBlog.SetItemText(i, 1, (*strA)[1].GetBuffer((*strA)[1].GetLength()));
			m_listBlog.SetRedraw(TRUE);
		}
	}
}


CStringArray* CBlog::GetDateArray(CStringArray* Source)
{
	CStringArray *arr = new CStringArray();
	CString strDate, strYMD;
	GetDlgItemText(IDC_YEAR, strYMD);
	strDate += strYMD + _T("年");
	GetDlgItemText(IDC_MOUTH, strYMD);
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


void CBlog::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	CommSet.m_Blog = _T("");
	m_listBlog.DeleteAllItems();
	CommSet.Close();
}



void CBlog::OnEnChangeYear()
{
	static bool isFirst = true;
	if (m_sBLOG != _T("")) {
		strArr = DivideString(m_sBLOG, _T(";"));
		CStringArray* strArray = GetDateArray(strArr);
		if(!isFirst)
			PaintList(strArray);
		else isFirst = false;
	}
}


void CBlog::OnEnChangeMouth()
{
	static bool isFirst = true;
	if (m_sBLOG != _T("")) {
		strArr = DivideString(m_sBLOG, _T(";"));
		CStringArray* strArray = GetDateArray(strArr);
		if (!isFirst)
			PaintList(strArray);
		else isFirst = false;
	}
}


void CBlog::OnEnChangeDay()
{
	static bool isFirst = true;
	if (m_sBLOG != _T("")) {
		strArr = DivideString(m_sBLOG, _T(";"));
		CStringArray* strArray = GetDateArray(strArr);
		if (!isFirst)
			PaintList(strArray);
		else isFirst = false;
	}
}
