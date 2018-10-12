#include<iostream>
using namespace std;
int f(int k,int n){
	//函数 f（k，n）=f（k，n-1）+f（k-1,n-1）{当k>0&&k<n时成立
	//当k等于0或k等于n时，f（k，n）=1；即{k=0||k=n}
	if(k == 0 || k == n)return 1;
	else return f(k,n-1) + f(k-1,n-1);
}
int main(){
	int k,n;
	while(scanf("%d %d",&k,&n)!=EOF){
		printf("%d\n",f(k,n));
	}
	return 0;
}
