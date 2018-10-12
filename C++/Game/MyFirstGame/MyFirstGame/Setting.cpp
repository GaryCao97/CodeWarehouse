#include "Setting.h"
#include "stdafx.h"

//-------变量
char Origin[4][20] = {
	"不知道的出身1",
	"不知道的出身2",
	"不知道的出身3",
	"不知道的出身4"
};

//-----函数-------

char* AgeToWord(long long age){
	int Year = (int)(age/129600);
	int Month = (int)(age%129600);
	int AgesLen = 0;
	int temp = Year;
	while(temp!=0){
		temp/=10;
		AgesLen++;
	}
	temp = Month;
	while(temp!=0){
		temp/=10;
		AgesLen++;
	}
	if (Year != 0) 
		AgesLen += 4;
	if (Month != 0) 
		AgesLen += 2;
	AgesLen+=1;
	char *ages = new char(AgesLen); 
	if (Year != 0)
		sprintf_s(ages, AgesLen, "%d元会%d年", Year, Month);
	else 
		sprintf_s(ages, AgesLen, "%d年", Month);
	ages[AgesLen - 1] = 0;
	return ages;
}
int Random(int min, int max) {
	srand((unsigned int)time(0));
	return (min + rand() % (max - min + 1));
}
void PrintWordCenter(short y, char *string) {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD pos = { (short)(bInfo.dwSize.X - strlen(string)) / 2 ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf_s("%s", string);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void ShowCursor()
{
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
	chFill.Char.UnicodeChar = ' ';
	ScrollConsoleScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), &rcScroll, &rcClip, crDest, &chFill);
}
void ClearLine(short row) {
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
	chFill.Char.UnicodeChar = ' ';
	ScrollConsoleScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), &rcScroll, &rcClip, crDest, &chFill);
	crDest = { 0, row };
	rcScroll.Left = 0;
	rcScroll.Top = row - 1;
	rcScroll.Right = bInfo.dwSize.X - 1;
	rcScroll.Bottom = bInfo.dwSize.Y - 2;
	rcClip = rcScroll;
	chFill.Attributes = bInfo.wAttributes;
	chFill.Char.UnicodeChar = ' ';
	ScrollConsoleScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), &rcScroll, &rcClip, crDest, &chFill);
}
void ClearScreen() {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD d;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD home = { 0, 0 };
	WORD att = bInfo.wAttributes;
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), att, size, home, &d);
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), 0, size, home, &d);
}