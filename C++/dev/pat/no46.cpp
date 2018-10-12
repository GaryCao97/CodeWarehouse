#include<iostream>
using namespace std;
int main(){  
    int n,i;
    int A_s, A_p, B_s, B_p;
    int A_num = 0, B_num = 0;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> A_s>>A_p>>B_s>>B_p;
        if (A_s + B_s == A_p && A_s + B_s != B_p)
            B_num++;
        if (A_s + B_s == B_p && A_s + B_s != A_p)
            A_num++;
    }
    cout << A_num << ' ' << B_num;
    return 0;
} 
