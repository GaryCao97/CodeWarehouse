#define TRUE 1
#define FALSE 0
#define NULL 0
class Student
{
public:
	void GetInformation(char *_Name,char *_Number,char *_Class);								//��ȡѧ����Ϣ
	int GetStartTime(int hh = 0,int mm = 0,int ss = 0);											//��ȡ��ʼʱ�䣬�ɹ��򷵻�TRUE
	int GetStopTime(int hh = 0,int mm = 0,int ss = 0);											//��ȡ����ʱ�䲢����ʱ���ɹ��򷵻�TRUE
	void ShowMoney();																			//����ϻ�����
	void ShowInformation();																		//���ѧ����Ϣ
	int Check(char *_Name = NULL,char *_Number = NULL,char *_Class = NULL);						//���ҶԱȣ�������򷵻�TRUE
protected:
	char Name[20];
	char Number[20];
	char Class[50];
	int Hour[3],Minute[3],Second[3];
	int Money;
	int SetTime();
};