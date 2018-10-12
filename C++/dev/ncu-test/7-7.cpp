#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int gplt[4] = {0,0,0,0};//g0 p1 l2 t3
	char ch;
	while(cin.peek()!=10 && cin >> ch){
		if(ch == 'g' || ch == 'G')gplt[0]++;
		if(ch == 'p' || ch == 'P')gplt[1]++;
		if(ch == 'l' || ch == 'L')gplt[2]++;
		if(ch == 't' || ch == 'T')gplt[3]++;
	}
	while(gplt[0] || gplt[1] || gplt[2] || gplt[3] ){
		if(gplt[0]){
			gplt[0]--;
			printf("G");
		}
		if(gplt[1]){
			gplt[1]--;
			printf("P");
		}
		if(gplt[2]){
			gplt[2]--;
			printf("L");
		}
		if(gplt[3]){
			gplt[3]--;
			printf("T");
		}
	}
	return 0;
} 
