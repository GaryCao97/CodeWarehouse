// BlogChoose.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "BlogChoose.h"
#include "Blog.h"
#include "BlogM.h"
#include "afxdialogex.h"


// CBlogChoose �Ի���

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


// CBlogChoose ��Ϣ�������


void CBlogChoose::OnBnClickedBtnBlogm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBlogM bd2;
	bd2.m_sBLOG = m_sBLOG;
	bd2.m_iCommPos = m_iCommPos;
	if (bd2.DoModal() == IDCANCEL)
		CDialogEx::OnCancel();
}


void CBlogChoose::OnBnClickedBtnBlog()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBlog bd1;
	bd1.m_sBLOG = m_sBLOG;
	bd1.m_iCommPos = m_iCommPos;
	if (bd1.DoModal() == IDCANCEL)
		CDialogEx::OnCancel();
}
