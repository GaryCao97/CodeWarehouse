#include<stdio.h>
#include<windows.h>
#define wait(x) Sleep(x*1000)
int main()
{
	HANDLE hOut;
	COORD pos = { 0, 0 };
	int i;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);
	//SetConsoleTextAttribute(hOut, 3 | 1);
	for (i = 0; i<20; i++)
	{
		SetConsoleTextAttribute(hOut, 10 * i);
		pos.X = 1;
		pos.Y = 1;
		SetConsoleCursorPosition(hOut, pos);

		printf("%d%d:HelloWorld!\n", pos.X, pos.Y);
		Sleep(1000);
	}
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	printf("%d", bInfo.dwCursorPosition.X);
	printf("%d", bInfo.dwCursorPosition.Y);
	Sleep(1000);
	return 0;
}