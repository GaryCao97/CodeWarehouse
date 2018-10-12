// CommSet.h : CCommSet ���ʵ��



// CCommSet ʵ��

// ���������� 2017��5��27��, 21:17

#include "stdafx.h"
#include "CommSet.h"
IMPLEMENT_DYNAMIC(CCommSet, CRecordset)

CCommSet::CCommSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_CommNum = L"";
	m_CommName = L"";
	m_CommKind = L"";
	m_Introduce = L"";
	m_PhotoAddress = L"";
	m_Origin = L"";
	m_Specifications = L"";
	m_Price = L"";
	m_Inventory = 0;
	m_Blog = L"";
	m_nFields = 11;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CCommSet::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CCommSet::GetDefaultSQL()
{
	return _T("[Commodity]");
}

void CCommSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[CommNum]"), m_CommNum);
	RFX_Text(pFX, _T("[CommName]"), m_CommName);
	RFX_Text(pFX, _T("[CommKind]"), m_CommKind);
	RFX_Text(pFX, _T("[Introduce]"), m_Introduce);
	RFX_Text(pFX, _T("[PhotoAddress]"), m_PhotoAddress);
	RFX_Text(pFX, _T("[Origin]"), m_Origin);
	RFX_Text(pFX, _T("[Specifications]"), m_Specifications);
	RFX_Text(pFX, _T("[Price]"), m_Price);
	RFX_Long(pFX, _T("[Inventory]"), m_Inventory);
	RFX_Text(pFX, _T("[Blog]"), m_Blog);

}
/////////////////////////////////////////////////////////////////////////////
// CCommSet ���

#ifdef _DEBUG
void CCommSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCommSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


