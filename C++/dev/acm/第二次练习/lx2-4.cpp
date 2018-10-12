#include <stdio.h>
#include <math.h>
int main(){
    int n, m, delta;
    scanf("%d%d", &m, &n);
    while(m||n){
        delta = sqrt(m*m - 4*n);
        if(delta * delta == m*m - 4*n && (m + delta)%2 == 0)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d%d", &m, &n);
    }
    return 0;
}
