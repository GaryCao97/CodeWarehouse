#include <iostream>
using namespace std;
void main()
{
	char Str[100], *str;
	cin >> Str;
	str = Str;
	for(;*str != '\0';str+=2)
	{
		printf("%c",*str);
	}
	printf("\n");
	str--;
	for(;str != Str -1;str--)
		printf("%c",*str);
	printf("\n");
}