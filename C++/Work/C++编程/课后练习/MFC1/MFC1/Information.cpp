// Information.h : CInformation ���ʵ��



// CInformation ʵ��

// ���������� 2016��5��11��, 22:37

#include "stdafx.h"
#include "Information.h"
IMPLEMENT_DYNAMIC(CInformation, CRecordset)

CInformation::CInformation(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	m_1 = 0.0;
	m_2 = 0.0;
	m_3 = 0.0;
	m_4 = 0.0;
	m_5 = 0.0;
	column7 = 0.0;
	column8 = 0.0;
	m_nFields = 13;
	m_nDefaultType = dynaset;
}
CString CInformation::GetDefaultConnect()
{
	return _T("DSN=Data;DBQ=D:\\Visaul Studio\\\x7ec3\x4e60\\\x5b66\x7c4d\x6210\x7ee9\x7ba1\x7406\\\x5b66\x7c4d\x6210\x7ee9\x7ba1\x7406\\Data.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CInformation::GetDefaultSQL()
{
	return _T("[Information]");
}

void CInformation::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[ѧ��]"), column3);
	RFX_Text(pFX, _T("[רҵ�༶]"), column4);
	RFX_Text(pFX, _T("[ѧԺ]"), column5);
	RFX_Text(pFX, _T("[����Ա]"), column6);
	RFX_Double(pFX, _T("[ѧ��1]"), m_1);
	RFX_Double(pFX, _T("[ѧ��2]"), m_2);
	RFX_Double(pFX, _T("[ѧ��3]"), m_3);
	RFX_Double(pFX, _T("[ѧ��4]"), m_4);
	RFX_Double(pFX, _T("[ѧ��5]"), m_5);
	RFX_Double(pFX, _T("[�ܷ�]"), column7);
	RFX_Double(pFX, _T("[ƽ����]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CInformation ���

#ifdef _DEBUG
void CInformation::AssertValid() const
{
	CRecordset::AssertValid();
}

void CInformation::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


