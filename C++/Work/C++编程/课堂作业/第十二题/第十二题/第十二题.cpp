#include <iostream>
using namespace std;

int main()
{
	int num = 2 , days = 1;
	double money = num * 0.8 , money_sum = money;
	while (num <= 100)
	{
		num *= 2;
		money = num * 0.8;
		money_sum += money;
		days++;
	}
	double average = money_sum / days;
	cout << "ƽ��ÿ�컨��" << average << "Ԫ" << endl;
}