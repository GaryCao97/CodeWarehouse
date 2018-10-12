// UserInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "UserInfo.h"
#include "afxdialogex.h"


// CUserInfo 对话框

IMPLEMENT_DYNAMIC(CUserInfo, CDialogEx)

CUserInfo::CUserInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_USER_INFO, pParent)
	, m_sUsername(_T(""))
	, m_sNumber(_T(""))
	, m_sDuty(_T(""))
	, m_sYzm1(_T(""))
	, m_sYzm2(_T(""))
	, m_iStyle(-1)
	, m_sRealName(_T(""))
	, m_bNorA(false)
	, m_sKind(_T(""))
{

}

CUserInfo::~CUserInfo()
{
}

void CUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_UI_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_UI_NUMBER, m_sNumber);
	DDX_Text(pDX, IDC_UI_DUTY, m_sDuty);
	DDX_Text(pDX, IDC_UI_YZM1, m_sYzm1);
	DDX_Text(pDX, IDC_UI_YZM2, m_sYzm2);
	DDX_Text(pDX, IDC_UI_REALNAME, m_sRealName);
	DDX_CBString(pDX, IDC_UI_KIND, m_sKind);
}


BEGIN_MESSAGE_MAP(CUserInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CUserInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CUserInfo 消息处理程序

BOOL CUserInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_bNorA) {
		GetDlgItem(IDC_UI_NUMBER)->EnableWindow(FALSE);
		GetDlgItem(IDC_UI_KIND)->EnableWindow(FALSE);
		GetDlgItem(IDC_UI_DUTY)->EnableWindow(FALSE);
	}
	m_sYzm2 = GetYzm();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CUserInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString yzm1 = m_sYzm1;
	CString yzm2 = m_sYzm2;
	yzm1 = yzm1.MakeLower();
	yzm2 = yzm2.MakeLower();
	if (yzm1 != yzm2) {
		MessageBox(_T("验证码错误！"), _T("系统提示"));
		CUserInfo::OnInitDialog();
	}
	else {
		if (!UserSet.IsOpen())
			UserSet.Open();
		if (m_iStyle == -1) {
			if (m_sNumber == _T("") || m_sUsername == _T("") || m_sDuty == _T("") || m_sKind == _T(""))
				MessageBox(_T("请输入完整信息！"), _T("系统提示"));
			else
			{
				CODBCFieldInfo info;
				if (UserSet.IsOpen())
					UserSet.Close();
				UserSet.m_strFilter = _T("Username='") + m_sUsername + _T("'");
				if (!UserSet.IsOpen())
					UserSet.Open();
				if (!UserSet.IsEOF()) {
					UserSet.Close();
					UserSet.m_strFilter = _T("");
					UserSet.Open(); 
					MessageBox(_T("用户名已存在！"), _T("系统提示")); }
				else{
					UserSet.Close();
					UserSet.m_strFilter = _T("");
					UserSet.Open();
					UserSet.AddNew();
					UserSet.m_Username = m_sUsername;
					UserSet.m_Realname = m_sRealName;
					UserSet.m_Duty = m_sDuty;
					UserSet.m_Kind = m_sKind;
					UserSet.m_Number = m_sNumber;
					UserSet.m_Password = m_sNumber.Right(6);
					UserSet.Update();
					UserSet.Close();
					UpdateData(FALSE);
					CDialogEx::OnOK();
				}
			}
		}
		else {
			UserSet.Move(m_iStyle);
			UserSet.Edit();
			UserSet.m_Username = m_sUsername;
			UserSet.m_Realname = m_sRealName;
			UserSet.m_Duty = m_sDuty;
			UserSet.m_Kind = m_sKind;
			UserSet.m_Number = m_sNumber;
			UserSet.Update();
			UserSet.Close();
			UpdateData(FALSE);
			CDialogEx::OnOK();
		}
		UserSet.Close();
	}
}
