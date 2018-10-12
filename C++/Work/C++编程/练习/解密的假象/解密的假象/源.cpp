#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <Windows.h>
using namespace std;
void pojie(char *p,int x,char *q,int y = 0)
{
	if(x == 0)
	{
		system("cls");
		cout << q;
	}
	else
	{
		int i = '0'-1;
		while(q[y] != p[y])
		{
			q[y] = i++;
			cout << q;
			Sleep(5);
			system("cls");
		}
		pojie(p,x-1,q,y+1);
	}
}
int main()
{
	srand(time_t(0));
	cout << "ÇëÊäÈëÃÜÂë";
	char str[1000];
	int i;
	for(i = 0;str[i-1] != '\r';i++)
		str[i] = getch();
	str[i-1] = '\0';
	int n = strlen(str);
	system("cls");
	char o[1000] = "";
	pojie(str,n,o);
	cout << endl;
	return 0;
}
