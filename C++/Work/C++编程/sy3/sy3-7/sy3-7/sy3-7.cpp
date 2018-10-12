#include<iostream>
using namespace std;

int Prime(int x)															/*定义一个判断一个数是否是素数的函数*/
{
	for (int n = 2 ; n < x ; n++)
	{
		if (x % n != 0) {continue;}
		else {return 0;break;}
	}
	return 1;
}

int main()
{
	cout << "请输入一个正整数：";
	int integer ;															/*提示输入初始正整数*/
	cin >> integer;
	
	int prime[10];															/*定义prime[]数组存放素数*/
	int sum = 0;
	
	for (int i = 0 ; i < 10 ; i++) prime[i]=0;
	
	for (int n = 0 ; n < 10 ; n++)											/*用循环语句将前十个素数分别输入到prime[]数组中*/
	{
		int _num;
		if (n == 0) _num = 0;
		else _num = integer - prime[n-1] + 1;
		for (int i = integer - _num ; i > 1 ; i--)							/*从上一个素数后开始判断素数，并依次减小数字*/
		{
			if (Prime(i) != 0) {prime[n] = i;break;}						/*判断i是否为素数，如果是则赋值给prime[]数组*/
		}
		sum = sum + prime[n];												/*素数求和*/
	}
	
	{
		cout << prime[0];
		int i = 1;
		while((i <= 9) && (prime[i] != 0))
		{
			cout << " + " << prime[i] ;
			i++;
		}
		cout << " = " << sum << endl;
		if (prime[i] == 0) cout << "整数" << integer << "内的素数不足十个。" << endl;
	}
	return 0;
}