
// MFCApplication2Set.cpp : CMFCApplication2Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Set ʵ��

// ���������� 2016��5��10��, 19:21

IMPLEMENT_DYNAMIC(CMFCApplication2Set, CRecordset)

CMFCApplication2Set::CMFCApplication2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	m_Name = L"";
	m_Number = L"";
	m_Class = L"";
	m_School = L"";
	m_Teacher = L"";
	m_Score_1 = 0.0;
	m_Score_2 = 0.0;
	m_Score_3 = 0.0;
	m_Score_4 = 0.0;
	m_Score_5 = 0.0;
	m_Score_Sum = 0.0;
	m_Score_Aver = 0.0;
	m_nFields = 13;
	m_nDefaultType = dynaset;
}
#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication2Set::GetDefaultConnect()
{
	return _T("DSN=Data;DBQ=D:\\Visaul Studio\\\x7ec3\x4e60\\\x5b66\x7c4d\x6210\x7ee9\x7ba1\x7406\\\x5b66\x7c4d\x6210\x7ee9\x7ba1\x7406\\Data.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication2Set::GetDefaultSQL()
{
	return _T("[Information]");
}

void CMFCApplication2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Class]"), m_Class);
	RFX_Text(pFX, _T("[School]"), m_School);
	RFX_Text(pFX, _T("[Teacher]"), m_Teacher);
	RFX_Double(pFX, _T("[Score_1]"), m_Score_1);
	RFX_Double(pFX, _T("[Score_2]"), m_Score_2);
	RFX_Double(pFX, _T("[Score_3]"), m_Score_3);
	RFX_Double(pFX, _T("[Score_4]"), m_Score_4);
	RFX_Double(pFX, _T("[Score_5]"), m_Score_5);
	RFX_Double(pFX, _T("[Score_Sum]"), m_Score_Sum);
	RFX_Double(pFX, _T("[Score_Aver]"), m_Score_Aver);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication2Set ���

#ifdef _DEBUG
void CMFCApplication2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

