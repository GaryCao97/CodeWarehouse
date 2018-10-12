// Merch.h : CMerch ���ʵ��



// CMerch ʵ��

// ���������� 2017��6��3��, 8:01

#include "stdafx.h"
#include "Merch.h"
IMPLEMENT_DYNAMIC(CMerch, CRecordset)

CMerch::CMerch(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Merchnum = L"";
	m_Merchname = L"";
	m_Merchkind = L"";
	m_Price = L"";
	m_Introduction = L"";
	m_Number = 0;
	m_Forms = L"";
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMerch::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CMerch::GetDefaultSQL()
{
	return _T("[Merch]");
}

void CMerch::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Merchnum]"), m_Merchnum);
	RFX_Text(pFX, _T("[Merchname]"), m_Merchname);
	RFX_Text(pFX, _T("[Merchkind]"), m_Merchkind);
	RFX_Text(pFX, _T("[Price]"), m_Price);
	RFX_Text(pFX, _T("[Introduction]"), m_Introduction);
	RFX_Long(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Forms]"), m_Forms);

}
/////////////////////////////////////////////////////////////////////////////
// CMerch ���

#ifdef _DEBUG
void CMerch::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMerch::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


