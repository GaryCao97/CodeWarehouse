#include "Class.h"
#include<cstring>
#include<iostream>
using namespace std;
void Student::GetInformation(char *_Name,char *_Number,char *_Class)
{
	strcpy_s(Name,_Name);
	strcpy_s(Number,_Number);
	strcpy_s(Class,_Class);
}
int Student::GetStartTime(int hh,int mm,int ss)
{
	if(hh >= 24 || mm >= 60 || ss >= 60)
		return FALSE;
	Hour[1] = hh;
	Minute[1] = mm;
	Second[1] = ss;
	return TRUE;
}
int Student::GetStopTime(int hh,int mm,int ss)
{
	if(hh >= 24 || mm >= 60 || ss >= 60)
		return FALSE;
	Hour[2] = hh;
	Minute[2] = mm;
	Second[2] = ss;
	if(Student::SetTime())
		return TRUE;
	else return FALSE;
}
int Student::SetTime()
{
	Hour[0] = Hour[2] - Hour[1];
	Minute[0] = Minute[2] - Minute[1];
	Second[0] = Second[2] - Second[1];
	if(Second[0] < 0)
	{
		Second[0] += 60;
		Minute[0] -= 1;
	}
	else if(Second[0] >= 60)
	{
		Second[0] -= 60;
		Minute[0] += 1;
	}
	if(Minute[0] < 0)
	{
		Minute[0] += 60;
		Hour[0] -= 1;
	}
	else if(Minute[0] >= 60)
	{
		Minute[0] -= 60;
		Hour[0] += 1;
	}
	if(Hour[0] < 0)
		return FALSE;
	return TRUE;
}
void Student::ShowMoney()
{
	if(Minute[0] != 0 || Second[0] != 0)
		Money = (Hour[0] + 1) * 1;
	else Money = Hour[0];
	printf("上机花费%d元。\n",Money);
}
void Student::ShowInformation()
{
	printf("学号：%s\n姓名：%s\n班级：%s\n上机时间%d:%d:%d\n",Number,Name,Class,Hour[0],Minute[0],Second[0]);
}
int Student::Check(char *_Name, char *_Number, char *_Class)
{
	if (strcmp(_Name, Name) == 0)
		return TRUE;
	else if (strcmp(_Number, Number) == 0)
		return TRUE;
	else if (strcmp(_Class, Class) == 0)
		return TRUE;
	else return FALSE;
}