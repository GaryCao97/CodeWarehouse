#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
	char *number;
	int SeatNum;
}student;
int main(){
	int n;
	cin >> n;
	student *stu = (student*)malloc((n+1)*sizeof(student));
	char *ch;
	int order,sNum;
	for(int i = 0;i < n;i++){
		ch = (char*)malloc(16*sizeof(char));
		cin >> ch >> order >> sNum;
		stu[order].number = ch;
		stu[order].SeatNum = sNum;
	}
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> order;
		cout << stu[order].number << ' ' << stu[order].SeatNum;
		if(i != n-1) cout << endl;
	}
	return 0;
}
