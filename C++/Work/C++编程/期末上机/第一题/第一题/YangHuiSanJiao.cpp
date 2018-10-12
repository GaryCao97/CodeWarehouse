#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;
void Create(int arr[][N])
{
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}
void main()
{
	int YangHui[N][N];
	Create(YangHui);
	cout << setiosflags(ios::left);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << setw(3) << YangHui[i][j];
		}
		printf("\n");
	}
}