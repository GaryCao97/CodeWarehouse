#include<iostream>
#include<stdlib.h>
using namespace std;
#define INIT_NUM 100
#define INCREMENT_NUM 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct{
	char num[15];
	char name[10];//������ѧ�ű������ַ����ڣ���󳤶Ⱦ�Ϊ10���ַ� 
	float grade[5];//��1��4�ֱ�������ѧ�ƣ�0��ƽ���ɼ� 
}student;
typedef struct{
	student *stu;
	int length;
	int listsize;
}StuList;
Status InitList(StuList &L){
	//��ʼ��ѧ����Ϣ�� 
	L.stu = (student *)malloc(INIT_NUM * sizeof(student));
	if(!L.stu){
		return ERROR;
	}
	L.length = 0;
	L.listsize = INIT_NUM;
	return OK;
}
Status InputList(StuList &L){
	//��һ��ѧ����Ϣ������ѧ����Ϣ������ 
	if(L.length == L.listsize){
		L.stu = (student *)realloc(L.stu, (L.listsize + INCREMENT_NUM) * sizeof(student));
		if(!L.stu){
			return ERROR;
		}
		L.listsize += INCREMENT_NUM;
	}
	int i = L.length;
	cout << "������ѧ����ѧ�ţ�";
	cin >> L.stu[i].num;
	cout << "������ѧ����������";
	cin >> L.stu[i].name;
	for(int j = 1; j <= 4; j++){
		cout << "������ѧ���ĵ�" << j << "�ųɼ���";
		do{
			cin >> L.stu[i].grade[j];
			if(L.stu[i].grade[j] < 0 || L.stu[i].grade[j] > 100){
				cout << "����������Χ������������" << endl;
			}
		}while(L.stu[i].grade[j] < 0 || L.stu[i].grade[j] > 100);
	}
	L.stu[i].grade[0] = (L.stu[i].grade[1] + L.stu[i].grade[2] + L.stu[i].grade[3] + L.stu[i].grade[4]) / 4.0;
	L.length++;
	return OK;
}
Status SortBy(StuList &L, int num){
	//��ѧ����Ϣ����num��ɼ�����
	int i = L.length - 1;
	while (i > 0) {
		int pos = 0;
		for (int j = 0; j < i; j++){
			if (L.stu[j].grade[num] > L.stu[j + 1].grade[num]) {
				pos = j;
				student temp;
				temp = L.stu[j];
				L.stu[j] = L.stu[j + 1];
				L.stu[j + 1] = temp;
			}
		}
		i = pos;
	}
}
void Output_Elem(StuList &L){
	//�������Ҫ���ѧ���ĳɼ� 
	cout << "��������˷ֱ�Ϊ��" << endl;
	for(int i = 0; i < L.length; i++){
		for(int j = 1; j <= 4; j++){
			if(L.stu[i].grade[j] < 60){
				cout << L.stu[i].name << endl;
				break;
			}
		}
	}
	cout << "������˷ֱ�Ϊ��" << endl;
	for(int i = 0; i < L.length; i++){
		for(int j = 1; j <= 4; j++){
			if(L.stu[i].grade[j] > 90){
				cout << L.stu[i].name << endl;
				break;
			}
		}
	}
	
}
int main(){
	StuList SList;
	cout << "������ѧ��������";
	int n;
	cin >> n;
	InitList(SList);
	for(int m = 0; m < n; m++){
		InputList(SList);
	}
	SortBy(SList,0);
	Output_Elem(SList);
	return 0;
} 
