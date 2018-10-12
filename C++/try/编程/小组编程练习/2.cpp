#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int Que(int No)
{
	int a, b, ans, p_ans, sign, times = 3;
	char r_sign;
	do
	{
		a = rand() % 51;
		b = rand() % 51;
		sign = rand() % 2;
		switch (sign)
		{
		case 0 :
			r_sign = '-';
			ans = a - b;
			break;
		case 1 :
			r_sign = '+';
			ans = a + b;
			break;
		}
	} while (ans > 50 || ans < 0);
	for (; times > 0;times--)
	{
		system("cls");
		cout << "This is the No." << No << " question !";
		cout << "You only have " << times << " choice to answer!" << endl;
		cout << a << r_sign << b << '=';
		cin >> p_ans;
		if (p_ans == ans)
			break;
	}
	if (p_ans != ans)
	{
		cout << "The right answer is : " << ans << endl;
		system("pause");
	}
	switch (times)
	{
	case 3:return 10;
	case 2:return 7;
	case 1:return 5;
	case 0:return 0;
	}
}
void main()
{
	srand((unsigned)time(0));
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int every = Que(i+1);
		sum += every;
	}
	switch (sum/10)
	{
	case 10:
	case 9:
		cout << "Smart!";
		break;
	case 8:
		cout << "Good!";
		break;
	case 7:
		cout << "OK!";
		break;
	case 6:
		cout << "Pass!";
		break;
	default:
		cout << "Try Again!";
		break;
	}
}