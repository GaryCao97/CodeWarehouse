#include "Class.h"
#include<cstring>
#include <cstdlib>
#include<iostream>
using namespace std;
#define NUM 30
Student stu[NUM];
void Input()
{
	char Name[20], Number[20], Class[50];
	int hh, mm, ss;
	for (int i = 0; i < NUM; i++)
	{
		cout << "������������ѧ�š��༶��" << endl;
		cin >> Name;
		cin >> Number;
		cin >> Class;
		stu[i].GetInformation(Name, Number, Class);
		cout << "�������ϻ�ʱ�䣨ʱ �� �룩��" << endl;
		cin >> hh >> mm >> ss;
		stu[i].GetStartTime(hh, mm, ss);
		system("cls");
	}
}
int Down(char _Number[])
{
	int hh, mm, ss;
	cout << "�������»�ʱ�䣨ʱ �� �룩��" << endl;
	cin >> hh >> mm >> ss;
	for (int i = 0; i < NUM; i++)
		if (stu[i].Check(NULL,_Number) == TRUE)
		{
			stu[i].GetStopTime(hh, mm, ss);
			return i;
		}
	return -1;
}
void Search(char kind[])
{

}
void main()
{
	Input();
start:
	system("cls");
	cout << "������ѧ�ţ�" << endl;
	char number[20];
	cin >> number;
	int num; 
	num = Down(number);
	stu[num].ShowInformation();
	stu[num].ShowMoney();
	cout << "�Ƿ����(Y/y)or(N/n)" << endl;
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'y':
	case 'Y':
		goto start;
		break;
	case 'n':
	case 'N':
		cout << "�Ƿ���в�ѯ��չʾ��Ϣ" << endl;
		break;
	default:return; break;
	}

}