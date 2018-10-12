// InformationSet.h : CInformationSet 类的实现



// CInformationSet 实现

// 代码生成在 2016年5月11日, 22:49

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[编号]"), column1);
	RFX_Text(pFX, _T("[姓名]"), m_Name);
	RFX_Text(pFX, _T("[学号]"), m_Number);
	RFX_Text(pFX, _T("[专业班级]"), m_Class);
	RFX_Text(pFX, _T("[学院]"), m_School);
	RFX_Text(pFX, _T("[辅导员]"), m_Teacher);
	RFX_Double(pFX, _T("[学科1]"), m_S1);
	RFX_Double(pFX, _T("[学科2]"), m_S2);
	RFX_Double(pFX, _T("[学科3]"), m_S3);
	RFX_Double(pFX, _T("[学科4]"), m_S4);
	RFX_Double(pFX, _T("[学科5]"), m_S5);
	RFX_Double(pFX, _T("[总分]"), m_Sum);
	RFX_Double(pFX, _T("[平均分]"), m_Aver);

}
/////////////////////////////////////////////////////////////////////////////
// CInformationSet 诊断

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


