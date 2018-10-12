#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n;
    float p;
    int seq[100005];
    int res = 0;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&seq[i]);
    }
    sort(seq, seq+n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+res; j < n;++j){
            if (seq[j] <= seq[i]*p) {
                if (j-i > res) {
                    res = j - i;
                }
            }else{
                break;
            }
            
        }
    }
    printf("%d",res+1);
    return 0;
}
