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
	cout << "����������a��" ;
	cin >> a;
	cout << "�����������ִ�д���n��";
	cin >> n;
	root = x(n);
	cout << "����" << a << "������ƽ����Ϊ��" << root << endl;
	return 0;
}