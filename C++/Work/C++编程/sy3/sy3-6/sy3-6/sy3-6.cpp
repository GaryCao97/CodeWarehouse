#include <iostream>
using namespace std;
int main()
{
	cout << "������1��1000�ڵ�����������" ;
	int num;
	cin >> num;
	cout << "Input  : " << num << endl;
	cout << "Output : ";
	int n = 1;
	while(n<=num)
	{
		if (num % n == 0) cout << n << ", ";
		n++;
	}
	cout << endl;
	return 0;
}