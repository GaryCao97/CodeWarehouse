#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<map>  
#include<algorithm>  
#include<string>  
#include<vector>  
#include<sstream>// stringstrearm  
using namespace std;  
string A, Q;  
int i,B, num;  
  
int fun(char c)  
{  
        num*=10;  
        num+=c-'0';  
        Q+=(num/B)+'0';  
        return num%B;  
}  
  
int main()  
{  
        cin>>A>>B;  
        num=0;  
  
        for( i=0; i<A.size(); i++)  
                num=fun(A[i]);  
        for(i=0; i<Q.size(); i++)  
            if(Q[i]!='0'){  
                Q=Q.substr(i);  
                break;  
            }  
        cout<<Q<<" "<<num<<endl;  
        return 0;  
}
