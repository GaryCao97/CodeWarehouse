// SortDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "SortDlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"
extern CInformationSet _Set;


// CSortDlg 对话框

IMPLEMENT_DYNAMIC(CSortDlg, CDialogEx)

CSortDlg::CSortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSortDlg::IDD, pParent)
{

}

CSortDlg::~CSortDlg()
{
}

void CSortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_sort_LIST, sort_list);
}


BEGIN_MESSAGE_MAP(CSortDlg, CDialogEx)
	ON_BN_CLICKED(IDC_sort_Return, &CSortDlg::OnBnClickedsortReturn)
	ON_BN_CLICKED(IDC_sort_name, &CSortDlg::OnBnClickedsortname)
	ON_BN_CLICKED(IDC_sort_number, &CSortDlg::OnBnClickedsortnumber)
	ON_BN_CLICKED(IDC_sort_school, &CSortDlg::OnBnClickedsortschool)
	ON_BN_CLICKED(IDC_sort_class, &CSortDlg::OnBnClickedsortclass)
	ON_BN_CLICKED(IDC_sort_Teacher, &CSortDlg::OnBnClickedsortTeacher)
	ON_BN_CLICKED(IDC_sort_lesson1, &CSortDlg::OnBnClickedsortlesson1)
	ON_BN_CLICKED(IDC_sort_lesson2, &CSortDlg::OnBnClickedsortlesson2)
	ON_BN_CLICKED(IDC_sort_lesson3, &CSortDlg::OnBnClickedsortlesson3)
	ON_BN_CLICKED(IDC_sort_lesson4, &CSortDlg::OnBnClickedsortlesson4)
	ON_BN_CLICKED(IDC_sort_lesson5, &CSortDlg::OnBnClickedsortlesson5)
	ON_BN_CLICKED(IDC_sort_lesson_sum, &CSortDlg::OnBnClickedsortlessonsum)
	ON_BN_CLICKED(IDC_sort_lesson_aver, &CSortDlg::OnBnClickedsortlessonaver)
END_MESSAGE_MAP()


// CSortDlg 消息处理程序

void CSortDlg::PaintListItem(void)
{
	sort_list.DeleteAllItems();
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
		sort_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		_Set.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		sort_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			_Set.GetFieldValue((short)j,string);
			sort_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		_Set.MoveNext();
		i++;
		sort_list.SetRedraw(TRUE);
	}
	_Set.Close();
}


BOOL CSortDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if(!_Set.IsOpen())
	_Set.Open();
	sort_list.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE|LVS_EX_AUTOSIZECOLUMNS|LVS_EX_FULLROWSELECT);
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
			sort_list.InsertColumn(i,&Lc);
		}
	}
	_Set.Close();
	CSortDlg::PaintListItem();

	return TRUE;  
}

void CSortDlg::OnBnClickedsortReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CSortDlg::OnCancel();
}


void CSortDlg::OnBnClickedsortname()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("姓名");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortnumber()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学号");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortschool()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学院");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortclass()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("专业班级");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortTeacher()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("辅导员");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson1()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学科1");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson2()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学科2");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson3()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学科3");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson4()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学科4");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson5()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("学科5");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlessonsum()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("总分");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlessonaver()
{
	// TODO: 在此添加控件通知处理程序代码
	_Set.Close();
	_Set.m_strSort = _T("平均分");
	CSortDlg::PaintListItem();
}