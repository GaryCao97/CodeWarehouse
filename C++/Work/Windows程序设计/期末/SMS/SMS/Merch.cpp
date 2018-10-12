// Merch.h : CMerch 类的实现



// CMerch 实现

// 代码生成在 2017年6月3日, 8:01

#include "stdafx.h"
#include "Merch.h"
IMPLEMENT_DYNAMIC(CMerch, CRecordset)

CMerch::CMerch(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Merchnum = L"";
	m_Merchname = L"";
	m_Merchkind = L"";
	m_Price = L"";
	m_Introduction = L"";
	m_Number = 0;
	m_Forms = L"";
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMerch::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\SMS\\SMS\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CMerch::GetDefaultSQL()
{
	return _T("[Merch]");
}

void CMerch::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Merchnum]"), m_Merchnum);
	RFX_Text(pFX, _T("[Merchname]"), m_Merchname);
	RFX_Text(pFX, _T("[Merchkind]"), m_Merchkind);
	RFX_Text(pFX, _T("[Price]"), m_Price);
	RFX_Text(pFX, _T("[Introduction]"), m_Introduction);
	RFX_Long(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Forms]"), m_Forms);

}
/////////////////////////////////////////////////////////////////////////////
// CMerch 诊断

#ifdef _DEBUG
void CMerch::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMerch::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


