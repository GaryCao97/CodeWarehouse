// UserSet.h : CUserSet ���ʵ��



// CUserSet ʵ��

// ���������� 2017��5��9��, 17:11

#include "stdafx.h"
#include "UserSet.h"
IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Username = L"";
	m_Number = L"";
	m_Realname = L"";
	m_Kind = L"";
	m_Duty = L"";
	m_Password = L"";
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CUserSet::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CUserSet::GetDefaultSQL()
{
	return _T("[User]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Username]"), m_Username);
	RFX_Text(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Realname]"), m_Realname);
	RFX_Text(pFX, _T("[Kind]"), m_Kind);
	RFX_Text(pFX, _T("[Duty]"), m_Duty);
	RFX_Text(pFX, _T("[Password]"), m_Password);

}
/////////////////////////////////////////////////////////////////////////////
// CUserSet ���

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


