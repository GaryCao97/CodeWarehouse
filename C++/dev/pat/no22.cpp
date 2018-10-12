#include<iostream>  
using namespace std;  
  
void test(long long m,long long k){  
    if(m/k==0)
		cout<<m;  
    else{   
       test(m/k,k);  
       cout<<m%k;
	}  
}  
int main(){  
    long long A,B,D;
    cin>>A>>B>>D;
    long long ans=A+B;
    test(ans,D);
    return 0;  
}
