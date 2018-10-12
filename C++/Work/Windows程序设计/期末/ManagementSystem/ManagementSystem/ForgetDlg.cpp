// ForgetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "ForgetDlg.h"
#include "afxdialogex.h"


// CForgetDlg 对话框

IMPLEMENT_DYNAMIC(CForgetDlg, CDialogEx)

CForgetDlg::CForgetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORGET, pParent)
	, m_sUsername(_T(""))
	, m_sNumber(_T(""))
	, m_sPassword1(_T(""))
	, m_sPassword2(_T(""))
	, m_sYzm1(_T(""))
	, m_sYzm2(_T(""))
{

}

CForgetDlg::~CForgetDlg()
{
}

void CForgetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_F_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_F_NUMBER, m_sNumber);
	DDX_Text(pDX, IDC_F_PASSWORD1, m_sPassword1);
	DDX_Text(pDX, IDC_F_PASSWORD2, m_sPassword2);
	DDX_Text(pDX, IDC_F_YZM1, m_sYzm1);
	DDX_Text(pDX, IDC_F_YZM2, m_sYzm2);
}


BEGIN_MESSAGE_MAP(CForgetDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CForgetDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CForgetDlg 消息处理程序


BOOL CForgetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_sYzm2 = GetYzm();
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CForgetDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString yzm1 = m_sYzm1;
	CString yzm2 = m_sYzm2;
	yzm1 = yzm1.MakeLower();
	yzm2 = yzm2.MakeLower();
	if (yzm1 != yzm2) {
		MessageBox(_T("验证码错误！"), _T("系统提示"));
		CForgetDlg::OnInitDialog();
	}
	else if (m_sPassword1 != m_sPassword2){
		MessageBox(_T("两次密码应该相同！"), _T("系统提示"));
		CForgetDlg::OnInitDialog();
	}
	else {
		if (!UserSet.IsOpen())
			UserSet.Open();
		UserSet.Move(0);
		int n = 0;
		while (!UserSet.IsEOF()){
			if (m_sNumber != (CString)UserSet.m_Number)
				UserSet.MoveNext();
			else if (m_sUsername != (CString)UserSet.m_Username) {
				MessageBox(_T("请输入正确的用户名！"), _T("系统提示"));
				break;
			}
			else {
				n = 1;
				UserSet.Edit();
				UserSet.m_Password = m_sPassword1;
				UserSet.Update();
				MessageBox(_T("修改成功！"), _T("系统提示"));
				break;
			}
		}
		UserSet.Close();
		if (n == 1)
			CDialogEx::OnOK();
	}
	UpdateData(FALSE);
}
