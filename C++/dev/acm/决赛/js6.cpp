#include<iostream>
using namespace std;
int main(){
    int num,n,m;
    cin >> num;
    for(int i = 0;i < num;i++){
            cin >> n >> m;
            int ans = (n)%(m+1);
            if(ans > 0)cout << "first" << endl;
            else cout <<"second"<<endl; 
    }
    system("pause");
    return 0;
}
