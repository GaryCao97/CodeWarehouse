#include <stdio.h>
int main(){  
    __int64 a[35][2];
    int i,j,k;
    a[0][0] = 1;
    a[0][1] = 0;
    for (i = 1;i<=33;i++){  
        a[i][0] = 3 * a[i-1][0] + 2 * a[i-1][1];  
        a[i][1] = a[i-1][0] + a[i-1][1];  
    }
    while (cin >> j && j != -1)  
        printf("%I64d, %I64d\n",a[j][0],a[j][1]);
    return 0;   
}  
