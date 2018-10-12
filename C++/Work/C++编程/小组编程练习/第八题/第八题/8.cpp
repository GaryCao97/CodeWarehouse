#include <cstdlib>
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define NUM 30

class Student
{
public:
	void GetInformation(char *_Name, char *_Number, char *_Class);									//��ȡѧ����Ϣ
	int GetStartTime(int hh = 0, int mm = 0, int ss = 0);											//��ȡ��ʼʱ�䣬�ɹ��򷵻�TRUE
	int GetStopTime(int hh = 0, int mm = 0, int ss = 0);											//��ȡ����ʱ�䲢����ʱ���ɹ��򷵻�TRUE
	void ShowMoney();																				//����ϻ�����
	void ShowTime();																				//����ϻ���ʱ��
	void ShowInformation(int a);																	//���ѧ����Ϣ
	int Check(char *_Name = NULL, char *_Number = NULL, char *_Class = NULL);						//���ҶԱȣ�������򷵻�TRUE
protected:
	char Name[20];
	char Number[20];
	char Class[50];
	int Hour[3], Minute[3], Second[3];
	int Money;
	int SetTime();
};

Student stu[NUM];

int Start()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t=============================================" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t*            ��ӭʹ�û�������ϵͳ           *" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t*                                           *" << endl;
	cout << "\t=============================================" << endl << endl << endl;
	cout << "\t��ѡ����" << endl;
	cout << "\t1.�»�" << endl;
	cout << "\t2.��ѯ" << endl;
	cout << "\t3.�˳�" << endl << '\t';
	int ans;
	cin >> ans;
	return ans;
}
void Input()
{
	char Name[20], Number[20], Class[50];
	int hh, mm, ss;
	for (int i = 0; i < NUM; i++)
	{
		cout << "\t������������ѧ�š��༶��" << endl << '\t';
		cin >> Name;
		cin >> Number;
		cin >> Class;
		stu[i].GetInformation(Name, Number, Class);
		cout << "\t�������ϻ�ʱ�䣨ʱ �� �룩��" << endl << '\t';
		cin >> hh >> mm >> ss;
		stu[i].GetStartTime(hh, mm, ss);
		system("cls");
	}
}
void Down()
{
	system("cls");
	char number[20];
	int num,book = FALSE;
	int hh, mm, ss;
	do
	{
		cout << "\t������ѧ�ţ�" << endl << '\t';
		cin >> number;
		for (num = 0; num < NUM; num++)
			if (stu[num].Check(NULL, number) == TRUE)
			{
				book = TRUE;
				break;
			}
		if (book == FALSE) 
		{
			system("cls");
			cout << "\tѧ�Ų����ڣ����������룺" << endl;
		}
	} while (book == FALSE);
	stu[num].ShowInformation(1);
	cout << "\t�������»�ʱ�䣨ʱ �� �룩��" << endl << '\t';
	cin >> hh >> mm >> ss;
	stu[num].GetStopTime(hh, mm, ss);
	stu[num].ShowTime();
	stu[num].ShowMoney();
	system("pause");
	return;
}
void Search()
{
	system("cls");
	char ch, CH[50]; int book = FALSE;
	cout << "\t��ѡ���ѯ��ʽ��" << endl
		<< "\t1.����������" << endl
		<< "\t2.��ѧ�Ų���" << endl
		<< "\t3.���༶����" << endl << '\t';
	cin >> ch;
	switch (ch)
	{
	case '1':
		cout << "\t��ѡ���ѯ������" << endl << '\t';
		cin >> CH;
		for (int o = 0; o < NUM; o++)
		{
			if (stu[o].Check(CH) == TRUE)
			{
				book = TRUE;
				stu[o].ShowInformation(2);
			}
		}
		if (book == FALSE)
			cout << "\t��ѯ���Ϊ�գ�" << endl;
		break;
	case '2':
		cout << "\t��ѡ���ѯѧ�ţ�" << endl << '\t';
		cin >> CH;
		for (int o = 0; o < NUM; o++)
		{
			if (stu[o].Check(NULL, CH) == TRUE)
			{
				book = TRUE;
				stu[o].ShowInformation(2);
			}
		}
		if (book == FALSE)
			cout << "\t��ѯ���Ϊ�գ�" << endl;
		break;
	case '3':
		cout << "\t��ѡ���ѯ�༶��" << endl << '\t';
		cin >> CH;
		for (int o = 0; o < NUM; o++)
		{
			if (stu[o].Check(NULL, NULL, CH) == TRUE)
			{
				book = TRUE;
				stu[o].ShowInformation(2);
			}
		}
		if (book == FALSE)
			cout << "\t��ѯ���Ϊ�գ�" << endl;
		break;
	default:
		cout << "\t�������˷Ƿ��ַ���" << endl;
		break;
	}
	system("pause");
	return;
}
int Compare(char a[], char b[])
{
	int m = 0;
	if (a[m] != b[m])
		return FALSE;
	for (m = 1; a[m-1] != '\0' && b[m-1] != '\0'; m++)
	{
		if (a[m] != b[m])
			return FALSE;
	}
	return TRUE;
}
void Copy(char a[], char b[])
{
	int o = 0;
	for (; b[o] != '\0'; o++)
	{
		a[o] = b[o];
	}
	a[o] = '\0';
}
void main()
{
	Input();
	int c;
	do
	{
		c = Start();
		if (c == 1)
		{
			Down();
		}
		else if (c == 2)
		{
			Search();
		}
	} while (c != 3);
	return;
}
void Student::GetInformation(char *_Name, char *_Number, char *_Class)
{
	Copy(Name, _Name);
	Copy(Number, _Number);
	Copy(Class, _Class);
}
int Student::GetStartTime(int hh, int mm, int ss)
{
	if (hh >= 24 || mm >= 60 || ss >= 60)
		return FALSE;
	Hour[1] = hh;
	Minute[1] = mm;
	Second[1] = ss;
	return TRUE;
}
int Student::GetStopTime(int hh, int mm, int ss)
{
	if (hh >= 24 || mm >= 60 || ss >= 60)
		return FALSE;
	Hour[2] = hh;
	Minute[2] = mm;
	Second[2] = ss;
	if (Student::SetTime())
		return TRUE;
	else return FALSE;
}
int Student::SetTime()
{
	Hour[0] = Hour[2] - Hour[1];
	Minute[0] = Minute[2] - Minute[1];
	Second[0] = Second[2] - Second[1];
	if (Second[0] < 0)
	{
		Second[0] += 60;
		Minute[0] -= 1;
	}
	else if (Second[0] >= 60)
	{
		Second[0] -= 60;
		Minute[0] += 1;
	}
	if (Minute[0] < 0)
	{
		Minute[0] += 60;
		Hour[0] -= 1;
	}
	else if (Minute[0] >= 60)
	{
		Minute[0] -= 60;
		Hour[0] += 1;
	}
	if (Hour[0] < 0)
		return FALSE;
	return TRUE;
}
void Student::ShowMoney()
{
	if (Minute[0] != 0 || Second[0] != 0)
		Money = (Hour[0] + 1) * 1;
	else Money = Hour[0];
	printf("\t�ϻ�����%dԪ��\n", Money);
}
void Student::ShowTime()
{
	printf("\t��ʱ��%d:%d:%d\n\n", Hour[0], Minute[0], Second[0]);
}
void Student::ShowInformation(int a)
{
	switch (a)
	{
	case 1:
		printf("\tѧ�ţ�%s\n\t������%s\n\t�༶��%s\n\t�ϻ�ʱ��%d:%d:%d\n\n", Number, Name, Class, Hour[1], Minute[1], Second[1]);
		break;
	case 2:
		printf("\tѧ�ţ�%s\n\t������%s\n\t�༶��%s\n\t�ϻ�ʱ��%d:%d:%d\n\t�»�ʱ��%d:%d:%d\n\n", Number, Name, Class, Hour[1], Minute[1], Second[1], Hour[2], Minute[2], Second[2]);
		break;
	}
	
}
int Student::Check(char *_Name, char *_Number, char *_Class)
{
	if (_Name == NULL && _Number == NULL)
	{
		if (Compare(_Class, Class) == TRUE)
			return TRUE;
		else return FALSE;
	}
	else if (_Class == NULL && _Number == NULL)
	{
		if (Compare(_Name, Name) == TRUE)
			return TRUE;
		else return FALSE;
	}
	else if (_Name == NULL && _Class == NULL)
	{
		if (Compare(_Number, Number) == TRUE)
			return TRUE;
		else return FALSE;
	}
	else return FALSE;
}