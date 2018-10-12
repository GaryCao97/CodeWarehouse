#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	COORD coord;
	coord.X = 1;
	coord.Y = 0;
	int  second = 0;
	SYSTEMTIME st;

	while (1)
	{
		GetLocalTime(&st);

		if (abs(st.wSecond - second) >= 1)
		{
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hStdout, coord); //光标位置设置为1 ， 0
			SetConsoleTextAttribute(hStdout, 9 | 1);
			printf("%2d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
			second = st.wSecond;
			_CONSOLE_CURSOR_INFO  cInfo;
			GetConsoleCursorInfo(hStdout, &cInfo);
			cInfo.bVisible = false;
			SetConsoleCursorInfo(hStdout, &cInfo);  //光标不可见
		}
	}
	return 0;
}