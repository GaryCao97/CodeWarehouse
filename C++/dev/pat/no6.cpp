#include<iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int a,b,c;
	a = num/100;
	b = (num%100)/10;
	c = num%10;
	int i = 1;
	while(a){
		cout << 'B';
		a--;
	}
	while(b){
		cout << 'S';
		b--;
	}
	while(c){
		cout << i++;
		c--;
	}
	return 0;
} 
