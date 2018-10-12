#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char p[1001],q[1001];
	cin >> p >> q;
	int num1[255];
	int num2[255];
	int tag = 1;
	int flat[255];
	int sum = 0;
	for(int i = 0;i<255;i++){
		num1[i] = 0;
		num2[i] = 0;
		flat[i] = 0;
	}
	for(int i = 0;i<strlen(p);i++)
		num1[p[i]]++;
	for(int i = 0;i<strlen(q);i++)
		num2[q[i]]++;
	for(int i = 0;i<strlen(q);i++){
		if(num1[q[i]]<num2[q[i]]){
			tag = 0;
			if(flat[q[i]] == 0){
				sum+= num2[q[i]] - num1[q[i]];
				flat[q[i]] = 1;
			}
		}
	}
	if(tag == 1)cout << "Yes " << strlen(p) - strlen(q);
	else if(tag == 0)cout << "No " << sum;
	return 0;
}
