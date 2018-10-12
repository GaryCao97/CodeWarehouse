#include <iostream>
#include <iomanip>
using namespace std;
void Line()
{
	cout << "***************************************************" << endl;
}
int main()
{
	cout << "Enter number of days in month: ";
	int day;
	cin >> day;
	cout << "Enter starting day of the week(1 = Sum,7 = Sat): ";
	int week;
	cin >> week;
	Line();
	cout << "     Sun Mon Tue Wen Thu Fri Sat " << endl;
	cout << setw(4 * week + 4) << setiosflags(ios::right);
	for (int i = 1;i <= day;i++)
	{
		cout << i << setw(4);
		if ((i - 1 + week) % 7 == 0) cout << endl << setw(8);
	}
	cout << endl;
	Line();
	return 0;
}