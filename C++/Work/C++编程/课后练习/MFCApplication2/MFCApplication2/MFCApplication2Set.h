
// MFCApplication2Set.h: CMFCApplication2Set 类的接口
//


#pragma once

// 代码生成在 2016年5月10日, 19:21

class CMFCApplication2Set : public CRecordset
{
public:
	CMFCApplication2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMFCApplication2Set)

// 字段/参数数据

// 以下字符串类型(如果存在)反映数据库字段(ANSI 数据类型的 CStringA 和 Unicode
// 数据类型的 CStringW)的实际数据类型。
//  这是为防止 ODBC 驱动程序执行可能
// 不必要的转换。如果希望，可以将这些成员更改为
// CString 类型，ODBC 驱动程序将执行所有必要的转换。
// (注意: 必须使用 3.5 版或更高版本的 ODBC 驱动程序
// 以同时支持 Unicode 和这些转换)。

	long	column1;
	CStringW	m_Name;
	CStringW	m_Number;
	CStringW	m_Class;
	CStringW	m_School;
	CStringW	m_Teacher;
	double	m_Score_1;
	double	m_Score_2;
	double	m_Score_3;
	double	m_Score_4;
	double	m_Score_5;
	double	m_Score_Sum;
	double	m_Score_Aver;

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

