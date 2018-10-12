
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef struct Peo{
	int num;
	double money;
	int index;
}Peo;
bool comp(Peo p,Peo q){
	if((p.money == q.money) && (p.num == q.num))return p.index < q.index;
	else if(p.money == q.money)return p.num > q.num;
	else return p.money > q.money;
}

int main(){
	Peo *p;
	int n,i,k,num,total,index,money;
	while(scanf("%d",&n)!=EOF){
		num = n;
		p = (Peo*)malloc(n * sizeof(Peo));
		for(i = 0;i<num;i++){
			p[i].index = i+1;
			p[i].money = 0;
			p[i].num = 0;
		} 
		i = 0;
		while(n--){
			scanf("%d",&k);
			total = 0;
			while(k--){
				scanf("%d %d",&index,&money);
				total+=money;
				p[index-1].money+=money;
				p[index-1].num+=1;
			}
			p[i].money-=total;
			i++;
		}
		sort(p,p+num,comp);
		for(i = 0;i < num;i++){
			p[i].money/=100.0;
			printf("%d %.2lf\n",p[i].index,p[i].money);
		}
	}
	return 0;
}
