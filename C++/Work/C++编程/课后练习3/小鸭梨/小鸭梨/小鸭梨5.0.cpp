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
	cout<<"*           ����ʹ�õ�¼�ϻ����ܣ�������1               *"<<endl;
	cout<<"*           �����ѯ�����ϻ�ʱ�䣬������2               *"<<endl;
	cout<<"*           ��ѯ��ǰ����ʹ�������������3               *"<<endl;
	cout<<"*             ���践�ز˵���ҳ��������0                 *"<<endl;
	cout<<"*                                                       *"<<endl;
	cout<<endl<<"��������Ӧ������ѡ�����(0-3)��";
	loop:
	cin>>a;
	cout<<endl;
	if(a==0)  //����û�Ҫ�󷵻ز˵���ҳ 
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
				cout<<"����������������룺";
				goto loop; //�������ݴ������û���������һ������ 
			}
    	}
	} 
}

void input(struct student *p) //
{
	cout << "������ѧ��������Ȼ����<�س�>����" << endl;
	cin >> p->name;
	cout << "������ѧ�����ڵİ༶��Ȼ����<�س�>����" << endl;
	cin >> p->_class;
	cout << "������ѧ����ѧ�ţ�Ȼ����<�س�>����" << endl;
	cin >> p->number;
	cin.get();
}
void save() //�����ļ�  ������������� 
{
	struct student stu[30];
	FILE *fp;
	int i = 0, *p;
	fopen_s(&fp, "����.txt", "r+");//("����.txt","r+");
	input(stu + i);
	fwrite(&stu[i], sizeof(struct student), 1, fp);
	count_4(i);
	i++;
	cout << "���践�ز˵���ҳ��������0��" << endl;
	int a;
	cin >> a;
	if (a == 0)
		menu();
}

void showtime(tm* pt) //���������ʱ�䣬���������� 
{
	cout << setfill('0') << 1900 + pt->tm_year << '-';
	cout << setw(2) << pt->tm_mon + 1 << '-';
	cout << setw(2) << pt->tm_mday << ' ';
	cout << setw(2) << pt->tm_hour << ':';
	cout << setw(2) << pt->tm_min << ':';
	cout << setw(2) << pt->tm_sec << '\n';
}

void count_1(struct student, int i, tm* pt) //��¼��ʼ����ʱ�� 
{
	stu[i].ihour = pt->tm_hour;
	stu[i].iminute = pt->tm_min;
	stu[i].isecond = pt->tm_sec;
	cout << "����ʼʹ�ü����ʱ��Ϊ��" << stu[i].ihour << ":" << stu[i].iminute << ":" << stu[i].isecond << endl;
}

void count_2(struct student, int i, tm* pt) //��¼ ��������ʱ�� 
{
	stu[i].ohour = pt->tm_hour;
	stu[i].ominute = pt->tm_min;
	stu[i].osecond = pt->tm_sec;
	cout << "������ʹ�ü����ʱ��Ϊ��" << stu[i].ohour << ":" << stu[i].ominute << ":" << stu[i].osecond << endl;
}

void count_3(int i) //���㻨�� 
{
	int money;
	money = (stu[i].ohour - stu[i].ihour) * 1;
	if (stu[i].ominute>stu[i].iminute)
		cout << "�������������ѣ�" << ++money << endl;
	else if (stu[i].ominute == stu[i].iminute&&stu[i].osecond>stu[i].isecond)
		cout << "�������������ѣ�" << ++money << endl;
	else
		cout << "�������������ѣ�" << money << endl;
}

void count_4(int i)  //�������Ϻ��������ʱ�估���ѵļ��� ��д��ʱ��д��������� 
{
	cout << "����������1������������" << endl;
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

void inquire() //��ѯѧ�����ϻ�ʱ�� 
{
	int num, i;
	long b;
	char a[20];
	do
	{
		cout << "��ѯ��ʹ��������1��ʹ��ѧ�Ű�2��" << endl;
		cin >> num;
	} while (num != 1 && num != 2);
	if (num == 1)
	{
		cout << "������������";
		gets_s(a);
		for (i = 0; i<30; i++)
		{
			if (strcmp(stu[i].name, a) == 0)
				break;
		}
	}
	else
	{
		cout << "������ѧ�ţ�";
		cin >> b;
		for (i = 0; i<30; i++)
		{
			if (stu[i].number == b)
				break;
		}
	}
	if (i == 30)
		cout << "û�����ѧ����" << endl;
	else
		cout << stu[i].name << endl << "�ϻ�ʱ�䣺" << stu[i].ihour << ":"
		<< stu[i].iminute << "��" << stu[i].isecond << "��" << endl;
	cout << "���践�ز˵���ҳ��������0��" << endl;
	int c;
	cin >> c;
	if (c == 0)
		menu();
}

void display() //��ѯ��ǰ������ʹ����� 
{
	int k;
	cout << "��������ţ�";
	cin >> k;
	if (stu[k].ihour == stu[k].ohour&&stu[k].iminute == stu[k].ominute&&stu[k].isecond == stu[k].osecond)
		cout << "����ʹ��" << "��" << "��" << endl;
	else
	{
		cout << "����ʹ�ã�" << "��" << endl;
		cout << "ʹ���߰༶��" << stu[k]._class << "     " << "ʹ����ѧ�ţ�" << stu[k].number << "     " << "ʹ����������" << stu[k].name << endl;
	}
	system("pause");
	cout << "���践�ز˵���ҳ��������0��" << endl;
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
	cout<<"*         �ӭʹ��СѼ������շѹ���ϵͳ��            *"<<endl; 
	cout<<"*                                                       *"<<endl;
	cout<<"*********************************************************"<<endl;
	menu();
}

