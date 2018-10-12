#include<stdlib.h>
#include<iostream>
#include <algorithm>
using namespace std;
int comp(int n1,int n2){
	return n1>n2;
}
int main(){
	int n,*num;
	while(scanf("%d",&n)!=EOF){
		num = (int*)malloc(n*sizeof(int));
		for(int i = 0;i < n;i++)scanf("%d",&num[i]);
		sort(num,num+n,comp);
		for(int i = 0;i < n;i++)printf("%d ",num[i]);
		printf("\n");
	}
	return 0;
}
