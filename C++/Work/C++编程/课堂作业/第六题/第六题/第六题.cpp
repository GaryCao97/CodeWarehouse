#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout<<setiosflags(ios::right);

	for (int i = 1; i <= 4;i++)
	{
		cout<<setw(9-2*i);
		for(int n = 1; n <= 2 * i - 1; n++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	
	for (int i = 1; i <= 3;i++)
	{
		cout<<setw(2*i-1);
		for(int n = 5; n >= 2 * i - 1; n--)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}