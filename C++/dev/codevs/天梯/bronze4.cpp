#include<cstdio>
int main(){  
    double a,b;
    scanf("%lf%lf",&a,&b);
    if((a-b)<=1e-8 && (a-b)>=-1e-8) printf("yes");
    else printf("no");
    return 0;
}
