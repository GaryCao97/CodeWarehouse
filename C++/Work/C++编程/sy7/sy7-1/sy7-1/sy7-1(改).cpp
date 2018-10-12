#include <iostream>
using namespace std;
struct Date
{
	int year;
	int moon;
	int day;
	int date;
}someday;
int Reap()
{
	if (someday.year % 400 == 0 || (someday.year % 4 == 0 && someday.year % 100 != 0))
		return 1;
	else return 0;
}
void Date_Day()
{
	switch (someday.moon)
	{
	case 1:someday.date = someday.day + 0;break;
	case 2:someday.date = someday.day + 31;break;
	case 3:someday.date = someday.day + 59 + Reap();break;
	case 4:someday.date = someday.day + 90 + Reap();break;
	case 5:someday.date = someday.day + 120 + Reap();break;
	case 6:someday.date = someday.day + 151 + Reap();break;
	case 7:someday.date = someday.day + 181 + Reap();break;
	case 8:someday.date = someday.day + 212 + Reap();break;
	case 9:someday.date = someday.day + 243 + Reap();break;
	case 10:someday.date = someday.day + 273 + Reap();break;
	case 11:someday.date = someday.day + 304 + Reap();break;
	case 12:someday.date = someday.day + 334 + Reap();break;
	default:cout << "你输入的月份错误！" << endl;
	}
}
int main()
{
	cout << "请输入某天的年、月、日(yy mm dd)：" << endl;
	cin >> someday.year >> someday.moon >> someday.day;
	Date_Day();
	cout << "某天是当年的第" << someday.date << "天！" << endl;
	return 0;
}