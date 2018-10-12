#include <iostream>
using namespace std;
int main()
{
	int i = 1, j = 2, k = 3;
	unsigned u = 47215;
	float x = 2.2, y = 3.4, z = -5.6;
	char c1 = 'a', c2 = 'b';
	printf("i = %d  j = %d  k = %d\n", i, j, k);
	printf("x = %6.5f,y = %6.5f,z = %6.5f\n", x, y, z);
	printf("x = %e,y = %f,z = %2.1f\n", x, y, z);
	printf("x + y = %3.2f  y + z = %3.2f  z + x = %3.2f\n", x+y, y+z, z+x);
	printf("u = %u\n", u);
	printf("c1 = '%c' or %d  c2 = '%c' or %d\n", c1, c1, c2, c2);
}
