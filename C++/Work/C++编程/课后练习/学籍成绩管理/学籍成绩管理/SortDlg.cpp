// SortDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "SortDlg.h"
#include "UserSet.h"
#include "InformationSet.h"
#include "afxdialogex.h"
extern CInformationSet _Set;


// CSortDlg �Ի���

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


// CSortDlg ��Ϣ�������

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
			sort_list.InsertColumn(i,&Lc);
		}
	}
	_Set.Close();
	CSortDlg::PaintListItem();

	return TRUE;  
}

void CSortDlg::OnBnClickedsortReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSortDlg::OnCancel();
}


void CSortDlg::OnBnClickedsortname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("����");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortnumber()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortschool()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧԺ");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortclass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("רҵ�༶");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortTeacher()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("����Ա");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��1");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��2");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��3");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��4");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlesson5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ѧ��5");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlessonsum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("�ܷ�");
	CSortDlg::PaintListItem();
}


void CSortDlg::OnBnClickedsortlessonaver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_Set.Close();
	_Set.m_strSort = _T("ƽ����");
	CSortDlg::PaintListItem();
}