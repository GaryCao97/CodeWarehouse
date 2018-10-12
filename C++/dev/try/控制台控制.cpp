#include <windows.h>
#include <stdio.h>
#include <string.h>
HANDLE hOut;
HANDLE hIn;
void ClearScreen(void);
void DispMousePos(COORD pos); // 在第24行显示鼠标位置

int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE); // 获取标准输入设备句柄
	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
	// 背景是蓝色，文本颜色是黄色
	SetConsoleTextAttribute(hOut, att);
	ClearScreen(); // 清屏
	INPUT_RECORD mouseRec;
	DWORD state = 0, res;
	COORD pos = { 0, 0 };
	for (;;) // 循环
	{
		ReadConsoleInputW(hIn, &mouseRec, 1, &res);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				break; // 双击鼠标退出循环       
			pos = mouseRec.Event.MouseEvent.dwMousePosition;
			DispMousePos(pos);
			if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				FillConsoleOutputCharacter(hOut, 'A', 1, pos, NULL);
		}
	}
	pos.X = pos.Y = 0;
	SetConsoleCursorPosition(hOut, pos); // 设置光标位置
	CloseHandle(hOut); // 关闭标准输出设备句柄
	CloseHandle(hIn); // 关闭标准输入设备句柄
}

void DispMousePos(COORD pos) // 在第24行显示鼠标位置
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD home = { 0, 24 };
	WORD att0 = BACKGROUND_INTENSITY;
	FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, NULL);
	FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, NULL);
	char s[20];
	sprintf(s, "X = %2lu, Y = %2lu", pos.X, pos.Y);
	SetConsoleTextAttribute(hOut, att0);
	SetConsoleCursorPosition(hOut, home);
	WriteConsole(hOut, s, strlen(s), NULL, NULL);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性
	SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // 恢复原来的光标位置
}

void ClearScreen(void)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD p;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD home = { 0, 0 };
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputAttribute(hOut, bInfo.wAttributes, size, home, &p);
	FillConsoleOutputCharacter(hOut, ' ', size, home, &p);
}
