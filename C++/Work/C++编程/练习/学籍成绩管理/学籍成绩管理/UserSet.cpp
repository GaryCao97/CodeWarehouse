// UserSet.h : CUserSet ���ʵ��



// CUserSet ʵ��

// ���������� 2016��5��11��, 22:50

#include "stdafx.h"
#include "UserSet.h"
IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	m_Username = L"";
	m_Password = L"";
	m_SafeQ = L"";
	m_SafeA = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
CString CUserSet::GetDefaultConnect()
{
	return _T("DSN=Data;DBQ=C:\\Data.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
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
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[Username]"), m_Username);
	RFX_Text(pFX, _T("[Password]"), m_Password);
	RFX_Text(pFX, _T("[SafeQ]"), m_SafeQ);
	RFX_Text(pFX, _T("[SafeA]"), m_SafeA);

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


