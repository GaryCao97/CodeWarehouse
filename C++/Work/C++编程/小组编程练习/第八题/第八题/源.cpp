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
		cout << "请输入姓名、学号、班级：" << endl;
		cin >> Name;
		cin >> Number;
		cin >> Class;
		stu[i].GetInformation(Name, Number, Class);
		cout << "请输入上机时间（时 分 秒）：" << endl;
		cin >> hh >> mm >> ss;
		stu[i].GetStartTime(hh, mm, ss);
		system("cls");
	}
}
int Down(char _Number[])
{
	int hh, mm, ss;
	cout << "请输入下机时间（时 分 秒）：" << endl;
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
	cout << "请输入学号：" << endl;
	char number[20];
	cin >> number;
	int num; 
	num = Down(number);
	stu[num].ShowInformation();
	stu[num].ShowMoney();
	cout << "是否继续(Y/y)or(N/n)" << endl;
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
		cout << "是否进行查询或展示信息" << endl;
		break;
	default:return; break;
	}

}