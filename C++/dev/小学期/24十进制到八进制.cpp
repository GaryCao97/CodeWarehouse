#include<iostream>
using namespace std;
int main(){
	long long num10,input;
	int num8[20],i;
	while(cin >> num10){
		input = num10;
		i = 19;
		while(input){
			num8[i--] = input%8;
			input /= 8;
		}
		cout << "10进制 " << num10 << " 8进制 ";
		while(++i<20)cout << num8[i];
		cout << endl;
	}
	return 0;
}
