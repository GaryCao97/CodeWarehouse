#include<iostream>
#include <ctime>
using namespace std;
void main()
{
	unsigned t[3], ti;
	ti = time(0);
	t[2] = ti % 60;
	ti /= 60;
	t[1] = ti % 60;
	ti /= 60;
	t[0] = ti % 24;
	printf("%d:%d:%d", t[0], t[1], t[2]);

}