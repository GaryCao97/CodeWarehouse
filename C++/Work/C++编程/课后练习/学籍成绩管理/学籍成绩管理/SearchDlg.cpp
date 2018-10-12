// SearchDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "SearchDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CInformationSet _Set;


// CSearchDlg �Ի���

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


// CSearchDlg ��Ϣ�������


void CSearchDlg::OnBnClickedsearchReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("����¼������"),_T("ϵͳ��ʾ"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("����='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchnumber()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchschool()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧԺ='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchclass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("רҵ�༶='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchteacher()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("����Ա='") + search_edit + _T("'");
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��1=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��2=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��3=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��4=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlesson5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ѧ��5=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlessonsum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("�ܷ�=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}


void CSearchDlg::OnBnClickedsearchlessonaver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_Set.Close();
	_Set.m_strFilter = _T("ƽ����=") + search_edit;
	CSearchDlg::PaintListItem();
	_Set.m_strFilter = _T("");
	UpdateData(FALSE);
}
