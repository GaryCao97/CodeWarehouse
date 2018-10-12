#include <iostream>
using namespace std;
int max(int x, int y){
	int m = x;
	if (y>m)
		m = y;
	return m;
}
int main(){
	int a, b, c;
	int(*funp)(int, int); /*定义函数指针*/
	cout << "Input a,b:\t";
	cin >> a >> b;
	funp = max; /*函数指针指向具体的函数*/
	c = (*funp)(a, b); /*用函数指针调用函数*/
	cout << "max=" << c << endl;
	return 0;
}
