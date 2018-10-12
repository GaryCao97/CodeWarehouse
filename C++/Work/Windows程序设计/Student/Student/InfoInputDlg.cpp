// InfoInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student.h"
#include "InfoInputDlg.h"
#include "afxdialogex.h"


// InfoInputDlg 对话框

IMPLEMENT_DYNAMIC(InfoInputDlg, CDialogEx)

InfoInputDlg::InfoInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO_INPUT, pParent)
	, m_sName(_T(""))
	, m_sNumber(_T(""))
	, m_sClass(_T(""))
	, m_sPhoto(_T(""))
{

}

InfoInputDlg::~InfoInputDlg()
{
}

void InfoInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_sName);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_sNumber);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_sClass);
	DDX_Text(pDX, IDC_EDIT_PHOTO, m_sPhoto);
}


BEGIN_MESSAGE_MAP(InfoInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PHOTO, &InfoInputDlg::OnBnClickedButtonPhoto)
END_MESSAGE_MAP()


// InfoInputDlg 消息处理程序


void InfoInputDlg::OnBnClickedButtonPhoto()
{
	// TODO: 在此添加控件通知处理程序代码
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|可交换图形格式文件(*.gif)|*.gif|联合图像专家组文件(*.jpg;*.jpe)|*.jpg;*.jpe|所有文件(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp", OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) {
		UpdateData(TRUE);
		m_sPhoto = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}
