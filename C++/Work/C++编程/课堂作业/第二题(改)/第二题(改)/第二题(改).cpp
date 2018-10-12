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
	cout << "请输入初始年月日及结束年月日" << endl;
	int yy_1,mm_1,dd_1,yy_2,mm_2,dd_2;
	cout << "请输入初始年份 ";
	cin >> yy_1;
	cout << "请输入初始月份 ";
	cin >> mm_1;
	cout << "请输入初始日数 ";
	cin >> dd_1;
	rd = RestDay(yy_1,mm_1,dd_1);
	cout << "请输入结束年份 ";
	cin >> yy_2;
	cout << "请输入结束月份 ";
	cin >> mm_2;
	cout << "请输入结束日数 ";
	cin >> dd_2;
	pd = AllDay(yy_2) - RestDay(yy_2,mm_2,dd_2) + 1;
	day = 0;
	for (int n = yy_1 + 1;n < yy_2;n++)
	{
		day += AllDay(n);
	}
	day = day + rd + pd;
	cout << "从" << yy_1 << "年" << mm_1 << "月" << dd_1
		<< "日到"<< yy_2 << "年" << mm_2 << "月" << dd_2 
		<< "日，总共" << day << "天，约合" 
		<< (day/365) << "年" << ((day%365)/30) << "月" << (day%365%30) << "天"
		<< endl;
}