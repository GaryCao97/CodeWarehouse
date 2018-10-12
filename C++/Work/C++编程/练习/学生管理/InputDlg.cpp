// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学籍成绩管理.h"
#include "InputDlg.h"
#include "InformationSet.h"
#include "afxdialogex.h"
#include "UserSet.h"
#include "InformationSet.h"
CInformationSet _Set;

// CInputDlg 对话框

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
	, input_class(_T(""))
	, intput_S1(0)
	, intput_S2(0)
	, intput_S3(0)
	, intput_S4(0)
	, intput_S5(0)
	, input_name(_T(""))
	, input_number(_T(""))
	, input_school(_T(""))
	, input_teacher(_T(""))
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_input_Class, input_class);
	DDX_Text(pDX, IDC_input_Lesson1, intput_S1);
	DDX_Text(pDX, IDC_input_Lesson2, intput_S2);
	DDX_Text(pDX, IDC_input_Lesson3, intput_S3);
	DDX_Text(pDX, IDC_input_Lesson4, intput_S4);
	DDX_Text(pDX, IDC_input_Lesson5, intput_S5);
	DDX_Text(pDX, IDC_input_Name, input_name);
	DDX_Text(pDX, IDC_input_Number, input_number);
	DDX_Text(pDX, IDC_input_School, input_school);
	DDX_Text(pDX, IDC_input_Teacher, input_teacher);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_input_Close, &CInputDlg::OnBnClickedinputClose)
	ON_BN_CLICKED(IDC_input_Next, &CInputDlg::OnBnClickedinputNext)
END_MESSAGE_MAP()


// CInputDlg 消息处理程序


void CInputDlg::OnBnClickedinputClose()
{
	// TODO: 在此添加控件通知处理程序代码
	CInputDlg::OnCancel();
}


void CInputDlg::OnBnClickedinputNext()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	if(input_name == str || input_number == str || input_class == str || input_school == str || input_teacher == str)
		MessageBox(_T("请输入完整信息！"),_T("系统提示"));
	else
	{
		if(!_Set.IsOpen())
			_Set.Open();
		_Set.AddNew();
		_Set.m_Name = input_name;
		_Set.m_School = input_school;
		_Set.m_Class = input_class;
		_Set.m_Number = input_number;
		_Set.m_Teacher = input_teacher;
		_Set.m_S1 = intput_S1;
		_Set.m_S2 = intput_S2;
		_Set.m_S3 = intput_S3;
		_Set.m_S4 = intput_S4;
		_Set.m_S5 = intput_S5;
		_Set.m_Sum = intput_S5 + intput_S4 + intput_S3 + intput_S2 + intput_S1;
		_Set.m_Aver = _Set.m_Sum / 5.0;
		_Set.Update();
		_Set.Close();
		input_class = _T("");
		intput_S1 = 0;
		intput_S2 = 0;
		intput_S3 = 0;
		intput_S4 = 0;
		intput_S5 = 0;
		input_name = _T("");
		input_number = _T("");
		input_school = _T("");
		input_teacher = _T("");
		UpdateData(FALSE);
	}

}
