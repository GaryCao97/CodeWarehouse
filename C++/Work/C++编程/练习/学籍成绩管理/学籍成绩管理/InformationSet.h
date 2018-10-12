// InformationSet.h : CInformationSet ������

#pragma once

// ���������� 2016��5��11��, 22:49

class CInformationSet : public CRecordset
{
public:
	CInformationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CInformationSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	column1;
	CStringW	m_Name;
	CStringW	m_Number;
	CStringW	m_School;
	CStringW	m_Class;
	CStringW	m_Teacher;
	double	m_S1;
	double	m_S2;
	double	m_S3;
	double	m_S4;
	double	m_S5;
	double	m_Sum;
	double	m_Aver;

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


