
#pragma once
#include <list> 
#include <fstream>
using namespace std;

typedef struct {
	long m_ID;
	CStringW	m_Username;
	CStringW	m_Number;
	CStringW	m_Realname;
	CStringW	m_Kind;
	CStringW	m_Duty;
	CStringW	m_Password;
}UserElem;
typedef struct {
	long m_ID;
	char	m_Username[20];
	char	m_Number[20];
	char	m_Realname[20];
	char	m_Kind[20];
	char	m_Duty[100];
	char	m_Password[20];
}UserFileInfo;

class CUserSet
{
private:
	std::list<UserElem> real;
	std::list<UserElem>::iterator iterR;
	int length;
	std::list<UserElem> openned;
	std::list<UserElem>::iterator iterO;
	int openLength;
	CString title[7];
	int now;
	int realNow;
	int newID;
	bool canEdit;

public:
	CUserSet();
	~CUserSet();
	long m_ID;
	CStringW	m_Username;
	CStringW	m_Number;
	CStringW	m_Realname;
	CStringW	m_Kind;
	CStringW	m_Duty;
	CStringW	m_Password;

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