#include <iostream>
using namespace std;
int main()
{
	cout << "�ɻ�Ʊ��Ϊ1000Ԫ��" << endl;
	int month , tickets;
	double per_money , money;
loop:
	cout << "����ʱ�䣺";
	cin >> month;
	cout << "����������";
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
	cout << "�������ѵ��ܽ��Ϊ" << money << endl;
	goto loop;
	return 0;
}