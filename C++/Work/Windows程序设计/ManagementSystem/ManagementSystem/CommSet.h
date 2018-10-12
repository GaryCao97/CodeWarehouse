
#pragma once
#include <list> 
#include <fstream>
using namespace std;

typedef struct {
	long		m_ID;
	CStringW	m_CommNum;
	CStringW	m_CommName;
	CStringW	m_CommKind;
	CStringW	m_Introduce;
	CStringW	m_PhotoAddress;
	CStringW	m_Origin;
	CStringW	m_Specifications;
	CStringW	m_Price;
	long	m_Inventory;
}CommElem;

class CCommSet
{
private:
	std::list<CommElem> real;
	std::list<CommElem>::iterator iterR;
	int length;
	std::list<CommElem> openned;
	std::list<CommElem>::iterator iterO;
	int openLength;
	int now;
	int realNow;
	int newID;
	bool canEdit;
	CString title[10];

public:
	CCommSet();
	~CCommSet();
	long		m_ID;
	CStringW	m_CommNum;
	CStringW	m_CommName;
	CStringW	m_CommKind;
	CStringW	m_Introduce;
	CStringW	m_PhotoAddress;
	CStringW	m_Origin;
	CStringW	m_Specifications;
	CStringW	m_Price;
	long		m_Inventory;

	CString m_strFilter;//查找关键字
	CString m_strSort;//排序关键字
	CString m_sFilterTitle;
	CString m_sFilterKeyWord;

	bool IsOpen();//数据是否打开
	bool IsEOF();//数据是否为空
	bool Open();//打开数据
	bool Close();//关闭数据
	void AddNew();//添加数据
	void Update();//更新数据
	void Edit();//编辑数据
	void Delete();//删除数据
	void Move(long pos);//选择数据条
	void MoveNext();//选择下一条数据
	void GetFieldValue(short n, CString &str);//获得内容
	int GetODBCFieldCount();
	void GetODBCFieldInfo(short n, CString &str);
	void CStringToChar(CString str, char *pChStr);
};


