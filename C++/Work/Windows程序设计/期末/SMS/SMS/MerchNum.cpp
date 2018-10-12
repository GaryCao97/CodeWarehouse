// MerchNum.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SMS.h"
#include "MerchNum.h"
#include "afxdialogex.h"


// CMerchNum �Ի���

IMPLEMENT_DYNAMIC(CMerchNum, CDialogEx)

CMerchNum::CMerchNum(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MERCH_NUM, pParent)
	, m_llNum(0)
	, m_sTag(_T(""))
	, m_sMerchnum(_T(""))
	, m_sMerchname(_T(""))
	, m_sMerchkind(_T(""))
	, m_sPrice(_T(""))
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	m_iYear = st.wYear;
	m_iMonth = st.wMonth;
	m_iDay = st.wDay;
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	m_sMerchnum = MerchSet.m_Merchnum;
	m_sPrice = MerchSet.m_Price;
	m_sMerchkind = MerchSet.m_Merchkind;
	m_sMerchname = MerchSet.m_Merchname;
	MerchSet.Close();
}

CMerchNum::~CMerchNum()
{
}

void CMerchNum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM, m_llNum);
	DDX_Text(pDX, IDC_TAG, m_sTag);
	DDX_Text(pDX, IDC_YEAR, m_iYear);
	DDX_Text(pDX, IDC_MONTH, m_iMonth);
	DDX_Text(pDX, IDC_DAY, m_iDay);
	DDX_Text(pDX, IDC_MERCHNUM, m_sMerchnum);
	DDX_Text(pDX, IDC_MERCHNAME, m_sMerchname);
	DDX_Control(pDX, IDC_MERCHKIND, m_comboMerchkind);
	DDX_CBString(pDX, IDC_MERCHKIND, m_sMerchkind);
	DDX_Text(pDX, IDC_PRICE, m_sPrice);
}


BEGIN_MESSAGE_MAP(CMerchNum, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMerchNum::OnBnClickedOk)
END_MESSAGE_MAP()


// CMerchNum ��Ϣ�������


BOOL CMerchNum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_comboMerchkind.AddString(m_sMerchkind);
	m_comboMerchkind.SetCurSel(0);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_YEAR))->SetRange(0, 2333);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_MONTH))->SetRange(1, 12);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_DAY))->SetRange(1, 31);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CMerchNum::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strDate, strNum;
	strDate.Format(_T("%d��%d��%d��"), m_iYear, m_iMonth, m_iDay);
	strNum.Format(_T("%ld"), m_llNum);
	if (!MerchSet.IsOpen())
		MerchSet.Open();
	MerchSet.Move(m_iMerchPos);
	if (m_sTag == _T("��������") && m_llNum <= MerchSet.m_Number) {
		MerchSet.Edit();
		MerchSet.m_Number -= m_llNum;
		MerchSet.m_Forms += strDate + _T(" ������:") + strNum + _T(";");
		MerchSet.Update();
		MerchSet.Close();
		CDialogEx::OnOK();
	}
	else if(m_sTag == _T("��������") && m_llNum > 0) {
		MerchSet.Edit();
		MerchSet.m_Number += m_llNum;
		MerchSet.m_Forms += strDate + _T(" ������:") + strNum + _T(";");
		MerchSet.Update();
		MerchSet.Close();
		CDialogEx::OnOK();
	}
	else {
		MerchSet.Close();
		MessageBox(_T("��������ȷ����ֵ"), _T("ϵͳ��ʾ"));
	}
}
