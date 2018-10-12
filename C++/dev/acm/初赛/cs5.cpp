#include<stdio.h>
int main(){
	int num;
	while(~scanf("%d",&num)){
		int i,a,b,c,d;
		for(i = num+1;;i++){
			a = i/1000;
			b = i%1000 / 100;
			c = i%100 / 10;
			d = i%10;
			if((a!=b) && (a!=c) && (a!=d) && (b!=c) && (b!=d) && (c!=d))break;
		}
		printf("%d\n",i);
	}
	return 0;
} 
