#include<iostream>
#include<ctime> 
#include<iomanip>
#include<Windows.h> 
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <conio.h>
#include <process.h> 
//conio是Console Input/Output（控制台输入输出）的简写，其中定义了通过控制台进行数据输入和数据输出的函数，主要是一些用户通过按键盘产生的对应操作，比如_getch()函数等等。
using namespace std;
#define x0 28                   //end_function()结束界面的图像的第一个元素的横坐标 
#define y0 7                    //end_function()结束界面的图像的第一个元素的纵坐标
#define year0 1940              //计算的参考起始年份 
#define year1 2040              //计算的参考结束年份 
#define main_time_interval 2500           //主界面函数跳转到主菜单函数 和 其他函数跳转到结束界面函数 的延迟等待时间间隔 
#define second_time_interval 10              //调试时间间隔 
#define third_time_interval 100              //调试时间间隔 
#define string_time_interval 5               //功能函数中的字符串输出的调试时间间隔 
#define number_time_interval 15              //功能函数中的天数的数字的输出的调试时间间隔 
#define P 35                             //功能函数一的排列间隔 
CRITICAL_SECTION CS, cs; //定义临界区结构对象
string weekdays = " Sun Mon Tue Wed Thu Fri Sat";
int number, year, day, days, month, month_days, sum_month_days = 0, i, j, k, m = 0, n = 0;
int temp1[7], temp2[7];
void position_cursor(int x1, int y1)  //改变光标位置，x，y分别指代横纵坐标 
{
	COORD position;  //定义结构体变量 
	position.X = x1;
	position.Y = y1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void conceal(int size, int visibility)   //设置光标大小size以及可见性visibility   主要根据实际需要控制主界面和结束界面以及其他时段，光标的隐藏，以满足美观需要 
{
	CONSOLE_CURSOR_INFO cursor_info = { size, visibility };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void wait(int seconds)    //计时函数
{
	clock_t endwait;
	endwait = clock() + seconds * CLK_TCK;   //CLK_TCK=1000毫秒 
	while (clock() < endwait) {}
}

int yearl(int year)              //判断闰年与否             
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))  { return 1; }   //能被4整除且不能被100整除 或 能被4且400整除的都为闰年 
	else  { return 0; }                                                    //若为闰年返回1，否则返回0 
}

int lyear(int year, int year2)   //计算两个年份之间的闰年数 
{
	int leap_year;
	for (--year, leap_year = 0; year >= year2; year--)      //根据yearl（）的返回值进行两年之间的闰年数计算，并返回闰年数 
	{
		if (yearl(year) == 1)  { leap_year++; }
	}
	return leap_year;
}

int lmonth(int month, int year)   //返回当月总天数 
{
	int month_days;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		//若月份为1,3,5,7,8,10,12，当月总天数为31，若月份为4，6,9,11则当月总天数为30,2月份的总天数根据闰年与否分别取28或29 
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
int monthl(int month, int year)    //递归计算当月之前所有月份的总天数 
{
	int month_days;
	if (month == 1) return sum_month_days;
	else { sum_month_days += lmonth(--month, year); monthl(month, year); }
}

int judge(int m, int n, int year, int month)    //用于输入当月第几周星期几的节日位置  m指第几周，n指星期几，year，month见名知意 
{
	//int days;
	sum_month_days = 0;
	days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0) + monthl(month, year);
	if (days % 7<n)
		return (m - 1) * 7 + (n - days % 7);                  //根据键入的要求的第几周星期几返回当月这个时间所在的第几天 
	else
		return (m - 1) * 7 + (7 - days % 7) + n;
}
void festival(int year, int month, int day)  //节日导入函数 
{
	switch (month)
	{
	case 1:
		if (day == 1)
			cout << "元旦";
		else
			cout << "这天不是公历节日";
		break;
	case 2:
		if (year >= 1997 && day == 2)
			cout << "世界湿地日 ";
		else if (day == 14)
			cout << "情人节 ";
		else
			cout << "这天不是公历节日";
		break;
	case 3:
		if (year >= 1999 && day == 3)
			cout << "全国爱耳日 ";
		else if (year >= 2000 && day == 5)
			cout << "青年志愿者服务日 ";
		else if (day == 8)
			cout << "国际妇女节 ";
		else if (year >= 2009 && day == 9)
			cout << "保护母亲河日 ";
		else if (day == 12)
			cout << "中国植树节 ";
		else if (day == 14)
			cout << "白色情人节 ";
		else if (year >= 2004 && day == 14)
			cout << "国际警察节 ";
		else if (year >= 1983 && day == 15)
			cout << "世界消费者权益日 ";
		else if (year >= 2013 && day == 21)
			cout << "世界森林日 ";
		else if (year >= 2003 && day == 21)
			cout << "世界睡眠日";
		else if (year >= 1993 && day == 22)
			cout << "世界水日 ";
		else if (year >= 1950 && day == 23)
			cout << "世界气象日 ";
		else if (year >= 1995 && day == 24)
			cout << "世界防治结核病日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 4:
		if (day == 1)
			cout << "愚人节 ";
		else if (year >= 1949 && day == 7)
			cout << "世界卫生日 ";
		else if (year >= 2009 && day == 22)
			cout << "世界地球日 ";
		else if (year >= 2016 && day == 24)
			cout << "中国航天日 ";
		else if (year >= 2001 && day == 26)
			cout << "世界知识产权日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 5:
		if (day == judge(2, 7, year, month))
			cout << "母亲节 ";
		if (day == 1)
			cout << "国际劳动节 ";
		else if (year >= 1999 && day == 3)
			cout << "世界哮喘日 ";
		else if (day == 4)
			cout << "中国青年节 ";
		else if (day == 8)
			cout << "世界红十字日 ";
		else if (day == 12)
			cout << "国际护士节 ";
		else if (day == 15)
			cout << "国际家庭日 ";
		else if (day == 17)
			cout << "世界电信日 ";
		else if (day == 20)
			cout << "全国学生营养日 ";
		else if (day == 23)
			cout << "国际牛奶日 ";
		else if (day == 31)
			cout << "世界无烟日 ";

		else
			cout << "这天不是公历节日";
		break;
	case 6:
		if (day == judge(3, 7, year, month))
			cout << "父亲节 ";
		if (day == 1)
			cout << "国际儿童节 ";
		else if (day == 5)
			cout << "世界环境日 ";
		else if (day == 6)
			cout << "全国爱眼日 ";
		else if (day == 17)
			cout << "世界防治荒漠化和干旱日 ";
		else if (day == 23)
			cout << "国际奥林匹克日 ";
		else if (day == 25)
			cout << "全国土地日 ";
		else if (day == 26)
			cout << "国际禁毒日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 7:
		if (day == 1)
			cout << "中国共产党诞生日 国际建筑日 ";
		else if (day == 7)
			cout << "中国人民抗日战争纪念日 ";
		else if (day == 11)
			cout << "世界人口日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 8:
		if (day == 1)
			cout << "中国人民解放军建军节 ";
		else if (day == 12)
			cout << "国际青年节 ";
		else
			cout << "这天不是公历节日";
		break;
	case 9:
		if (day == 8)
			cout << "国际扫盲日 ";
		else if (day == 10)
			cout << "中国教师节 ";
		else if (day == 16)
			cout << "中国脑健康日 国际臭氧层保护日 ";
		else if (day == 20)
			cout << "全国爱牙日 ";
		else if (day == 21)
			cout << "世界停火日 ";
		else if (day == 27)
			cout << "世界旅游日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 10:
		if (day == 1)
			cout << "中华人民共和国国庆节 国际音乐日 国际老年人日 ";
		else if (day == 4)
			cout << "世界动物日 ";
		else if (day == 5)
			cout << "世界教师日 ";
		else if (day == 8)
			cout << "全国高血压日 ";
		else if (day == 9)
			cout << "世界邮政日 ";
		else if (day == 10)
			cout << "世界精神卫生日";
		else if (day == 14)
			cout << "世界标准日";
		else if (day == 15)
			cout << "国际盲人节 世界农村妇女日 ";
		else if (day == 16)
			cout << "世界粮食日 ";
		else if (day == 17)
			cout << "国际消除贫困日 ";
		else if (day == 24)
			cout << "联合国日 世界发展新闻日 ";
		else if (day == 28)
			cout << "中国男性健康日 ";
		else if (day == 31)
			cout << "万圣节 ";
		else
			cout << "这天不是公历节日";
		break;
	case 11:
		if (day == 8)
			cout << "中国记者节 ";
		else if (day == 9)
			cout << "消防宣传日 ";
		else if (day == 14)
			cout << "世界糖尿病日 ";
		else if (day == 17)
			cout << "国际大学生节 ";
		else if (day == 25)
			cout << "国际消除对妇女的暴力日 ";
		else
			cout << "这天不是公历节日";
		break;
	case 12:
		if (day == 1)
			cout << "世界艾滋病日 ";
		else if (day == 3)
			cout << "世界残疾人日 ";
		else if (day == 4)
			cout << "全国法制宣传日 ";
		else if (day == 9)
			cout << "世界足球日 ";
		else if (day == 25)
			cout << "圣诞节 ";
		else
			cout << "这天不是公历节日";
		break;
		//	default:;
	}
}

//功能二函数的同步删除多行的附属函数，具体算法有待以后精简 ^_^! 
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
