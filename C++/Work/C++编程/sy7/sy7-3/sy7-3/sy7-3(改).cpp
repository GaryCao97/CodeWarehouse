#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct information
{
	int number;
	char name[10];
	double programmer,database,network,operate_system;
	double aver;
}student[15];
void inGrade()
{
	cout << "请输入同学的信息："<< endl << "学号 姓名 programmer database network operate_system" << endl;
	for(int i = 0;i < 15;i++)
	{
		cin >>student[i].number 
			>>student[i].name 
			>>student[i].programmer
			>>student[i].database
			>>student[i].network
			>>student[i].operate_system;
	}
}
void aveGrade()
{
	for(int i = 0;i < 15;i++)
		student[i].aver = ( student[i].programmer + student[i].database + student[i].network + student[i].operate_system ) / 4.0;
}
void maxGrade()
{
	struct information temp;
	int n,m,i;
	for(n = 0;n < 15;n++)
	{
		for(m = 0;m < n;m++)
		{
			if (student[n].aver > student[m].aver)
			{
				temp = student[n];
				for(i = n;i > m;i--)
				{
					student[i].number = student[i-1].number;
					strcpy_s(student[i].name,student[i-1].name);
					student[i].programmer = student[i-1].programmer;
					student[i].database = student[i-1].database;
					student[i].network = student[i-1].network;
					student[i].operate_system = student[i-1].operate_system;
					student[i].aver = student[i-1].aver ;
				}
				student[m] = temp;
				break;
			}
		}
	}
}
void outGrade()
{
	cout << endl << "处理后" << endl;
	for(int i = 0;i < 15;i++)
	{
		cout<<setw(4);
		cout<<student[i].number << " "
			<<student[i].name  << " " << setw(4)
			<<student[i].programmer << " " << setw(4)
			<<student[i].database << " " << setw(4)
			<<student[i].network << " " << setw(4)
			<<student[i].operate_system << " " << setw(6)
			<<student[i].aver << endl; 
	}
}
int main()
{
	inGrade();
	aveGrade();
	maxGrade();
	outGrade();
	return 0;
}