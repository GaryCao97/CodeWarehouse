#include <iostream>
using namespace std;
int main()
{
	char a,b,c,*o = &a,*p = &b,*q = &c;
	scanf("%c %c %c",&a,&b,&c);
	char temp;
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
	printf("%c %c %c\n",*o,*p,*q);
	return 0;
}