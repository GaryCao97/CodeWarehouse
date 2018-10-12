#include <iostream>
using namespace std;
int main()
{
	short a, b; unsigned c, d; long e, f;
	a = 100; b = -100; e = 50000; f = 32767;
	c = a; d = b;
	printf("%d, %d\n", a, b);
	printf("%u, %u\n", c, d);
	c = a = e; d = b = f;
	printf("%d, %d\n", a, b);
	printf("%u, %u\n", c, d);
}
