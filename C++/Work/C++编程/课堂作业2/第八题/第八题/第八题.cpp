#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int num1,num2;
loop1:
	cout << "Enter first multipliter: ";
	cin >> num1;
	if (!(num1 >= 10 && num1 <= 99)) 
	{
		cout<< "Error!!Please input again!" << endl;
		goto loop1;
	}
loop2:
	cout << "Enter second multipliter: ";
	cin >> num2;
	if (!(num2 >= 10 && num2 <= 99)) 
	{
		cout<< "Error!!Please input again!" << endl;
		goto loop2;
	}
	cout <<  endl;
	cout << setw(3) << " " << num1 << endl;
	cout << setw(3) << "*" << num2 << endl;
	cout << "------" << endl;
	cout << setiosflags(ios::right) << setw(5) << ((num2%10)*num1) << endl;
	cout << setw(4) << ((num2/10)*num1) << endl;
	cout << "------" << endl;
	cout << setw(5) << num1 * num2 << endl;
	return 0;
}