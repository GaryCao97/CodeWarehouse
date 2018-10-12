#include <iostream>
#include <iomanip> 
#include <string> 
#include <ctime>
#include <string.h> 
using namespace std;
void menus();
void save();
void count_4(int i);
void inquire();
void display();
struct student
{
	char name[20];
	char _class[20];
	long number;
	int ihour;
	int iminute;
	int isecond;
	int ohour;
	int ominute;
	int osecond;
}stu[30];
void menu()
{	
	int a;
	cout<<"*           如需使用登录上机功能，请输入1               *"<<endl;
	cout<<"*           如需查询本次上机时间，请输入2               *"<<endl;
	cout<<"*           查询当前机器使用情况，请输入3               *"<<endl;
	cout<<"*             如需返回菜单首页，请输入0                 *"<<endl;
	cout<<"*                                                       *"<<endl;
	cout<<endl<<"请输入相应数字以选择服务(0-3)：";
	loop:
	cin>>a;
	cout<<endl;
	if(a==0)  //如果用户要求返回菜单首页 
		menu();
	else
	{
		switch(a)
		{
			case 1: save();
				break;
			case 2: inquire();
				break;
			case 3: display();
				break;
			default:
			{
				cout<<"输入错误！请重新输入：";
				goto loop; //输入数据错，则让用户重新输入一个数据 
			}
    	}
	} 
}

void input(struct student *p) //
{
	cout << "请输入学生姓名，然后按下<回车>键：" << endl;
	cin >> p->name;
	cout << "请输入学生所在的班级，然后按下<回车>键：" << endl;
	cin >> p->_class;
	cout << "请输入学生的学号，然后按下<回车>键：" << endl;
	cin >> p->number;
	cin.get();
}
void save() //存入文件  （用这个！！） 
{
	struct student stu[30];
	FILE *fp;
	int i = 0, *p;
	fopen_s(&fp, "数据.txt", "r+");//("数据.txt","r+");
	input(stu + i);
	fwrite(&stu[i], sizeof(struct student), 1, fp);
	count_4(i);
	i++;
	cout << "如需返回菜单首页，请输入0：" << endl;
	int a;
	cin >> a;
	if (a == 0)
		menu();
}

void showtime(tm* pt) //输出跳动的时间，包括年月日 
{
	cout << setfill('0') << 1900 + pt->tm_year << '-';
	cout << setw(2) << pt->tm_mon + 1 << '-';
	cout << setw(2) << pt->tm_mday << ' ';
	cout << setw(2) << pt->tm_hour << ':';
	cout << setw(2) << pt->tm_min << ':';
	cout << setw(2) << pt->tm_sec << '\n';
}

void count_1(struct student, int i, tm* pt) //记录开始上网时间 
{
	stu[i].ihour = pt->tm_hour;
	stu[i].iminute = pt->tm_min;
	stu[i].isecond = pt->tm_sec;
	cout << "您开始使用计算机时间为：" << stu[i].ihour << ":" << stu[i].iminute << ":" << stu[i].isecond << endl;
}

void count_2(struct student, int i, tm* pt) //记录 结束上网时间 
{
	stu[i].ohour = pt->tm_hour;
	stu[i].ominute = pt->tm_min;
	stu[i].osecond = pt->tm_sec;
	cout << "您结束使用计算机时间为：" << stu[i].ohour << ":" << stu[i].ominute << ":" << stu[i].osecond << endl;
}

void count_3(int i) //计算花费 
{
	int money;
	money = (stu[i].ohour - stu[i].ihour) * 1;
	if (stu[i].ominute>stu[i].iminute)
		cout << "您本次上网花费：" << ++money << endl;
	else if (stu[i].ominute == stu[i].iminute&&stu[i].osecond>stu[i].isecond)
		cout << "您本次上网花费：" << ++money << endl;
	else
		cout << "您本次上网花费：" << money << endl;
}

void count_4(int i)  //调用以上函数，完成时间及花费的计算 （写的时候写这个！！） 
{
	cout << "请输入数字1，结束上网。" << endl;
	int num;
	time_t t = time(NULL);
	tm* pt = 0;
	localtime_s(pt, &t);
	int sec = pt->tm_sec;
	count_1(stu[i], i, pt);
	showtime(pt);
	while (1)
	{
		t = time(NULL);
		localtime_s(pt, &t);
		if (sec != pt->tm_sec)
		{
			sec = pt->tm_sec;
			system("cls");
			showtime(pt);
		}
	}

	cin >> num;
	if (num == 1)
	{
		count_2(stu[i], i, pt);
		count_3(i);
	}
}

void inquire() //查询学生的上机时间 
{
	int num, i;
	long b;
	char a[20];
	do
	{
		cout << "查询（使用姓名按1，使用学号按2）" << endl;
		cin >> num;
	} while (num != 1 && num != 2);
	if (num == 1)
	{
		cout << "请输入姓名：";
		gets_s(a);
		for (i = 0; i<30; i++)
		{
			if (strcmp(stu[i].name, a) == 0)
				break;
		}
	}
	else
	{
		cout << "请输入学号：";
		cin >> b;
		for (i = 0; i<30; i++)
		{
			if (stu[i].number == b)
				break;
		}
	}
	if (i == 30)
		cout << "没有这个学生！" << endl;
	else
		cout << stu[i].name << endl << "上机时间：" << stu[i].ihour << ":"
		<< stu[i].iminute << "；" << stu[i].isecond << "：" << endl;
	cout << "如需返回菜单首页，请输入0：" << endl;
	int c;
	cin >> c;
	if (c == 0)
		menu();
}

void display() //查询当前机器的使用情况 
{
	int k;
	cout << "请输入机号：";
	cin >> k;
	if (stu[k].ihour == stu[k].ohour&&stu[k].iminute == stu[k].ominute&&stu[k].isecond == stu[k].osecond)
		cout << "机器使用" << "：" << "否" << endl;
	else
	{
		cout << "机器使用：" << "是" << endl;
		cout << "使用者班级：" << stu[k]._class << "     " << "使用者学号：" << stu[k].number << "     " << "使用者姓名：" << stu[k].name << endl;
	}
	system("pause");
	cout << "如需返回菜单首页，请输入0：" << endl;
	int a;
	cin >> a;
	if (a == 0)
		menu();
}

int main()
{
	loop1:
	cout<<"*********************************************************"<<endl;
	cout<<"*                                                       *"<<endl; 
	cout<<"*         ☆欢迎使用小鸭梨机房收费管理系统☆            *"<<endl; 
	cout<<"*                                                       *"<<endl;
	cout<<"*********************************************************"<<endl;
	menu();
}

