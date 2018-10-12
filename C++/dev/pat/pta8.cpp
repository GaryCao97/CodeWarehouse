#include<iostream>
#include<string.h>
using namespace std;
typedef struct{
	char Sex;
	double Height;
	double OtherHeight;
}Info;
int main(){
	int n;
	cin >> n;
	Info arr[n];
	for(int i = 0;i < n;i ++){
		cin >> arr[i].Sex >> arr[i].Height;
		//（女方的身高）×1.09 =（男方的身高）  F女   M男 
		if(arr[i].Sex == 'F'){
			arr[i].OtherHeight = arr[i].Height * 1.09;
		} 
		if(arr[i].Sex == 'M'){
			arr[i].OtherHeight = arr[i].Height / 1.09;
		} 
	} 
	for(int i = 0;i < n;i ++){
		printf("%.2lf\n",arr[i].OtherHeight);
	} 
	return 0;
}
