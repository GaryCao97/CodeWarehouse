
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

	CString m_strFilter;//���ҹؼ���
	CString m_strSort;//����ؼ���
	CString m_sFilterTitle;
	CString m_sFilterKeyWord;

	bool IsOpen();//�����Ƿ��
	bool IsEOF();//�����Ƿ�Ϊ��
	bool Open();//������
	bool Close();//�ر�����
	void AddNew();//�������
	void Update();//��������
	void Edit();//�༭����
	void Delete();//ɾ������
	void Move(long pos);//ѡ��������
	void MoveNext();//ѡ����һ������
	void GetFieldValue(short n, CString &str);//�������
	int GetODBCFieldCount();
	void GetODBCFieldInfo(short n, CString &str);
	void CStringToChar(CString str, char *pChStr);
};