#include <iostream>
using namespace std;
extern int combinNum(int ,int);
int main()
{
	int m,n,combin;
	cout << "������������������";
	cin >> m >> n;
	if(m <=0 || n <= 0 || m < n)
	{
		cout << "���������������" << endl;
		return 0;
	}
	combin = combinNum(m,n);
	cout << "Combin " << m << "," << n << " is " << combin << endl;
	return 0;
}