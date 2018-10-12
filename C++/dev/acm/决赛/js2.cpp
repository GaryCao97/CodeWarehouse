#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxn 15
int hang[maxn],res[maxn];
int zuoxie[maxn],youxie[maxn];
int n;
int cur;
void dfs(int x)
{
    if(x==n)
    {
        cur++;
        return ;
    }
    for(int i=x;i<n;i++)
    {
        if(hang[i])continue;
        for(int j=0;j<n;j++)
        {
            if(res[j]||zuoxie[i+n-1-j]||youxie[i+n-(n-j)]) continue;
            hang[i]=1;
            res[j]=1;
            zuoxie[i+n-1-j]=1;
            youxie[i+n-(n-j)]=1;
            dfs(x+1);
            hang[i]=0;
            res[j]=0;
            zuoxie[i+n-1-j]=0;
            youxie[i+n-(n-j)]=0;
        }
    }

}
int main()
{
    for(n=1;n<=10;n++)
    {
        memset(hang,0,sizeof hang);
        memset(res,0,sizeof res);
        memset(zuoxie,0,sizeof zuoxie);
        memset(youxie,0,sizeof youxie);
        cur=0;
        dfs(0);
        cout<<"n="<<n<<" "<<cur<<endl;
    }
    system("pause");
}
