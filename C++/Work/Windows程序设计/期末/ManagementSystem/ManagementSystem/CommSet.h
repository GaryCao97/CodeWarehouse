// CommSet.h : CCommSet ������

#pragma once

// ���������� 2017��5��27��, 21:17

class CCommSet : public CRecordset
{
public:
	CCommSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCommSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	m_CommNum;
	CStringW	m_CommName;
	CStringW	m_CommKind;
	CStringW	m_Introduce;
	CStringW	m_PhotoAddress;
	CStringW	m_Origin;
	CStringW	m_Specifications;
	CStringW	m_Price;
	long	m_Inventory;
	CStringW	m_Blog;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


