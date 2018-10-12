// MerchOne.cpp : 实现文件
//

#include "stdafx.h"
#include "SMS.h"
#include "MerchOne.h"
#include "afxdialogex.h"


// CMerchOne 对话框

IMPLEMENT_DYNAMIC(CMerchOne, CDialogEx)

CMerchOne::CMerchOne(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MERCH_ONE, pParent)
	, m_sIntroduct(_T(""))
	, m_sMerchkind(_T(""))
	, m_sMerchname(_T(""))
	, m_sMerchnum(_T(""))
	, m_sPrice(_T(""))
	, m_bIsAdd(true)
{

}

CMerchOne::~CMerchOne()
{
}

void CMerchOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INTRODUCT, m_sIntroduct);
	DDX_Control(pDX, IDC_MERCHKIND, m_comboMerchkind);
	DDX_CBString(pDX, IDC_MERCHKIND, m_sMerchkind);
	DDX_Text(pDX, IDC_MERCHNAME, m_sMerchname);
	DDX_Text(pDX, IDC_MERCHNUM, m_sMerchnum);
	DDX_Text(pDX, IDC_PRICE, m_sPrice);
}


BEGIN_MESSAGE_MAP(CMerchOne, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMerchOne::OnBnClickedOk)
END_MESSAGE_MAP()


// CMerchOne 消息处理程序


BOOL CMerchOne::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (m_bIsAdd) {
		for (int i = 0; i < m_saDuty->GetCount(); i++) 
			m_comboMerchkind.AddString((*m_saDuty)[i]);
	}
	else {
		m_sMerchkind;
		m_comboMerchkind.AddString(m_sMerchkind);
		m_comboMerchkind.SetCurSel(0);
		m_comboMerchkind.EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMerchOne::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_bIsAdd) {
		if (m_sMerchkind == _T("") || m_sMerchname == _T("") || m_sMerchnum == _T(""))
			MessageBox(_T("请输入完整信息！"), _T("系统提示"));
		else {
			if (MerchSet.IsOpen())
				MerchSet.Close();
			MerchSet.m_strFilter = _T("Merchnum='") + m_sMerchnum + _T("'");
			MerchSet.Open();
			if (!MerchSet.IsEOF()) {
				MerchSet.Close();
				MerchSet.m_strFilter = _T("");
				MessageBox(_T("商品号已存在！"), _T("系统提示"));
			}
			else {
				MerchSet.Close();
				MerchSet.m_strFilter = _T("");
				MerchSet.Open();
				MerchSet.AddNew();
				MerchSet.m_Merchkind = m_sMerchkind;
				MerchSet.m_Merchname = m_sMerchname;
				MerchSet.m_Merchnum = m_sMerchnum;
				MerchSet.m_Introduction = m_sIntroduct;
				MerchSet.m_Price = m_sPrice;
				MerchSet.Update();
				MerchSet.Close();
				CDialogEx::OnOK();
			}
		}
	}
	else {
		MerchSet.Move(m_iMerchPos);
		MerchSet.Edit();
		MerchSet.m_Merchkind = m_sMerchkind;
		MerchSet.m_Merchname = m_sMerchname;
		MerchSet.m_Merchnum = m_sMerchnum;
		MerchSet.m_Introduction = m_sIntroduct;
		MerchSet.m_Price = m_sPrice;
		MerchSet.Update();
		MerchSet.Close();
		UpdateData(FALSE);
		CDialogEx::OnOK();
	}
}
