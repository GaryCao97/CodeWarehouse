#include<stdio.h>
int main(){
	__int64 num;
	while(scanf("%64I",&num)!=EOF){
		if(num == 0 || num == 1)printf("0\n");
		else printf("2\n");
	}
	return 0;
} 
