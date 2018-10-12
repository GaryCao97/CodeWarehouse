#include <stdio.h>
#include <malloc.h>
#include <algorithm>
using namespace std;
int main(){
	int n,m,*a,b,MAXL,MINL;
	while(scanf("%d%d",&m,&n)!=EOF){
		a = (int*)malloc(n * sizeof(int));
		for(int i = 0;i < n;i++){
			scanf("%d",&b);
			a[i] = b>(m-b)?b:(m-b);
		}
		sort(a,a+n);
		MAXL = a[n-1];
		MINL = (m-a[0]);
		printf("%d %d\n",MINL,MAXL);
	}
	return 0;
} 
