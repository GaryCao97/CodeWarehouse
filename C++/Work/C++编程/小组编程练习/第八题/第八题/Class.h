#define TRUE 1
#define FALSE 0
#define NULL 0
class Student
{
public:
	void GetInformation(char *_Name,char *_Number,char *_Class);								//获取学生信息
	int GetStartTime(int hh = 0,int mm = 0,int ss = 0);											//获取初始时间，成功则返回TRUE
	int GetStopTime(int hh = 0,int mm = 0,int ss = 0);											//获取结束时间并计算时间差，成功则返回TRUE
	void ShowMoney();																			//输出上机花费
	void ShowInformation();																		//输出学生信息
	int Check(char *_Name = NULL,char *_Number = NULL,char *_Class = NULL);						//查找对比，如果是则返回TRUE
protected:
	char Name[20];
	char Number[20];
	char Class[50];
	int Hour[3],Minute[3],Second[3];
	int Money;
	int SetTime();
};