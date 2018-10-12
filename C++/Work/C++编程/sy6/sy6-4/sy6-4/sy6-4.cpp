#include <iostream>
using namespace std;
int main()
{
	int a,b,c,*o = &a,*p = &b,*q = &c;
	scanf("%d %d %d",&a,&b,&c);
	int temp;
	if (*o < *p)
	{
		temp = *o;
		*o = *p;
		*p = temp;
	}
	if (*p < *q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
	if (*o < *p)
	{
		temp = *o;
		*o = *p;
		*p = temp;
	}
	printf("%d %d %d\n",*o,*p,*q);
	return 0;
}