#include "Menu.h"
#include "Setting.h"
#include "stdafx.h"


void Start() {
	ClearScreen();
	short w = 100, h = 40;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { w, h }); // 重新设置缓冲区大小
	SMALL_RECT rc = { 0,0, w - 1, h - 1 }; // 重置窗口位置和大小
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
	int y = 19;
	char *string;
	string = "倒计时3秒后开始游戏";
	PrintWordCenter(y, string);
	Sleep(1000);
	int t = 3;
	ClearScreen();
	while (t) {
		string = new char(2);
		sprintf_s(string, 2, "%d", t--);
		PrintWordCenter(y, string);
		Sleep(1000);
		ClearLine(y);
	}
}
int ChoiceOrigin() {
	int y;
	char *string;
	y = 10;
	string = "在一个不明所以的日子里，";
	PrintWordCenter(y, string);
	Sleep(1000);
	y += 2;
	string = "风雨交加，电闪雷鸣，";
	PrintWordCenter(y, string);
	Sleep(1000);
	y += 2;
	string = "你，出生在              ";
	PrintWordCenter(y, string);
	Sleep(1000);
	for (int i = y + 2, j = 1; j <= 4; j++, i += 2) {
		string = Origin[j - 1];
		PrintWordCenter(i, string);
		Sleep(1000);
	}
	INPUT_RECORD inRec;
	DWORD res;
	COORD crPos;
	int choice = 0;
	while (1)
	{
		ReadConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &res);
		if (inRec.EventType == MOUSE_EVENT)
		{
			crPos = inRec.Event.MouseEvent.dwMousePosition;
			choice = (crPos.Y - y) / 2;
			if (inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) 
				if (choice > 0 && choice < 5) 
					break;
		}
	}
	for (int i = y + 2, j = 1; j <= 4; j++, i += 2) {
		ClearLine(i);
	}
	return choice;
}