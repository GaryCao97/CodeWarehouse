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
	link *q = (link*)malloc(1000000*sizeof(link));
	link *p = (link*)malloc(n*sizeof(link));
	int i,pos = 0,m = k/2;
	for(i = 0;i < n;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		q[x].address = x;
		q[x].num = y;
		q[x].next = z;
	}
	if(start == -1){
		printf("-1\n");
		return 0;
	}
	for(i = 0,pos = 0;;){
		if(start == -1)break;
		p[i].address = q[start].address;
		p[i].num = q[start].num;
		p[i].next = q[start].next;
		start = q[start].next;
		i++,pos++;
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
