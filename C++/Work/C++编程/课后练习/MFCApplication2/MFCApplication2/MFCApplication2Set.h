
// MFCApplication2Set.h: CMFCApplication2Set ��Ľӿ�
//


#pragma once

// ���������� 2016��5��10��, 19:21

class CMFCApplication2Set : public CRecordset
{
public:
	CMFCApplication2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMFCApplication2Set)

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

