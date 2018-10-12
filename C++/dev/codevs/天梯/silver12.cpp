#include<cstdio>
int f(int x){
	if(x >= 0)return 5;
	else return f(x + 1) + f(x + 2) + 1;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
} 
