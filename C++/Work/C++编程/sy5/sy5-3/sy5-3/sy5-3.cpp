#include <iostream>
#include <cmath>
using namespace std;
double sh(double t)
{
	return ((exp(t) - exp(-t)) / 2.0);
}
double f(double x)
{
	return ( sh(1 + sh(x)) / (sh(2 * x) + sh(3 * x) ) );
}
int main()
{
	double x,y;
	cout << "�������Ա���x��";
	cin >> x;
	y = f(x);
	cout << "�����y =" << y << endl;
	return 0;
}