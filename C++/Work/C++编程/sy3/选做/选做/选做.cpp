#include <iostream>
using namespace std;
const int N = 1000;
int MinValue(int x,int y)
{
	int z;
	z = (x >= y) ? y : x;
	return z;
}
int Different(int x,int y)
{
	int z;
	if (x >= y) z = x - y;
	else z = y - x;
	return z;
}
int MinIndex(int x[],int y)
{
	int difference[N],min = x[0],index;
	for (int i = 0;i < N;i++)
	{
		difference[i] = Different(x[i],y);
		min = MinValue(difference[i],min);
	}
	for (int i = 0;i < N;i++)
	{
		if (difference[i] == min)
		{
			index = i;
			break;
		}
	}
	return index;
}
int main()
{
	int num0,num[N];
	cout << "Please select the first number: ";
	cin >> num0;
	for (int i = 0;i < N;num[i] = 1,i++);
	cout << "Please input some number(until number is 0): " << endl;
	for (int n = 0;n < N && num[n-1] != 0;n++)
	{
		cout<< "Please input No." << n + 1 << " : ";
		cin >> num[n];
	}
	int index = MinIndex(num,num0);
	cout << "The nearest number to " << num0 << " is No." << index + 1 << " : " <<  num[index] << endl;
	return 0;
}