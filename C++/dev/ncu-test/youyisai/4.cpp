#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	char ch;
	int n = 0;
	while(scanf("%c",&ch)&&ch!='@'){
		getchar();
		if(n != 0)printf("\n");
		scanf("%d",&n);
		getchar();
		for(int j = 0;j < n-1;j++)printf(" ");
		printf("%c",ch);
		printf("\n");
		for(int i = 1;i<n-1;i++){
			for(int j = 0;j < n-i-1;j++)printf(" ");
			printf("%c",ch);
			for(int j = 0;j < 2 * i-1;j++)printf(" ");
			printf("%c",ch);
			printf("\n");
		}
		if(n!=1){
			for(int i = 0;i < 2*n-1;i++)printf("%c",ch);
			printf("\n");
		}
	}
	return 0;
} 
