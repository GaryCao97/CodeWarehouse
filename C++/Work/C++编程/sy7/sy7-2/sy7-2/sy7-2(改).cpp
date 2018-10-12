#include <iostream>
#include <cstring>
using namespace std;
struct information
{
	char name[10];
	int age;
}people[3];
struct information *p;
void Input()
{
	char _name[10];int _age;
	for (int i= 0;i < 3;i++)
	{
		cout << "输入第" << i + 1 << "个人的姓名和年龄：" << endl;
		cin >> _name >> _age;
		strcpy_s((p+i)->name,_name);
		(p+i)->age = _age;
	}
}
void GetMid()
{
	int max = p->age, min = p->age , mid;
	for (int i= 0;i < 3;i++)
	{
		max = max < (p + i)->age ? (p + i)->age : max;
		min = min > (p + i)->age ? (p + i)->age : min;
	}
	for (int i= 0;i < 3;i++)
		mid = (max == (p+i)->age || min == (p+i)->age) ? -1 : i;
	p += mid;
}
int main()
{
	p = people;
	Input();
	GetMid();
	cout << p->name << p->age << endl;
	return 0;
}