#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
typedef struct{
	int address;
	int num;
	int next;
}link;
int main(){
	int start,n,k;
	cin >> start >> n >> k;
	link *p = (link*)malloc(n*sizeof(link));
	int i,pos = 0,m = k/2;
	for(i = 0;i < n;i++)
		scanf("%d %d %d",&p[i].address,&p[i].num,&p[i].next);
	if(start == -1){
		printf("-1\n");
		return 0;
	}
	for(i = 0,pos = 0;pos < n;){
		if(start == -1)break;
		if(p[i].address == start){
			link tmp = p[i];
			p[i]  = p[pos];
			p[pos] = tmp;
			start = p[pos++].next;
			i = 0;
		}
		else{
			i++;
		}
	}
	for(i = 0;i < pos/k;i++){
		for(int j = 0;j < m;j++){
			link tmp = p[j + k*i];
			p[j + k*i] = p[k*(i+1) - j - 1];
			p[k*(i+1) - j - 1] = tmp;
		}
	}
	for(i = 0;i < pos-1;i++){
		p[i].next = p[i+1].address;
	}
	p[pos-1].next = -1;
	for(i = 0;i < pos;i++){
		printf("%05d %d ",p[i].address,p[i].num);
		if(p[i].next != -1) printf("%05d",p[i].next);
		else printf("%d",p[i].next);
		printf("\n");
	}
	return 0;
}
