#include <iostream>
using namespace std;
int main()
{
	cout << "10��40������������Ϊ��" << endl;
	int num;
	int sum = 0;
	int i;
	for (num = 10;num <= 40;num++)
	{
		for (i = 2;i < num;i++)
		{
			if(num % i == 0) break;
		}
		if (i == num)
		{
			cout << " " << num << " +";
			sum += num;
		}
	}
	cout << '\b';
	cout << "= " << sum << endl;
	return 0;
}