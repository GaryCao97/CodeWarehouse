#include<iostream>
#include<ctime> 
#include<iomanip>
#include<Windows.h> 
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <conio.h>
#include <process.h> 
//conio��Console Input/Output������̨����������ļ�д�����ж�����ͨ������̨���������������������ĺ�������Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����������_getch()�����ȵȡ�
using namespace std;
#define x0 28                   //end_function()���������ͼ��ĵ�һ��Ԫ�صĺ����� 
#define y0 7                    //end_function()���������ͼ��ĵ�һ��Ԫ�ص�������
#define year0 1940              //����Ĳο���ʼ��� 
#define year1 2040              //����Ĳο�������� 
#define main_time_interval 2500           //�����溯����ת�����˵����� �� ����������ת���������溯�� ���ӳٵȴ�ʱ���� 
#define second_time_interval 10              //����ʱ���� 
#define third_time_interval 100              //����ʱ���� 
#define string_time_interval 5               //���ܺ����е��ַ�������ĵ���ʱ���� 
#define number_time_interval 15              //���ܺ����е����������ֵ�����ĵ���ʱ���� 
#define P 35                             //���ܺ���һ�����м�� 
CRITICAL_SECTION CS, cs; //�����ٽ����ṹ����
string weekdays = " Sun Mon Tue Wed Thu Fri Sat";
int number, year, day, days, month, month_days, sum_month_days = 0, i, j, k, m = 0, n = 0;
int temp1[7], temp2[7];
void position_cursor(int x1, int y1)  //�ı���λ�ã�x��y�ֱ�ָ���������� 
{
	COORD position;  //����ṹ����� 
	position.X = x1;
	position.Y = y1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void conceal(int size, int visibility)   //���ù���Сsize�Լ��ɼ���visibility   ��Ҫ����ʵ����Ҫ����������ͽ��������Լ�����ʱ�Σ��������أ�������������Ҫ 
{
	CONSOLE_CURSOR_INFO cursor_info = { size, visibility };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void wait(int seconds)    //��ʱ����
{
	clock_t endwait;
	endwait = clock() + seconds * CLK_TCK;   //CLK_TCK=1000���� 
	while (clock() < endwait) {}
}

int yearl(int year)              //�ж��������             
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))  { return 1; }   //�ܱ�4�����Ҳ��ܱ�100���� �� �ܱ�4��400�����Ķ�Ϊ���� 
	else  { return 0; }                                                    //��Ϊ���귵��1�����򷵻�0 
}

int lyear(int year, int year2)   //�����������֮��������� 
{
	int leap_year;
	for (--year, leap_year = 0; year >= year2; year--)      //����yearl�����ķ���ֵ��������֮������������㣬������������ 
	{
		if (yearl(year) == 1)  { leap_year++; }
	}
	return leap_year;
}

int lmonth(int month, int year)   //���ص��������� 
{
	int month_days;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		//���·�Ϊ1,3,5,7,8,10,12������������Ϊ31�����·�Ϊ4��6,9,11����������Ϊ30,2�·ݵ������������������ֱ�ȡ28��29 
	{
		month_days = 31;
	}
	else
	{
		if (month == 2)
		{
			if (yearl(year) == 1)
				month_days = 29;
			else
				month_days = 28;
		}
		else
		{
			month_days = 30;
		}
	}
	return month_days;
}
int monthl(int month, int year)    //�ݹ���㵱��֮ǰ�����·ݵ������� 
{
	int month_days;
	if (month == 1) return sum_month_days;
	else { sum_month_days += lmonth(--month, year); monthl(month, year); }
}

int judge(int m, int n, int year, int month)    //�������뵱�µڼ������ڼ��Ľ���λ��  mָ�ڼ��ܣ�nָ���ڼ���year��month����֪�� 
{
	//int days;
	sum_month_days = 0;
	days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0) + monthl(month, year);
	if (days % 7<n)
		return (m - 1) * 7 + (n - days % 7);                  //���ݼ����Ҫ��ĵڼ������ڼ����ص������ʱ�����ڵĵڼ��� 
	else
		return (m - 1) * 7 + (7 - days % 7) + n;
}
void festival(int year, int month, int day)  //���յ��뺯�� 
{
	switch (month)
	{
	case 1:
		if (day == 1)
			cout << "Ԫ��";
		else
			cout << "���첻�ǹ�������";
		break;
	case 2:
		if (year >= 1997 && day == 2)
			cout << "����ʪ���� ";
		else if (day == 14)
			cout << "���˽� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 3:
		if (year >= 1999 && day == 3)
			cout << "ȫ�������� ";
		else if (year >= 2000 && day == 5)
			cout << "����־Ը�߷����� ";
		else if (day == 8)
			cout << "���ʸ�Ů�� ";
		else if (year >= 2009 && day == 9)
			cout << "����ĸ�׺��� ";
		else if (day == 12)
			cout << "�й�ֲ���� ";
		else if (day == 14)
			cout << "��ɫ���˽� ";
		else if (year >= 2004 && day == 14)
			cout << "���ʾ���� ";
		else if (year >= 1983 && day == 15)
			cout << "����������Ȩ���� ";
		else if (year >= 2013 && day == 21)
			cout << "����ɭ���� ";
		else if (year >= 2003 && day == 21)
			cout << "����˯����";
		else if (year >= 1993 && day == 22)
			cout << "����ˮ�� ";
		else if (year >= 1950 && day == 23)
			cout << "���������� ";
		else if (year >= 1995 && day == 24)
			cout << "������ν�˲��� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 4:
		if (day == 1)
			cout << "���˽� ";
		else if (year >= 1949 && day == 7)
			cout << "���������� ";
		else if (year >= 2009 && day == 22)
			cout << "��������� ";
		else if (year >= 2016 && day == 24)
			cout << "�й������� ";
		else if (year >= 2001 && day == 26)
			cout << "����֪ʶ��Ȩ�� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 5:
		if (day == judge(2, 7, year, month))
			cout << "ĸ�׽� ";
		if (day == 1)
			cout << "�����Ͷ��� ";
		else if (year >= 1999 && day == 3)
			cout << "���������� ";
		else if (day == 4)
			cout << "�й������ ";
		else if (day == 8)
			cout << "�����ʮ���� ";
		else if (day == 12)
			cout << "���ʻ�ʿ�� ";
		else if (day == 15)
			cout << "���ʼ�ͥ�� ";
		else if (day == 17)
			cout << "��������� ";
		else if (day == 20)
			cout << "ȫ��ѧ��Ӫ���� ";
		else if (day == 23)
			cout << "����ţ���� ";
		else if (day == 31)
			cout << "���������� ";

		else
			cout << "���첻�ǹ�������";
		break;
	case 6:
		if (day == judge(3, 7, year, month))
			cout << "���׽� ";
		if (day == 1)
			cout << "���ʶ�ͯ�� ";
		else if (day == 5)
			cout << "���绷���� ";
		else if (day == 6)
			cout << "ȫ�������� ";
		else if (day == 17)
			cout << "������λ�Į���͸ɺ��� ";
		else if (day == 23)
			cout << "���ʰ���ƥ���� ";
		else if (day == 25)
			cout << "ȫ�������� ";
		else if (day == 26)
			cout << "���ʽ����� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 7:
		if (day == 1)
			cout << "�й������������� ���ʽ����� ";
		else if (day == 7)
			cout << "�й�������ս�������� ";
		else if (day == 11)
			cout << "�����˿��� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 8:
		if (day == 1)
			cout << "�й������ž������� ";
		else if (day == 12)
			cout << "��������� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 9:
		if (day == 8)
			cout << "����ɨä�� ";
		else if (day == 10)
			cout << "�й���ʦ�� ";
		else if (day == 16)
			cout << "�й��Խ����� ���ʳ����㱣���� ";
		else if (day == 20)
			cout << "ȫ�������� ";
		else if (day == 21)
			cout << "����ͣ���� ";
		else if (day == 27)
			cout << "���������� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 10:
		if (day == 1)
			cout << "�л����񹲺͹������ ���������� ������������ ";
		else if (day == 4)
			cout << "���綯���� ";
		else if (day == 5)
			cout << "�����ʦ�� ";
		else if (day == 8)
			cout << "ȫ����Ѫѹ�� ";
		else if (day == 9)
			cout << "���������� ";
		else if (day == 10)
			cout << "���羫��������";
		else if (day == 14)
			cout << "�����׼��";
		else if (day == 15)
			cout << "����ä�˽� ����ũ�帾Ů�� ";
		else if (day == 16)
			cout << "������ʳ�� ";
		else if (day == 17)
			cout << "��������ƶ���� ";
		else if (day == 24)
			cout << "���Ϲ��� ���緢չ������ ";
		else if (day == 28)
			cout << "�й����Խ����� ";
		else if (day == 31)
			cout << "��ʥ�� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 11:
		if (day == 8)
			cout << "�й����߽� ";
		else if (day == 9)
			cout << "���������� ";
		else if (day == 14)
			cout << "���������� ";
		else if (day == 17)
			cout << "���ʴ�ѧ���� ";
		else if (day == 25)
			cout << "���������Ը�Ů�ı����� ";
		else
			cout << "���첻�ǹ�������";
		break;
	case 12:
		if (day == 1)
			cout << "���簬�̲��� ";
		else if (day == 3)
			cout << "����м����� ";
		else if (day == 4)
			cout << "ȫ������������ ";
		else if (day == 9)
			cout << "���������� ";
		else if (day == 25)
			cout << "ʥ���� ";
		else
			cout << "���첻�ǹ�������";
		break;
		//	default:;
	}
}

//���ܶ�������ͬ��ɾ�����еĸ��������������㷨�д��Ժ󾫼� ^_^! 
unsigned int  _stdcall page_turning01(void *arg)
{
	temp1[0] = 22;
	for (temp2[0] = 0; temp2[0]<28; temp2[0]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[0], 3);
		cout << " ";
		temp1[0]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning02(void *arg)
{
	temp1[1] = 22;
	for (temp2[1] = 0; temp2[1]<28; temp2[1]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[1], 4);
		cout << " ";
		temp1[1]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning03(void *arg)
{
	temp1[2] = 22;
	for (temp2[2] = 0; temp2[2]<28; temp2[2]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[2], 5);
		cout << " ";
		temp1[2]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning04(void *arg)
{
	temp1[3] = 22;
	for (temp2[3] = 0; temp2[3]<28; temp2[3]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[3], 6);
		cout << " ";
		temp1[3]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning05(void *arg)
{
	temp1[4] = 22;
	for (temp2[4] = 0; temp2[4]<28; temp2[4]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[4], 7);
		cout << " ";
		temp1[4]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning06(void *arg)
{
	temp1[5] = 22;
	for (temp2[5] = 0; temp2[5]<28; temp2[5]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[5], 8);
		cout << " ";
		temp1[5]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
unsigned int  _stdcall page_turning07(void *arg)
{
	temp1[6] = 22;
	for (temp2[6] = 0; temp2[6]<28; temp2[6]++)
	{
		EnterCriticalSection(&cs);
		position_cursor(temp1[6], 9);
		cout << " ";
		temp1[6]++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
	return 0;
}
void start_delete()
{
	InitializeCriticalSection(&cs);
	_beginthreadex(NULL, 0, page_turning01, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning02, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning03, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning04, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning05, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning06, NULL, 0, NULL);
	_beginthreadex(NULL, 0, page_turning07, NULL, 0, NULL);
	n = 22;
	for (i = 0; i<28; i++)
	{
		EnterCriticalSection(&cs);
		position_cursor(n, 2);
		cout << " ";
		n++;
		LeaveCriticalSection(&cs);
		Sleep(10);
	}
}
