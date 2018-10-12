#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
	char num[19];
}IP;
int main(){
	int Q[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	IP *p,*q;
	int n;
	cin >> n;
	p = (IP*)malloc(n*sizeof(IP));
	q = (IP*)malloc(n*sizeof(IP));
	int i,j,k;
	for(i = 0,j = 0;i < n;i++){
		cin >> p[i].num;
		int sum = 0;
		for(k = 0;k < 17;k++){
			if(p[i].num[k]>='0' && p[i].num[k] <= '9')
				sum += ((p[i].num[k] - '0') * Q[k]);
			else{
				q[j++]= p[i];
				sum = 0;
				break;
			}
		}
		if(sum != 0 && p[i].num[17] != M[sum%11]) q[j++]= p[i];
	}
	if(j == 0)cout << "All passed";
	for(i = 0;i < j;i++)cout << q[i].num << endl;
	return 0;
}
