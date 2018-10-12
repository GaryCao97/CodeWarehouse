#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
const int N = 20;
int CreateSentence(char ch[N])
{
	srand((unsigned)time(0));
	char perCh;
	int perNum;
	int i;
	for (i = 0; i < N; i++)
	{
		perNum = rand() % 2;
		if ((i + 1) % 3 == 0 && perNum == 0)
		{
			ch[i] = ' ';
			continue;
		}
		else
		{
			perCh = rand() % 26 + 'a';
			ch[i] = perCh;
		}
	}
	if (i == N)
		return 1;
	else return 0;
}
void Output_1(char ch[N])
{
	for (int o = 0; o < N; o++)
	{
		printf("%c", ch[o]);
	}
	printf("\n");
}
void Input(char ch[N])
{
	for (int o = 0; o < N; o++)
	{
		char perCh = _getch();
		if (perCh == 8)
		{
			o -= 2;
			printf("\b");
			printf(" ");
			printf("\b");
			continue;
		}
		printf("%c", perCh);
		ch[o] = perCh;
	}
}
int Compare(char ch1[N], char ch2[N])
{
	system("cls");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord1,coord2;
	coord1.X = 0;
	coord1.Y = 3;
	coord2.X = 0;
	coord2.Y = 6;
	int book = 1;
	for (int o = 0; o < N; o++)
	{
		Sleep(500);
		coord1.X = coord2.X = o;
		if (ch1[o] == ch2[o])
			SetConsoleTextAttribute(hStdout, 9 | 1);
		else
		{
			SetConsoleTextAttribute(hStdout, 15 | 1);
			book = 0;
		}
		SetConsoleCursorPosition(hStdout, coord1);
		printf("%c", ch1[o]);
		SetConsoleCursorPosition(hStdout, coord2);
		printf("%c", ch2[o]);
	}
	return book;
}
int main()
{
	char TrueCh[N], InputCh[N];
	CreateSentence(TrueCh);
	Output_1(TrueCh);
	Input(InputCh);
	Compare(TrueCh, InputCh);
}