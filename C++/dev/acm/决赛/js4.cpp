#include<stdio.h>
#include<stdlib.h>
#include<cmath>
int f(int n){
	int i,j;
	i=sqrt(n) + 1;
	for(j=2;j<=i;j++)
		if(n%j==0)
			break;
	if(j>i)
		return 1;
	else
		return 0;
}
void print(int n,int a[]){
	int i;
	for(i=0;i<n;i++)
		printf(i?" %d":"%d",a[i]);
	printf("\n");
}
void place(int k,int n,int a[]){
	int i,j;
	if(k>=n){
		if(f(a[k-1]+1))
			print(n,a);
	}
	else
		for(i=k%2+1;i<=n;i++){
			for(j=0;j<k;j++)
				if(a[j]==i)
					break;
			if(j>=k)
				if(f(a[k-1]+i))	{
					a[k]=i;
					place(k+1,n,a);
				}
		}
}
int main(){
	int n,k,a[15],i=1;
	while(scanf("%d",&n)!=EOF){
		a[0]=1;
		k=1;
		place(k,n,a);
		i++;
	}
	return 0;
}
