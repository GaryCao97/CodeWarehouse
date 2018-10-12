// ChangeiDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "ChangeiDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CInformationSet _Set;


// CChangeiDlg 对话框

IMPLEMENT_DYNAMIC(CChangeiDlg, CDialogEx)

CChangeiDlg::CChangeiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeiDlg::IDD, pParent)
	, changei_class(_T(""))
	, changei_S1(0)
	, changei_S2(0)
	, changei_S3(0)
	, changei_S4(0)
	, changei_S5(0)
	, changei_name(_T(""))
	, changei_number(_T(""))
	, changei_school(_T(""))
	, changei_teacher(_T(""))
{

}

CChangeiDlg::~CChangeiDlg()
{
}

void CChangeiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_changei_LIST, changei_list);
	DDX_Text(pDX, IDC_changei_Class, changei_class);
	DDX_Text(pDX, IDC_changei_Lesson1, changei_S1);
	DDX_Text(pDX, IDC_changei_Lesson2, changei_S2);
	DDX_Text(pDX, IDC_changei_Lesson3, changei_S3);
	DDX_Text(pDX, IDC_changei_Lesson4, changei_S4);
	DDX_Text(pDX, IDC_changei_Lesson5, changei_S5);
	DDX_Text(pDX, IDC_changei_Name, changei_name);
	DDX_Text(pDX, IDC_changei_Number, changei_number);
	DDX_Text(pDX, IDC_changei_School, changei_school);
	DDX_Text(pDX, IDC_changei_Teacher, changei_teacher);
}


BEGIN_MESSAGE_MAP(CChangeiDlg, CDialogEx)
	ON_BN_CLICKED(IDC_changei_Return, &CChangeiDlg::OnBnClickedchangeiReturn)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_changei_LIST, &CChangeiDlg::OnLvnItemActivatechangeiList)
	ON_BN_CLICKED(IDC_changei_Change, &CChangeiDlg::OnBnClickedchangeiChange)
	ON_BN_CLICKED(IDC_changei_Delete, &CChangeiDlg::OnBnClickedchangeiDelete)
END_MESSAGE_MAP()


// CChangeiDlg 消息处理程序


void CChangeiDlg::OnBnClickedchangeiReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CChangeiDlg::OnCancel();
}

void CChangeiDlg::PaintListItem(void)
{
	
	changei_list.DeleteAllItems();
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
		changei_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		_Set.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		changei_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			_Set.GetFieldValue((short)j,string);
			changei_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		_Set.MoveNext();
		i++;
		changei_list.SetRedraw(TRUE);
	}
	_Set.Close();
}

BOOL CChangeiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if(!_Set.IsOpen())
		_Set.Open();
	changei_list.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE|LVS_EX_AUTOSIZECOLUMNS|LVS_EX_FULLROWSELECT);
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
			Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
			changei_list.InsertColumn(i,&Lc);
		}
	}
	_Set.Close();
	CChangeiDlg::PaintListItem();
	return TRUE;  
}


void CChangeiDlg::OnLvnItemActivatechangeiList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	UpdateData(TRUE);
	int pos;
	pos = changei_list.GetSelectionMark();
	if(!_Set.IsOpen())
		_Set.Open();
	_Set.Move(pos);
	changei_class = _Set.m_Class;
	changei_name = _Set.m_Name;
	changei_number = _Set.m_Number;
	changei_school = _Set.m_School;
	changei_teacher = _Set.m_Teacher;
	changei_S1 = _Set.m_S1;
	changei_S2 = _Set.m_S2;
	changei_S3 = _Set.m_S3;
	changei_S4 = _Set.m_S4;
	changei_S5 = _Set.m_S5;
	_Set.Close();
	UpdateData(FALSE);
}


void CChangeiDlg::OnBnClickedchangeiChange()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int pos;
	pos = changei_list.GetSelectionMark();
	if(!_Set.IsOpen())
		_Set.Open();
	_Set.Move(pos);
	_Set.Edit();
	_Set.m_Class = (CStringW)changei_class;
	_Set.m_Name = (CStringW)changei_name;
	_Set.m_Number = (CStringW)changei_number;
	_Set.m_School = (CStringW)changei_school;
	_Set.m_Teacher = (CStringW)changei_teacher;
	_Set.m_S1 = changei_S1;
	_Set.m_S2 = changei_S2;
	_Set.m_S3 = changei_S3;
	_Set.m_S4 = changei_S4;
	_Set.m_S5 = changei_S5;
	_Set.m_Sum = changei_S1 + changei_S2 + changei_S3 + changei_S4 + changei_S5;
	_Set.m_Aver = _Set.m_Sum / 5.0;
	_Set.Update();
	_Set.Close();
	CChangeiDlg::PaintListItem();
	UpdateData(FALSE);
}



void CChangeiDlg::OnBnClickedchangeiDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int pos;
	pos = changei_list.GetSelectionMark();
	if(!_Set.IsOpen())
		_Set.Open();
	_Set.Move(pos);
	_Set.Delete();
	_Set.Close();
	CChangeiDlg::PaintListItem();
	UpdateData(FALSE);
}
