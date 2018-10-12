// OutputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����.h"
#include "OutputDlg.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
extern CInformationSet _Set;


// COutputDlg �Ի���

IMPLEMENT_DYNAMIC(COutputDlg, CDialogEx)

COutputDlg::COutputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COutputDlg::IDD, pParent)
{
	
}

COutputDlg::~COutputDlg()
{
}

void COutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_output_List, output_list);
}


BEGIN_MESSAGE_MAP(COutputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_output_Return, &COutputDlg::OnBnClickedoutputReturn)
END_MESSAGE_MAP()


// COutputDlg ��Ϣ�������

BOOL COutputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if(!_Set.IsOpen())
	_Set.Open();
	output_list.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE|LVS_EX_AUTOSIZECOLUMNS|LVS_EX_FULLROWSELECT);
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
			Lc.pszText = DbFi.m_strName.GetBuffer(DbFi.m_strName.GetLength());
			output_list.InsertColumn(i,&Lc);
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
		output_list.SetRedraw(FALSE);
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		_Set.GetFieldValue((short)0,string);
		item.pszText = string.GetBuffer(string.GetLength());
		output_list.InsertItem(&item);
		for(j = 1;j < 13;j++)
		{
			_Set.GetFieldValue((short)j,string);
			output_list.SetItemText(i,j,string.GetBuffer(string.GetLength()));
		}
		_Set.MoveNext();
		i++;
		output_list.SetRedraw(TRUE);
	}
	
	_Set.Close();
	return TRUE;  

}


void COutputDlg::OnBnClickedoutputReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	COutputDlg::OnCancel();
}



