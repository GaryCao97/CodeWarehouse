// CommOutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "CommOutDlg.h"
#include "afxdialogex.h"


// CCommOutDlg �Ի���

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

	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	m_iYear = st.wYear;
	m_iMouth = st.wMonth;
	m_iDay = st.wDay;
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
	DDX_Text(pDX, IDC_YEAR, m_iYear);
	DDX_Text(pDX, IDC_MOUTH, m_iMouth);
	DDX_Text(pDX, IDC_DAY, m_iDay);
}


BEGIN_MESSAGE_MAP(CCommOutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCommOutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCommOutDlg ��Ϣ�������


BOOL CCommOutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (m_sAddress != _T("")) {
		HBITMAP bitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), m_sAddress, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_picPhoto.SetBitmap(bitmap);
	}
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_YEAR))->SetRange(0, 2333);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_MOUTH))->SetRange(1, 12);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_DAY))->SetRange(1, 31);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CCommOutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strDate;
	strDate.Format(_T("%d��%d��%d��"), m_iYear, m_iMouth, m_iDay);
	if (!CommSet.IsOpen())
		CommSet.Open();
	CommSet.Move(m_iCommPos);
	if (CommSet.m_Inventory > m_llNum) {
		CommSet.Edit();
		CommSet.m_Inventory -= m_llNum;
		CString strNum;
		strNum.Format(_T("%ld"), m_llNum);
		CommSet.m_Blog += strDate + _T(" ������:") + strNum + _T(";");
		CommSet.Update();
		CommSet.Close();
		CDialogEx::OnOK();
	}
	else {
		CommSet.Close();
		MessageBox(_T("��������ȷ����ֵ"), _T("ϵͳ��ʾ"));
	}
}
