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
	cout << "�������1���˵�ѧ��(ѧ��Ϊ��ʱ��������)��" << endl;
	cin >> num;
	cin.clear();
	while(strcmp("0",num) != 0)
	{
		n++;
		p = new information;
		strcpy_s(p->number,num);
		cout << "�������" << n << "���˵�������" << endl;
		cin >> p->name;
		cin.clear();
		cout << "�������" << n << "���˵��Ա�" << endl;
		cin >> p->sex;
		cin.clear();
		cout << "�������" << n << "���˵����䣺" << endl;
		cin >> p->age;
		cin.clear();
		cout << "�������" << n << "���˵�רҵ��" << endl;
		cin >> p->profession;
		cin.clear();
		if(n == 1) head = p;
		else q->next = p;
		q = p;
		cout << "�������" << n+1 << "���˵�ѧ��(ѧ��Ϊ��ʱ��������)��" << endl;
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
	cout << "ѧ��"<< setw(10) <<"����"<< setw(6) <<"�Ա�"<< setw(6) <<"����"<< setw(6) <<"רҵ" << endl;
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
	cout << "ԭʼ����" << endl;
	Output();
	cout << "ɾ��ѧ��" << endl;
	cin >> num;
	cin.clear();
	Delete_Num(num);
	Output();
	system("pause");
	system("cls");
	Output();
	cout << "ɾ��רҵ" << endl;
	cin >> pro;
	cin.clear();
	Delete_Pro(pro);
	Output();
	return 0;
}