#include<iostream>
using namespace std;
int Prime(int x)															/*定义一个判断数是否是素数的函数*/
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
	int integer , prime[10] , sum = 0 , n;
	cout << "请输入一个正整数：";											/*提示输入初始正整数*/
	cin >> integer;
	for (int m = 0 ; m < 10 ; m++) prime[m]=0;								/*初始化prime[]数组*/
	int num = integer;														/*用于代替整数integer的过程变量num*/
	for (n = 0 ; n < 10 ; n++)												/*用循环语句将前十个素数分别输入到prime[]数组中*/
	{
		for (; num > 1 ;num--)												/*从num开始判断素数，并依次减小数字*/
			if (Prime(num) != 0) {prime[n] = num--;break;}					/*判断num是否为素数，如果是则赋值给prime[]数组*/
		sum += prime[n];													/*素数求和*/
		if (prime[n] != 0) cout << prime[n] << " + ";
	}
	cout << '\b' << '\b' << "= " << sum << endl;
	if (prime[9] == 0) cout << "整数" << integer << "内的素数不足十个。" << endl;
	return 0;
}