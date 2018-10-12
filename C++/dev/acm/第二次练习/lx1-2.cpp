#include<iostream>
using namespace std;
int main(){
	int m,n,tag;
	while(scanf("%d %d",&m,&n)!=EOF){
		tag = 0;
		for(int i = m;i <= n;i++){
			int a,b,c;
			a = i/100;
			b = (i%100) /10;
			c = i%10;
			if(i == a*a*a + b*b*b + c*c*c){
				if(tag!=0)printf(" ");
				tag++;
				printf("%d",i);
			}
		}
		if(tag == 0) printf("no\n");
		else printf("\n");
	}
	return 0;
}
