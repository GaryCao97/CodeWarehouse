#pragma once


// CInputDlg �Ի���

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInputDlg();

// �Ի�������
	enum { IDD = IDD_Input };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedinputClose();
	CString input_class;
	double intput_S1;
	double intput_S2;
	double intput_S3;
	double intput_S4;
	double intput_S5;
	CString input_name;
	CString input_number;
	CString input_school;
	CString input_teacher;
	afx_msg void OnBnClickedinputNext();
};
