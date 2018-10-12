#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct P
{
    char name[15];
    int tm;
    int sj;
}p[1005];
int n,m;
int cmp(const void *a,const void *b)
{
    struct P *a1= (P*) a;
    struct P *b1= (P*) b;
    if(a1->tm!=b1->tm) return b1->tm-a1->tm;
    else if(a1->sj!=b1->sj) return a1->sj-b1->sj;
    else return a1->name-b1->name;
}
int main()
{
    int i,j,num,f,t,res;
    char str[10];
    scanf("%d%d",&n,&m);
    num=0;
    while(scanf("%s",&p[num].name)!=EOF)
    {
        p[num].tm=0;
        p[num].sj=0;
        for(i=0;i<n;i++)
        {

            scanf("%s",str);
            res=sscanf(str,"%d(%d)",&f,&t);
            if(res==2)
            {
                p[num].tm++;
                p[num].sj+=f;
                p[num].sj+=m*t;
            }
            else if(res==1&&f>0)
            {
                p[num].tm++;
                p[num].sj+=f;
            }
        }
        num++;
    }
    qsort(p,num,sizeof(p[0]),cmp);
    for(i=0;i<num;i++)
    {
        printf("%-10s %2d %4d",p[i].name,p[i].tm,p[i].sj);
    }
    return 0;
}
