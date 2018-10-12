#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){
	int n,i;
	long long *num,sumO = 0,sumI = 0,max,numO = 0,numI = 0;
	cin >> n;
	num = (long long*)malloc(n * sizeof(long long));
	for(i = 0;i < n;i++){
		cin >> num[i];
	}
	sort(num,num + n);
	for(i = 0;i < n;i++){
		if(i < n / 2){
			sumI += num[i];
			numI++;
		}
		else{
			sumO += num[i];
			numO++;
		}
	}	
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %ld",numO,numI,sumO - sumI);
	return 0;
}
