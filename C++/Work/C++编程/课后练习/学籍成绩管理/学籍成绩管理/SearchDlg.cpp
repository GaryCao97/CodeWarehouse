// SearchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "SearchDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CInformationSet _Set;


// CSearchDlg 对话框

IMPLEMENT_DYNAMIC(CSearchDlg, CDialogEx)

CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearchDlg::IDD, pParent)
	, search_edit(_T(""))
{

}

CSearchDlg::~CSearchDlg()
{
}

void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_search_List, search_list);
	DDX_Text(pDX, IDC_search_Edit, search_edit);
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialogEx)
	ON_BN_CLICKED(IDC_search_Return, &CSearchDlg::OnBnClickedsearchReturn)
	ON_BN_CLICKED(IDC_search_name, &CSearchDlg::OnBnClickedsearchname)
	ON_BN_CLICKED(IDC_search_number, &CSearchDlg::OnBnClickedsearchnumber)
	ON_BN_CLICKED(IDC_search_school, &CSearchDlg::OnBnClickedsearchschool)
	ON_BN_CLICKED(IDC_search_class, &CSearchDlg::OnBnClickedsearchclass)
	ON_BN_CLICKED(IDC_search_teacher, &CSearchDlg::OnBnClickedsearchteacher)
	ON_BN_CLICKED(IDC_search_lesson1, &CSearchDlg::OnBnClickedsearchlesson1)
	ON_BN_CLICKED(IDC_search_lesson2, &CSearchDlg::OnBnClickedsearchlesson2)
	ON_BN_CLICKED(IDC_search_lesson3, &CSearchDlg::OnBnClickedsearchlesson3)
	ON_BN_CLICKED(IDC_search_lesson4, &CSearchDlg::OnBnClickedsearchlesson4)
	ON_BN_CLICKED(IDC_search_lesson5, &CSearchDlg::OnBnClickedsearchlesson5)
	ON_BN_CLICKED(IDC_search_lesson_sum, &CSearchDlg::OnBnClickedsearchlessonsum)
	ON_BN_CLICKED(IDC_search_lesson_aver, &CSearchDlg::OnBnClickedsearchlessonaver)
END_MESSAGE_MAP()


// CSearchDlg 消息处理程序


void CSearchDlg::OnBnClickedsearchReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CSearchDlg::OnCancel();
}


BOOL CSearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if(!_Set.IsOpen())
	_Set.Open();
	search_list.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE|LVS_EX_AUTOSIZECOLUMNS|LVS_EX_FULLROWSELECT);
	int i;
	if(_Set.IsEOF())
		MessageBox(_T("请先录入数据"),_T("系统提示"));
	else
	{
		CODBCFieldInfo DbFi;
		LV_COLUMN Lc;
		Lc.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
		for(i = 0;i < 13;i++)
		{
			_Set.GetODBCFieldInfo(i,DbFi);
			Lc.iSubItem = i;
			Lc.fmt = LVCFMT_CENTER;
			Lc.cx = DbFi.m_strName.GetLength()*10+20;
			if (i >= 2 && i <= 4)
				Lc.cx = 150;
			else if(i == 1)
				Lc.cx = 100;
			else if(i == 11)
				Lc.cx = 50;
			Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
			search_list.InsertColumn(i,&Lc);
		}
	}
	_Set.Move(0);
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int j;
	i = 0;
	while(_Set.IsEOF() == 0)
	{
		search_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		_Set.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		search_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			_Set.GetFieldValue((short)j,string);
			search_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		_Set.MoveNext();
		i++;
		search_list.SetRedraw(TRUE);
	}
	
	_Set.Close();
	return TRUE;  
}


void CSearchDlg::PaintListItem(void)
{
	search_list.DeleteAllItems();
	if(!_Set.IsOpen())
	_Set.Open();
	_Set.Move(0);
	LV_ITEM item;
	CString string;
	CDBVariant DbVariant;
	int i,j;
	i = 0;
	while(_Set.IsEOF() == 0)
	{
		search_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		_Set.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		search_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			_Set.GetFieldValue((short)j,string);
			search_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		_Set.MoveNext();
		i++;
		search_list.SetRedraw(TRUE);
	}
	
	_Set.Close();
}


void CSearchDlg::OnBnClickedsearchname()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("姓名='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchnumber()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学号='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchschool()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学院='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchclass()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("专业班级='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchteacher()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("辅导员='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学科1=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学科2=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学科3=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学科4=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("学科5=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlessonsum()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("总分=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlessonaver()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("平均分=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}
