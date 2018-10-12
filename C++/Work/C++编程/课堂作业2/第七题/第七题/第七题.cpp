#include <iostream>
#include <iomanip>
using namespace std;
void Line()
{
	cout << "----------------------------------------------" << endl;
}
int main()
{
	int N;
loop:
	cout << "Enter a number(o<=N<=10):";
	cin >> N;
	if (!(N>=1&&N<=10)) 
	{
		cout << "Error!!Please input again!" << endl;
		goto loop;
	}
	cout << N << " Layers of Digital Pyramid is:" << endl;
	Line();
	for (int i = 1;i <= N;i++)
	{
		cout << setw(2 * N - i) << " " ;
		for(int j = 1;j <= i;j++)
		{
			cout << setw(2) << i;
		}
		cout << endl;
	}
	Line();
	return 0;
}