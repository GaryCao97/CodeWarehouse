// CommOutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "CommOutDlg.h"
#include "afxdialogex.h"


// CCommOutDlg 对话框

IMPLEMENT_DYNAMIC(CCommOutDlg, CDialogEx)

CCommOutDlg::CCommOutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMM_OUT, pParent)
	, m_sCommName(_T(""))
	, m_sCommNum(_T(""))
	, m_sCommKind(_T(""))
	, m_sSpecifi(_T(""))
	, m_sPrice(_T(""))
	, m_llNum(0)
	, m_iCommPos(0)
	, m_sAddress(_T(""))
{

}

CCommOutDlg::~CCommOutDlg()
{
}

void CCommOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COMMNAME, m_sCommName);
	DDX_Text(pDX, IDC_COMMNUM, m_sCommNum);
	DDX_Text(pDX, IDC_COMMKIND, m_sCommKind);
	DDX_Text(pDX, IDC_SPECIFI, m_sSpecifi);
	DDX_Text(pDX, IDC_PRICE, m_sPrice);
	DDX_Text(pDX, IDC_NUM, m_llNum);
	DDX_Control(pDX, IDC_PIC_PHOTO, m_picPhoto);
}


BEGIN_MESSAGE_MAP(CCommOutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCommOutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCommOutDlg 消息处理程序


BOOL CCommOutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_sAddress != _T("")) {
		HBITMAP bitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), m_sAddress, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_picPhoto.SetBitmap(bitmap);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCommOutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	if (CommSet.m_Inventory > m_llNum) {
		CommSet.Edit();
		CommSet.m_Inventory -= m_llNum;
		CommSet.Update();
		CommSet.Close();
		CDialogEx::OnOK();
	}
	else {
		CommSet.Close();
		MessageBox(_T("请输入正确的数值"), _T("系统提示"));
	}
}
