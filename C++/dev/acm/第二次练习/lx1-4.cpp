#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		int a = 0,b = 0,c = 0;
		double num;
		for(int i = 0;i < n;i++){
			scanf("%lf",&num);
			if(num == 0)b++;
			else if(num < 0)a++;
			else c++;
		}
		printf("%d %d %d\n",a,b,c);
		scanf("%d",&n);
	}
	return 0;
}
