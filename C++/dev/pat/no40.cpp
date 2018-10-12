#include <stdio.h>
#include <string.h>
int main() {
    char str[100001];
    gets(str);
    int numT = 0;
    int numAT = 0;
    int numPAT = 0;
    for(int i = strlen(str) - 1; i >= 0; --i) {
        if(str[i] == 'T')
            ++numT;
        else if(str[i] == 'A')
            numAT = (numAT + numT) % 1000000007;  
        else {
            numPAT = (numPAT + numAT) % 1000000007;  
        }
    }
    printf("%d", numPAT);
    return 0;
}
