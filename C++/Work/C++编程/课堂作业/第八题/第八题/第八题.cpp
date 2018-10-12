#include <iostream>
using namespace std;
int a;
double x(int m)
{
	double result;
	if (m == 0)
	{
		result = a / 2.0;
	}
	else if (m >= 1)
	{
		result = ( x(m-1) - a / x(m-1) ) / 2.0;
	}
	return result;
}

int main()
{
	int n;
	double root;
	extern int a;
	cout << "请输入正数a：" ;
	cin >> a;
	cout << "请输入迭代法执行次数n：";
	cin >> n;
	root = x(n);
	cout << "正数" << a << "的算术平方根为：" << root << endl;
	return 0;
}