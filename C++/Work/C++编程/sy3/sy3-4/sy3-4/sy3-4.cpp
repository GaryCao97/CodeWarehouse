#include <iostream>
using namespace std;
int main()
{
	cout << "飞机票价为1000元！" << endl;
	int month , tickets;
	double per_money , money;
loop:
	cout << "出行时间：";
	cin >> month;
	cout << "出行人数：";
	cin >> tickets;
	if (month >= 7 && month <= 9)
	{
		if (tickets >= 20) per_money = 0.9;
		else per_money = 0.95;
	}
	else 
	{
		if (tickets >= 20) per_money = 0.8;
		else per_money = 0.9;
	}
	money = 1000 * tickets * per_money;
	cout << "您所花费的总金额为" << money << endl;
	goto loop;
	return 0;
}