// InfoInputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Student.h"
#include "InfoInputDlg.h"
#include "afxdialogex.h"


// InfoInputDlg �Ի���

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


// InfoInputDlg ��Ϣ�������


void InfoInputDlg::OnBnClickedButtonPhoto()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	wchar_t *filters = L"λͼ�ļ�(*.bmp)|*.bmp|�ɽ���ͼ�θ�ʽ�ļ�(*.gif)|*.gif|����ͼ��ר�����ļ�(*.jpg;*.jpe)|*.jpg;*.jpe|�����ļ�(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp", OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) {
		UpdateData(TRUE);
		m_sPhoto = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}
