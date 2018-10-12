#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cout << "Please input a integer n: ";
	cin >> n;
	int i,j;
	cout << setiosflags(ios::left);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
			cout << setw(4) << j;
		cout << endl;
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<=i;j++)
			cout << setw(4) << j;
		cout << endl;
	}
	return 0;
}