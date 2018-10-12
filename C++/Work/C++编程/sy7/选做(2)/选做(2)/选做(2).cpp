#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int password()
{
	int c;
	do
	{
		c = rand() % 123;
	}while(c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122);
	return c;
}
void PassWord()
{
	srand(time(0));
	int bits,n = 0;
	cout << "请确认密码位数：" ;
	cin >> bits;
	char pw[100];
	for(int m = 0;m < 100;pw[m++] = '\0');
	while(n < bits)
		pw[n++] = password();
	cout << "密码为：" ;
	cout << pw << endl;
}
int main()
{
	char ch;
	do
	{
		PassWord();
		cout << "是否继续(Enter 'Y' or 'y' to continue!)：";
		cin >> ch;
	}while(ch == 'Y' || ch == 'y');
}