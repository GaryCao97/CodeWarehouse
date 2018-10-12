#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float score[4][6],aver[5];
	cout << "ÊäÈë³É¼¨" << endl;
	cout << setiosflags(ios::left);
	score[3][5] = 0;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 5;j++)
		{
			scanf("%f",&score[i][j]);
			score[i][5] = 0;
			score[3][j] = 0;
		}
	cout << "Input : " << endl;	
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 5;j++)
			cout << setw(6) << setprecision(3) << score[i][j];
		cout << endl;
	}
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 5;j++)
			score[i][5] += score[i][j] / 5;
	for (int j = 0;j < 5;j++)
		for (int i = 0;i < 3;i++)
			score[3][j] += score[i][j];
	cout << "Output :" << endl;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 6;j++)
			cout << setw(6) << setprecision(3) << score[i][j];
		cout << endl;
	}
	for (int j = 0;j < 5;j++)
		aver[j] = score[3][j] / 3;
	cout << "Average : " << endl;
	for (int j = 0;j < 5;j++)
		cout << setw(6) << setprecision(3) << aver[j];
	return 0;
}