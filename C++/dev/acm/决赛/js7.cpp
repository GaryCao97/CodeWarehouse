#include<iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    set<int> num;
    int n;
    int input;
    while(cin >> n){
              num.clear();
              for(int i = 0;i < n;i++){
                     cin >> input;
                     num.insert(input);
              }
              cout << num.size()<<endl;
            set<int>::iterator it;
            int tag = 0;
            for(it=num.begin();it!=num.end();it++)
            {
//                 if(tag == 0)
//                {
//                 cout<<*it;
//                 tag = 1;
//                 }
//                 else 
                 cout<<*it << " ";
            }
           cout << endl; 
    }
    return 0;
}
