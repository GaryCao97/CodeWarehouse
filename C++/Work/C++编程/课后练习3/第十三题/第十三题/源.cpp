#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
char Change[10][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
void main()
{
	cout << "Please input some equation :" << endl;
	char ch,equa[50];
	ch = getch();
	while(ch != '\n')
		strcat(equa,&ch);
	strcat(equa,'\0');
	cout << equa;
}