#include<cstdio>
#include<cstdlib>
#include<algorithm> 
using namespace std;
int main(){
	int n,*num;
	scanf("%d",&n);
	num = (int *)malloc(n * sizeof(int));
	for(int i = 0;i < n;i++)scanf("%d",&num[i]);
	sort(num,num + n);
	for(int i = 0;i < n;i++){
		if(i!=0)printf(" ");
		printf("%d",num[i]);
	}
	return 0;
} 
