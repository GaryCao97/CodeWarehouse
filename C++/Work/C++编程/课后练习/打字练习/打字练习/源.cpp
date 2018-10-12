#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	char a[30],b[30];
	for (int i = 0;i < 30;i++)
	{
		a[i] = (rand() + 97) % 122 ;
		cout << a[i];
	}
	cout << endl << "ÇëÊäÈëÉÏÊöÎÄ×Ö£º" << endl;
	for (int i = 0;i < 30;i++)
		scanf("%c",&b[i]);
	int flag = 0 ,wrong = 0 ,num ;
	for (int i = 0;i < 30;i++)
	{
		if (a[i] == b[i])
			wrong ++;
	}
	cout << wrong << endl;
	return 0;
}