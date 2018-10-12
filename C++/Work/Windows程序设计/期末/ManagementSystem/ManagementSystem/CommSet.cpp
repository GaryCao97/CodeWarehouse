// CommSet.h : CCommSet 类的实现



// CCommSet 实现

// 代码生成在 2017年5月27日, 21:17

#include "stdafx.h"
#include "CommSet.h"
IMPLEMENT_DYNAMIC(CCommSet, CRecordset)

CCommSet::CCommSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_CommNum = L"";
	m_CommName = L"";
	m_CommKind = L"";
	m_Introduce = L"";
	m_PhotoAddress = L"";
	m_Origin = L"";
	m_Specifications = L"";
	m_Price = L"";
	m_Inventory = 0;
	m_Blog = L"";
	m_nFields = 11;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CCommSet::GetDefaultConnect()
{
	return _T("DBQ=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Data.mdb;DefaultDir=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\C++\\Windows\x7a0b\x5e8f\x8bbe\x8ba1\\\x671f\x672b\\ManagementSystem\\ManagementSystem\\res\\Database.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CCommSet::GetDefaultSQL()
{
	return _T("[Commodity]");
}

void CCommSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[CommNum]"), m_CommNum);
	RFX_Text(pFX, _T("[CommName]"), m_CommName);
	RFX_Text(pFX, _T("[CommKind]"), m_CommKind);
	RFX_Text(pFX, _T("[Introduce]"), m_Introduce);
	RFX_Text(pFX, _T("[PhotoAddress]"), m_PhotoAddress);
	RFX_Text(pFX, _T("[Origin]"), m_Origin);
	RFX_Text(pFX, _T("[Specifications]"), m_Specifications);
	RFX_Text(pFX, _T("[Price]"), m_Price);
	RFX_Long(pFX, _T("[Inventory]"), m_Inventory);
	RFX_Text(pFX, _T("[Blog]"), m_Blog);

}
/////////////////////////////////////////////////////////////////////////////
// CCommSet 诊断

#ifdef _DEBUG
void CCommSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCommSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


