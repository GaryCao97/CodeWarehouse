#include <iostream>
using namespace std;
int main()
{
	char a[20], *p = a;
	int i, j = 0;

	cin >> a;
	for (i = 0; i < 20; i += 2)
	{
		if (*(p + i) != '\0')
			cout << *(p + i);
		else break;
	}

	cout << endl;
	for (i = 0; i < 20; i++)
		if (*(p + i) != '\0')
			j++;

	for (i = j - 1; i > -1; i--)
		cout << *(p + i);
	cout << endl;
}