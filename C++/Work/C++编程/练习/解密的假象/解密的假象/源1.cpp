#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
int main()
{
	char a[100];
	for(int i = 0;a[i-1] != '\r';i++)
		a[i] = getch();
	puts(a);
	return 0;
}