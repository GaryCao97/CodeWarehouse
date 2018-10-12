#include<iostream>
using namespace std;
int main(){
	double num,absNum;
	while(scanf("%lf",&num)!=EOF){
		absNum = (num>0)?num:(-num);
		printf("%.2lf\n",absNum);
	}
	return 0;
}
