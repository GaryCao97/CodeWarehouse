#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}
int mul(int a,int b,int g)
{
	return ( (a * b) / g);
}
int main()
{
	int a,b;
	cout << "请输入两个整数：";
	cin >> a >> b;
	cout << "最大公约数为：" << gcd(a,b) << " ,最小公倍数为：" << mul(a,b,gcd(a,b)) << endl;
}