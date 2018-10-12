// BlogChoose.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "BlogChoose.h"
#include "Blog.h"
#include "BlogM.h"
#include "afxdialogex.h"


// CBlogChoose 对话框

IMPLEMENT_DYNAMIC(CBlogChoose, CDialogEx)

CBlogChoose::CBlogChoose(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BLOG_CHOOSE, pParent)
{

}

CBlogChoose::~CBlogChoose()
{
}

void CBlogChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBlogChoose, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_BLOGM, &CBlogChoose::OnBnClickedBtnBlogm)
	ON_BN_CLICKED(IDC_BTN_BLOG, &CBlogChoose::OnBnClickedBtnBlog)
END_MESSAGE_MAP()


// CBlogChoose 消息处理程序


void CBlogChoose::OnBnClickedBtnBlogm()
{
	// TODO: 在此添加控件通知处理程序代码
	CBlogM bd2;
	bd2.m_sBLOG = m_sBLOG;
	bd2.m_iCommPos = m_iCommPos;
	if (bd2.DoModal() == IDCANCEL)
		CDialogEx::OnCancel();
}


void CBlogChoose::OnBnClickedBtnBlog()
{
	// TODO: 在此添加控件通知处理程序代码
	CBlog bd1;
	bd1.m_sBLOG = m_sBLOG;
	bd1.m_iCommPos = m_iCommPos;
	if (bd1.DoModal() == IDCANCEL)
		CDialogEx::OnCancel();
}
