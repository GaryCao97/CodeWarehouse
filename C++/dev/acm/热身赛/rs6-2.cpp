#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int cmp(const void *a,const void *b);
typedef struct people{
    char name[15];
    int time;
    int num;
}people;
people peo1[1010];
int main(){
    int n,m,num,time,num1,i,a,b;
    char name[15];
    num1=0;
    scanf("%d%d",&n,&m);
    while(~scanf("%s",&name)){
        num=time=0;
        for(i=0;i<n;i++){
            if(scanf("%d(%d)",&a,&b)==2){
                num++;
                time+=(a+b*m);
            }
            else{
                if(a>0){
                    num++;
                    time+=a;
                }
            }
            
        }
        strcpy(peo1[num1].name,name);
        peo1[num1].time=time;
        peo1[num1].num=num;
        num1++;
    }
    qsort(peo1,num1,sizeof(people),cmp);
    for(i=0;i<num1;i++){
        printf("%-10s %2d %4d\n",peo1[i].name,peo1[i].num,peo1[i].time);
    }
    return 0;
}
int cmp(const void *a,const void *b){
    people *p = (people*)a,*q=(people *)b;
    if(p->num!=q->num) return q->num-p->num;
    if(p->time!=q->time) return p->time-q->time;
    return strcmp(p->name,q->name);
}
