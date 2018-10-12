#include<cstdio>
#include<cmath>
void move(int n, char x, char y){
	printf("%d from %c to %c\n",n,x,y);
}
void hnt(int n, char from, char to, char depend){
    if(n == 1) move(1, from, to);
    else{
        hnt(n - 1, from, depend, to);
        move(n, from, to);
        hnt(n - 1, depend, to, from);
    }
}
int main(){
    int n;
    char a = 'A', b = 'B', c = 'C';
    scanf("%d",&n);
    int ans = pow(2, n) - 1;
    printf("%d\n",ans);
    hnt(n, a, c, b);
    return 0;
}
