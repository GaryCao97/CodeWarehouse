// InformationSet.h : CInformationSet ���ʵ��



// CInformationSet ʵ��

// ���������� 2016��5��11��, 22:49

#include "stdafx.h"
#include "InformationSet.h"
IMPLEMENT_DYNAMIC(CInformationSet, CRecordset)

CInformationSet::CInformationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	m_Name = L"";
	m_Number = L"";
	m_School = L"";
	m_Class = L"";
	m_Teacher = L"";
	m_S1 = 0.0;
	m_S2 = 0.0;
	m_S3 = 0.0;
	m_S4 = 0.0;
	m_S5 = 0.0;
	m_Sum = 0.0;
	m_Aver = 0.0;
	m_nFields = 13;
	m_nDefaultType = dynaset;
}
CString CInformationSet::GetDefaultConnect()
{
	return _T("DSN=Data;DBQ=D:\\Data.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CInformationSet::GetDefaultSQL()
{
	return _T("[Information]");
}

void CInformationSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[����]"), m_Name);
	RFX_Text(pFX, _T("[ѧ��]"), m_Number);
	RFX_Text(pFX, _T("[רҵ�༶]"), m_Class);
	RFX_Text(pFX, _T("[ѧԺ]"), m_School);
	RFX_Text(pFX, _T("[����Ա]"), m_Teacher);
	RFX_Double(pFX, _T("[ѧ��1]"), m_S1);
	RFX_Double(pFX, _T("[ѧ��2]"), m_S2);
	RFX_Double(pFX, _T("[ѧ��3]"), m_S3);
	RFX_Double(pFX, _T("[ѧ��4]"), m_S4);
	RFX_Double(pFX, _T("[ѧ��5]"), m_S5);
	RFX_Double(pFX, _T("[�ܷ�]"), m_Sum);
	RFX_Double(pFX, _T("[ƽ����]"), m_Aver);

}
/////////////////////////////////////////////////////////////////////////////
// CInformationSet ���

#ifdef _DEBUG
void CInformationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CInformationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


