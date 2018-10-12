#include<cstdio>

int main(){
	int ji,ou,num,zheng;
	while(scanf("%d",&num)!=EOF){
		ji = ou = 0;
		while(num--){
			scanf("%d",&zheng);
			if(zheng%2)ji++;
			else ou++;
		}
		printf("%d %d\n",ji,ou);
	}
	return 0;
} 
