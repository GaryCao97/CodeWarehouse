#include <iostream>
using namespace std;
int primeNum(int num)
{
	for (int i = 2;i < num;i++)
		if (num % i == 0)
			return 0;
	return num;
}
int main()
{
	int integer;
	cout << "请输入一个整数：";
	cin >> integer;
	if (integer <= 0)
	{
		cout << "你输入的数据有误！";
		return 0;
	}
	if (integer == 1 || primeNum(integer) == 0)
		cout << "Num is not a prime." << endl;
	else 
		cout << "Num is a prime." << endl;
	return 0;
}