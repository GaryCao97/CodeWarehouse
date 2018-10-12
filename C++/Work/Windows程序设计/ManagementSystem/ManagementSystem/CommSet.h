
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


