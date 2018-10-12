#include<iostream>
#include<string>
using namespace std;
int main(){
	string str,sub;
	cin >> str >> sub;
	cout << str.find(sub) + 1;
    return 0;
}
