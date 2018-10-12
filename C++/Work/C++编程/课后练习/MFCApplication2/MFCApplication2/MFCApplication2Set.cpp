
// MFCApplication2Set.cpp : CMFCApplication2Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Set 实现

// 代码生成在 2016年5月10日, 19:21

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
#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[编号]"), column1);
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
// CMFCApplication2Set 诊断

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

