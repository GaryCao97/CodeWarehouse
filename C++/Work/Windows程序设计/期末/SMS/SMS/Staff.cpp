// Staff.h : CStaff 类的实现



// CStaff 实现

// 代码生成在 2017年6月3日, 8:00

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Username]"), m_Username);
	RFX_Text(pFX, _T("[Post]"), m_Post);
	RFX_Text(pFX, _T("[Duty]"), m_Duty);
	RFX_Text(pFX, _T("[Password]"), m_Password);

}
/////////////////////////////////////////////////////////////////////////////
// CStaff 诊断

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


