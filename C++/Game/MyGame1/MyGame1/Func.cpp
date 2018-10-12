#include "stdafx.h"
#include "MyPlayer.h"
#include "Arr.h"
#include "Func.h"

void gotoxy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
void gotoxy(COORD pos) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD getxy() {
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos;
	while (1) {
		ReadConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &res);
		if (inRec.EventType == MOUSE_EVENT)	{
			pos = inRec.Event.MouseEvent.dwMousePosition;
			if (inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				break;
		}
	}
	return pos;
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void ShowCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void DeleteLine(short row) {
	SMALL_RECT rcScroll, rcClip;
	COORD crDest = { 0, row - 1 };
	CHAR_INFO chFill;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	rcScroll.Left = 0;
	rcScroll.Top = row;
	rcScroll.Right = bInfo.dwSize.X - 1;
	rcScroll.Bottom = bInfo.dwSize.Y - 1;
	rcClip = rcScroll;
	chFill.Attributes = bInfo.wAttributes;
	chFill.Char.UnicodeChar = 0;
	ScrollConsoleScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), &rcScroll, &rcClip, crDest, &chFill);
}
void ClearLine(short row) {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD d;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD home = { 0, row };
	unsigned long size = bInfo.dwSize.X;
	FillConsoleOutputCharacterW(GetStdHandle(STD_OUTPUT_HANDLE), 0, size, home, &d);
}
void ClearScreen() {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD d;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD home = { 0, 0 };
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputCharacterW(GetStdHandle(STD_OUTPUT_HANDLE),0, size, home, &d);
}

char* AgeToWord(long long age) {
	int Year = (int)(age / 129600);
	int Month = (int)(age % 129600);
	int AgesLen = 0;
	int temp = Year;
	while (temp != 0) {
		temp /= 10;
		AgesLen++;
	}
	temp = Month;
	while (temp != 0) {
		temp /= 10;
		AgesLen++;
	}
	if (Year != 0)
		AgesLen += 4;
	if (Month != 0)
		AgesLen += 2;
	AgesLen += 1;
	char *ages = new char(AgesLen);
	if (Year != 0)
		sprintf_s(ages, AgesLen, "%d元会%d年", Year, Month);
	else
		sprintf_s(ages, AgesLen, "%d年", Month);
	ages[AgesLen - 1] = 0;
	return ages;
}
void DrawBorder() {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	char wall[] = "~";
	for (int i = 3; i < 30; i++) {
		gotoxy((bInfo.dwSize.X - MENU_WIDTH) / 2 - 6, i);
		printf("%c", wall[0]);
		gotoxy((bInfo.dwSize.X + MENU_WIDTH) / 2 + 4, i);
		printf("%c", wall[0]);
	}
	for (int i = (bInfo.dwSize.X - MENU_WIDTH) / 2 - 6; i < (bInfo.dwSize.X + MENU_WIDTH) / 2 + 6; i += 2) {
		gotoxy(i, 3);
		printf("%c", wall[0]);
		gotoxy(i, 29);
		printf("%c", wall[0]);
	}
}
void PrintWordCenter(short y, string str) {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	gotoxy((short)(bInfo.dwSize.X - str.length()) / 2, y);
	printf_s("%s", str.c_str());
}
void TablePrint(short y, int n, int m, string *strArr) {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	int k = bInfo.dwSize.X;
	m = m % 2 == 0 ? m : m + 1;
	m = (k - m) / 2;
	k = (2 * k - 2 * m) / 2;
	string str;
	for (int j = y + 1; j < y + 2 * n + 2; j++) {
		if ((j - y) % 2 != 0) {
			for (int i = m; i <= k; i += 2) {
				gotoxy(i, j);
				printf_s("%c%c", Table[0][2], Table[0][3]);
			}
			gotoxy(m - 2, j);
			printf_s("%c%c", Table[2][0], Table[2][1]);
			gotoxy(k + 2, j);
			printf_s("%c%c", Table[2][8], Table[2][9]);
		}
		else {
			gotoxy(m - 2, j);
			printf_s("%c%c", Table[1][0], Table[1][1]);
			gotoxy(k + 1, j);//暂时不知道为什么
			printf_s("%c%c", Table[1][8], Table[1][9]);
		}
		if (j == y + 1) {
			gotoxy(m - 2, j);
			printf_s("%c%c", Table[0][0], Table[0][1]);
			gotoxy(k + 2, j);
			printf_s("%c%c", Table[0][8], Table[0][9]);
		}
		else if (j == y + 2 * n + 1) {
			gotoxy(m - 2, j);
			printf_s("%c%c", Table[4][0], Table[4][1]);
			gotoxy(k + 2, j);
			printf_s("%c%c", Table[4][8], Table[4][9]);
		}
	}
	for (int i = y + 2, j = 1; j <= n; j++, i += 2) {
		str = strArr[j - 1];
		PrintWordCenter(i, str);
	}
}
