#include <iostream>
using namespace std;

int main()
{
	int num_1 , num_2 , num_3 , num_4;
	cout << "������Ҫ������λ��������";
	int num;
	cin >> num;
	num_1 = (num % 10 + 2) % 10;
	num_2 = (num % 100 / 10 + 2) % 10;
	num_3 = (num % 1000 / 100 + 2) % 10;
	num_4 = (num /1000 + 2) % 10;
	num = num_1 + num_2 * 10 + num_3 * 100 + num_4 * 1000;
	cout << "���ܵĽ��Ϊ��" << num <<endl;
	return 0;
}