#include<cstdio>
const int MAX = 10000000+5;
int main(){
	int n,index,order,i;
	scanf("%d",&n);
	for(i = 1;i < MAX;i++){
		if((i + 1) * i / 2 >= n){
			index = n - ((i - 1) * i / 2);
			order = i;
			break;
		}
	}
	if(order%2)printf("%d/%d",order - index + 1,index);
	else printf("%d/%d",index,order - index + 1);
	return 0;
} 
