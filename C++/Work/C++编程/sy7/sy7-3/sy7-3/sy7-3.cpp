#include <iostream>
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
int maxGrade()
{
	double max = student[0].aver;
	int max_i = 0;
	for(int i = 0;i < 15;i++)
		if(student[i].aver > max)
		{
			max = student[i].aver;
			max_i = i;
		}
	return max_i;
}
void outGrade(int max_i)
{
	cout<<student[max_i].number << " "
		<<student[max_i].name  << " "
		<<student[max_i].programmer << " "
		<<student[max_i].database << " "
		<<student[max_i].network << " "
		<<student[max_i].operate_system << " "
		<<student[max_i].aver << endl;
}
int main()
{
	inGrade();
	aveGrade();
	maxGrade();
	outGrade(maxGrade());
	return 0;
}