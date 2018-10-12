#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;
void main()
{
	float x, x0, f, f1;
	x0 = 1.5;
	f = ((2 * x0 - 4)*x0 + 3)*x0 - 6;
	f1 = (6 * x0 - 8)*x0 + 3;
	x = x0 - f / f1;
	while (fabs(x - x0) >= 0.00001)
	{
		x0 = x;
		f = ((2 * x0 - 4)*x0 + 3)*x0 - 6;
		f1 = (6 * x0 - 8)*x0 + 3;
		x = x0 - f / f1;
	}
	printf("%10.8f \n", x);
}