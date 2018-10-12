// Information.h : CInformation ������

#pragma once

// ���������� 2016��5��11��, 22:37

class CInformation : public CRecordset
{
public:
	CInformation(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CInformation)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	column1;
	CStringW	column2;
	CStringW	column3;
	CStringW	column4;
	CStringW	column5;
	CStringW	column6;
	double	m_1;
	double	m_2;
	double	m_3;
	double	m_4;
	double	m_5;
	double	column7;
	double	column8;

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


