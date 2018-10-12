#include <iostream>
#include <iomanip>
using namespace std;
int n;
int MaxIndex(int a[10][10])
{
	int Max = a[0][0],index;
	for (int i = 0;i < n;i++)
		for(int j = 0; j < n;j++)
			Max = (Max > a[i][j])? Max :a[i][j];
	for (int i = 0;i < n;i++)
		for(int j = 0; j < n;j++)
			if (Max == a[i][j]) index = i;
	return index;
}
int MinIndex(int a[10][10])
{
	int Min = a[0][0],index;
	for (int i = 0;i < n;i++)
		for(int j = 0; j < n;j++)
			Min = (Min < a[i][j])? Min :a[i][j];
	for (int i = 0;i < n;i++)
		for(int j = 0; j < n;j++)
			if (Min == a[i][j]) index = i;
	return index;
}
int main()
{
	cout << "������һ��2��10֮���������";
	cin >> n;
	int num[10][10];
	cout << "������һ��" << n << "������ʽ��" << endl;
	for (int i = 0;i < n;i++)
		for(int j = 0; j < n;j++)
			cin >> num[i][j];
	cout << "ԭʼ���� �� n = " << n << endl;
	for (int i = 0;i < n;i++)
	{
		for(int j = 0; j < n;j++)
			cout << setw(4) <<num[i][j];
		cout << endl;
	}
	int Temp[10] , max_i = MaxIndex(num) , min_i = MinIndex(num);
	for (int j = 0;j < n;j++)
	{
		Temp[j] = num[max_i][j];
		num[max_i][j] = num[min_i][j];
		num[min_i][j] = Temp[j];
	}
	cout << "������� ��"<< endl;
	for (int i = 0;i < n;i++)
	{
		for(int j = 0; j < n;j++)
			cout << setw(4) << num[i][j];
		cout << endl;
	}
	return 0;
}