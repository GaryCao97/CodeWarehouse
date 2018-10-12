// Staff.h : CStaff ���ʵ��



// CStaff ʵ��

// ���������� 2017��6��3��, 8:00

#include "stdafx.h"
#include "Staff.h"
IMPLEMENT_DYNAMIC(CStaff, CRecordset)

CStaff::CStaff(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Username = L"";
	m_Post = L"";
	m_Duty = L"";
	m_Password = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CStaff::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CStaff::GetDefaultSQL()
{
	return _T("[Staff]");
}

void CStaff::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Username]"), m_Username);
	RFX_Text(pFX, _T("[Post]"), m_Post);
	RFX_Text(pFX, _T("[Duty]"), m_Duty);
	RFX_Text(pFX, _T("[Password]"), m_Password);

}
/////////////////////////////////////////////////////////////////////////////
// CStaff ���

#ifdef _DEBUG
void CStaff::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStaff::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


