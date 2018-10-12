#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct information
{
	char number[15];
	char name[10];
	char sex[5];
	int age;
	char profession[20];
	struct information *next;
}*head;
void Create()
{
	head = 0;
	struct information *p,*q;
	int n = 0;
	char num[15];
	cout << "请输入第1个人的学号(学号为零时结束输入)：" << endl;
	cin >> num;
	cin.clear();
	while(strcmp("0",num) != 0)
	{
		n++;
		p = new information;
		strcpy_s(p->number,num);
		cout << "请输入第" << n << "个人的姓名：" << endl;
		cin >> p->name;
		cin.clear();
		cout << "请输入第" << n << "个人的性别：" << endl;
		cin >> p->sex;
		cin.clear();
		cout << "请输入第" << n << "个人的年龄：" << endl;
		cin >> p->age;
		cin.clear();
		cout << "请输入第" << n << "个人的专业：" << endl;
		cin >> p->profession;
		cin.clear();
		if(n == 1) head = p;
		else q->next = p;
		q = p;
		cout << "请输入第" << n+1 << "个人的学号(学号为零时结束输入)：" << endl;
		cin >> num;
	}
	p->next = 0;
}
void Delete_Num(char *x)
{
	struct information *p,*q;
	p = head;
	while(p != 0)
	{
		if (strcmp(x,p->number) == 0 && p != head)
			q->next = p->next;
		else if (strcmp(x,p->number) == 0 && p == head)
			head = head->next;
		q = p;
		p = p->next;
	}
}
void Delete_Pro(char *x)
{
	struct information *p,*q;
	p = head;
	while(p != 0)
	{
		if (strcmp(x,p->profession) == 0 && p != head)
			q->next = p->next;
		else if (strcmp(x,p->profession) == 0 && p == head)
			head = head->next;
		q = p;
		p = p->next;
	}
}
void Output()
{
	struct information *p;
	p = head;
	cout << "学号"<< setw(10) <<"姓名"<< setw(6) <<"性别"<< setw(6) <<"年龄"<< setw(6) <<"专业" << endl;
	while(p != 0)
	{
		cout<< setw(4)
			<< p->number << setw(10)
			<< p->name << setw(5)
			<< p->sex << setw(6)
			<< p->age << setw(7)
			<< p->profession;
		cout << endl;
		p = p->next;
	}
}
int main()
{
	char num[15], pro[20];
	Create();
	system("cls");
	cout << "原始数据" << endl;
	Output();
	cout << "删除学号" << endl;
	cin >> num;
	cin.clear();
	Delete_Num(num);
	Output();
	system("pause");
	system("cls");
	Output();
	cout << "删除专业" << endl;
	cin >> pro;
	cin.clear();
	Delete_Pro(pro);
	Output();
	return 0;
}