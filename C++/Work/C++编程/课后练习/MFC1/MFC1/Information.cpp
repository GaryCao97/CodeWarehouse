// Information.h : CInformation 类的实现



// CInformation 实现

// 代码生成在 2016年5月11日, 22:37

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[编号]"), column1);
	RFX_Text(pFX, _T("[姓名]"), column2);
	RFX_Text(pFX, _T("[学号]"), column3);
	RFX_Text(pFX, _T("[专业班级]"), column4);
	RFX_Text(pFX, _T("[学院]"), column5);
	RFX_Text(pFX, _T("[辅导员]"), column6);
	RFX_Double(pFX, _T("[学科1]"), m_1);
	RFX_Double(pFX, _T("[学科2]"), m_2);
	RFX_Double(pFX, _T("[学科3]"), m_3);
	RFX_Double(pFX, _T("[学科4]"), m_4);
	RFX_Double(pFX, _T("[学科5]"), m_5);
	RFX_Double(pFX, _T("[总分]"), column7);
	RFX_Double(pFX, _T("[平均分]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CInformation 诊断

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


