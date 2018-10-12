// CommInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "CommInfo.h"
#include "afxdialogex.h"


// CCommInfo 对话框

IMPLEMENT_DYNAMIC(CCommInfo, CDialogEx)

CCommInfo::CCommInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMM_INFO, pParent)
	, m_sCommName(_T(""))
	, m_sCommNum(_T(""))
	, m_sCommKind(_T(""))
	, m_sIntroduce(_T(""))
	, m_sOrigin(_T(""))
	, m_sSpecification(_T(""))
	, m_sPrice(_T(""))
	, m_sPhotoAddress(_T(""))
	, m_iUserPos(-1)
	, m_iCommPos(-1)
{

}

CCommInfo::~CCommInfo()
{
}

void CCommInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CI_COMMNAME, m_sCommName);
	DDX_Text(pDX, IDC_CI_COMMNUM, m_sCommNum);
	DDX_Text(pDX, IDC_CI_COMMKIND, m_sCommKind);
	DDX_Text(pDX, IDC_CI_INTRODUCE, m_sIntroduce);
	DDX_Text(pDX, IDC_CI_ORIGIN, m_sOrigin);
	DDX_Text(pDX, IDC_CI_SPECIFI, m_sSpecification);
	DDX_Text(pDX, IDC_CI_PRICE, m_sPrice);
	DDX_Text(pDX, IDC_CI_PHOTO, m_sPhotoAddress);
	DDX_Control(pDX, IDC_PIC_PHOTO, m_picPhoto);
}


BEGIN_MESSAGE_MAP(CCommInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_PHOTO, &CCommInfo::OnBnClickedBtnPhoto)
	ON_BN_CLICKED(IDOK, &CCommInfo::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCommInfo::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCommInfo 消息处理程序


BOOL CCommInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_sPhotoAddress != _T("")) {
		HBITMAP bitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), m_sPhotoAddress, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_picPhoto.SetBitmap(bitmap);
	}
	if (m_iCommPos >= 0) {
		GetDlgItem(IDC_CI_COMMNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_CI_COMMNUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_CI_COMMKIND)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCommInfo::OnBnClickedBtnPhoto()
{
	// TODO: 在此添加控件通知处理程序代码
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|所有文件(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) {
		UpdateData(TRUE);
		m_sPhotoAddress = fileDlg.GetPathName();
		HBITMAP bitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), m_sPhotoAddress, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_picPhoto.SetBitmap(bitmap);
		UpdateData(FALSE);
	}
}


void CCommInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码if (!UserSet.IsOpen())
	UpdateData(TRUE);
	CommSet.Open();
	if (m_iCommPos == -1) {
		if (m_sCommNum == _T("") ||	m_sCommName == _T("") || m_sCommKind == _T(""))
			MessageBox(_T("请输入完整信息！"), _T("系统提示"));
		else
		{
			CODBCFieldInfo info;
			if (CommSet.IsOpen())
				CommSet.Close();
			CommSet.m_strFilter = _T("CommNum='") + m_sCommNum + _T("'");
			CommSet.Open();
			if (!CommSet.IsEOF()) {
				CommSet.Close();
				CommSet.m_strFilter = _T("");
				MessageBox(_T("商品号已存在！"), _T("系统提示"));
			}
			else {
				CommSet.Close();
				CommSet.m_strFilter = _T("");
				if (!UserSet.IsOpen())UserSet.Open();
				UserSet.Move(m_iUserPos);
				if (isItInString(UserSet.m_Duty, m_sCommKind)) {
					CommSet.Open();
					CommSet.AddNew();
					CommSet.m_CommNum = m_sCommNum;
					CommSet.m_CommName = m_sCommName;
					CommSet.m_CommKind = m_sCommKind;
					CommSet.m_PhotoAddress = m_sPhotoAddress;
					CommSet.m_Origin = m_sOrigin;
					CommSet.m_Introduce = m_sIntroduce;
					CommSet.m_Specifications = m_sSpecification;
					CommSet.m_Price = m_sPrice;
					CommSet.Update();
					CommSet.Close();
				}
				else MessageBox(_T("用户添加的商品类型不符合！"), _T("系统提示"));
				UserSet.Close();
				UpdateData(FALSE);
				CDialogEx::OnOK();
			}
		}
	}
	else {
		CommSet.Move(m_iCommPos);
		CommSet.Edit();
		CommSet.m_CommNum = m_sCommNum;
		CommSet.m_CommName = m_sCommName;
		CommSet.m_CommKind = m_sCommKind;
		CommSet.m_PhotoAddress = m_sPhotoAddress;
		CommSet.m_Origin = m_sOrigin;
		CommSet.m_Introduce = m_sIntroduce;
		CommSet.m_Specifications = m_sSpecification;
		CommSet.m_Price = m_sPrice;
		CommSet.Update();
		CommSet.Close();
		UpdateData(FALSE);
		CDialogEx::OnOK();
	}
	CommSet.Close();
}


void CCommInfo::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

