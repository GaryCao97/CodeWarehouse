#include <iostream>
using namespace std;
struct Date
{
	int year;
	int moon;
	int day;
	int date;
}someday;
void Date_Day()
{
	switch (someday.moon)
	{
	case 1:someday.date = someday.day + 0;break;
	case 2:someday.date = someday.day + 31;break;
	case 3:someday.date = someday.day + 60;break;
	case 4:someday.date = someday.day + 91;break;
	case 5:someday.date = someday.day + 121;break;
	case 6:someday.date = someday.day + 152;break;
	case 7:someday.date = someday.day + 182;break;
	case 8:someday.date = someday.day + 213;break;
	case 9:someday.date = someday.day + 244;break;
	case 10:someday.date = someday.day + 274;break;
	case 11:someday.date = someday.day + 305;break;
	case 12:someday.date = someday.day + 335;break;
	default:cout << "你输入的月份错误！" << endl;
	}
}
int main()
{
	cout << "请输入今天的年、月、日(yy mm dd)：" << endl;
	cin >> someday.year >> someday.moon >> someday.day;
	Date_Day();
	cout << "今天是今年的第" << someday.date << "天！" << endl;
	return 0;
}