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
	strcpy_s(p->name,"小红");
	p->age = 20;
	strcpy_s((p+1)->name,"小王");
	(p+1)->age = 40;
	strcpy_s((p+2)->name,"小明");
	(p+2)->age = 30;
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