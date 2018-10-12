#include <iostream>
#include <iomanip>
#define N 10
using namespace std;
int main()
{
	double num[N],*p = num,sum = 0,aver;
	for(int i = 0;i < N;i++)
	{
		cin >> *(p+i);
		sum += *(p+i);
	}
	aver = sum / N;
	cout << "Average is " << setiosflags(ios::fixed) << setprecision(2) << aver << endl;
}