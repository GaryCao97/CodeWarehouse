#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[20],b[20],c[20],*o = a,*p = b,*q = c;
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	char temp[20];
	if (strcmp(a,b) < 0)
	{
		for(int i = 0;i <20;i++)
		{
			temp[i] = *(o+i);
			*(o+i) = *(p+i);
			*(p+i) = temp[i];
		}
	}
	if (strcmp(b,c) < 0)
	{
		for(int i = 0;i <20;i++)
		{
			temp[i] = *(p+i);
			*(p+i) = *(q+i);
			*(q+i) = temp[i];
		}
	}
	if (strcmp(a,b) < 0)
	{
		for(int i = 0;i <20;i++)
		{
			temp[i] = *(o+i);
			*(o+i) = *(p+i);
			*(p+i) = temp[i];
		}
	}
	printf("%s\n",a);
	printf("%s\n",b);
	printf("%s\n",c);
	return 0;
}