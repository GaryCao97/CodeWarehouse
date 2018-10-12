#include <iostream>
using namespace std;
int main()
{
	int a = 1, b = 2;
	int  x, y, z;
	cout << (a++)+(++b) << endl;
	cout << a % b << endl;
	x = !a>b;
	y = a-- && b; 
	z = (x+y, a++ , b++) ;
	cout << a << endl << b << endl;
	cout << x << endl << y << endl << z << endl;
}
