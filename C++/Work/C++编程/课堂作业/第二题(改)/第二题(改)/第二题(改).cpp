#include <iostream>
using namespace std;

int RestDay(int x,int y,int z)
{
	int rd;
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) 
	{
		switch (y)
		{
		case 1  : rd = 366 - z + 1;break;
		case 2  : rd = 335 - z + 1;break;
		case 3  : rd = 306 - z + 1;break;
		case 4  : rd = 275 - z + 1;break;
		case 5  : rd = 245 - z + 1;break;
		case 6  : rd = 214 - z + 1;break;
		case 7  : rd = 184 - z + 1;break;
		case 8  : rd = 153 - z + 1;break;
		case 9  : rd = 122 - z + 1;break;
		case 10 : rd = 92 - z + 1;break;
		case 11 : rd = 61 - z + 1;break;
		case 12 : rd = 31 - z + 1;break;
		}
		return rd;
	}
	else 
	{
		switch (y)
		{
		case 1  : rd = 365 - z + 1;break;
		case 2  : rd = 334 - z + 1;break;
		case 3  : rd = 306 - z + 1;break;
		case 4  : rd = 275 - z + 1;break;
		case 5  : rd = 245 - z + 1;break;
		case 6  : rd = 214 - z + 1;break;
		case 7  : rd = 184 - z + 1;break;
		case 8  : rd = 153 - z + 1;break;
		case 9  : rd = 122 - z + 1;break;
		case 10 : rd = 92 - z + 1;break;
		case 11 : rd = 61 - z + 1;break;
		case 12 : rd = 31 - z + 1;break;
		}
		return rd;
	}
}

int AllDay(int x)
{
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) return 366;
	else return 365;
}

int main()
{
	int day,rd,pd;
	cout << "�������ʼ�����ռ�����������" << endl;
	int yy_1,mm_1,dd_1,yy_2,mm_2,dd_2;
	cout << "�������ʼ��� ";
	cin >> yy_1;
	cout << "�������ʼ�·� ";
	cin >> mm_1;
	cout << "�������ʼ���� ";
	cin >> dd_1;
	rd = RestDay(yy_1,mm_1,dd_1);
	cout << "������������ ";
	cin >> yy_2;
	cout << "����������·� ";
	cin >> mm_2;
	cout << "������������� ";
	cin >> dd_2;
	pd = AllDay(yy_2) - RestDay(yy_2,mm_2,dd_2) + 1;
	day = 0;
	for (int n = yy_1 + 1;n < yy_2;n++)
	{
		day += AllDay(n);
	}
	day = day + rd + pd;
	cout << "��" << yy_1 << "��" << mm_1 << "��" << dd_1
		<< "�յ�"<< yy_2 << "��" << mm_2 << "��" << dd_2 
		<< "�գ��ܹ�" << day << "�죬Լ��" 
		<< (day/365) << "��" << ((day%365)/30) << "��" << (day%365%30) << "��"
		<< endl;
}