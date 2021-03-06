
#include "Main.h"
#include "Var.h"
#include "Func.h"


void curGotoXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
COORD getMouseXY(DWORD clickType) {
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos;
	while (1) {
		ReadConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &res);
		if (inRec.EventType == MOUSE_EVENT) {
			pos = inRec.Event.MouseEvent.dwMousePosition;
			if (inRec.Event.MouseEvent.dwButtonState == clickType)
				break;
		}
	}
	return pos;
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void ClearScreen() {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD d;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD home = { 0, 0 };
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputCharacterW(GetStdHandle(STD_OUTPUT_HANDLE), 0, size, home, &d);
}
void PrintInXY(short x, short y, char * str){
	//DWORD d;
	curGotoXY(x, y);
	printf_s("%s", str);
	//WriteConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPCWSTR)str, strlen(str), { x,y }, &d);
}

void ShowInfo(bool isBlack) {
	char *str;
	if (isBlack)str = "该黑棋下了";
	else str = "该白棋下了";
	PrintInXY(Left + 8, 2, str);
}
void ClearCB(){
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			ChessBoard[i][j] = 0;
}
void DrawCB() {
	char *str;
	for (short i = 0; i < 19; i++){
		for (short j = 0; j < 19; j++) {
			if (i == 0 && j == 0)
				str = "╔";
			else if (i == 0 && j == 18)
				str = "╚";
			else if (i == 18 && j == 0)
				str = "╗";
			else if (i == 18 && j == 18)
				str = "╝";
			else if (i == 0)
				str = "╠";
			else if (i == 18)
				str = "╣";
			else if (j == 0)
				str = "╦";
			else if (j == 18)
				str = "╩";
			else str = "╬";
			PrintInXY(i * 2 + Left, j + Top, str);
		}
	}
	//═║╔╗╚╝╠╣╦╩╬〇○●
}
void Game() {
	int Winner;
	bool isBlack = true;
	ShowInfo(isBlack);
	int x = 0, y = 0;
	do {
		if (isBlack) {
			COORD pos = getMouseXY(LEFT_CLICK);
			x = (pos.X - Left) / 2, y = pos.Y - Top;
			if (x > 18 || x < 0 || y > 18 || y < 0)
				continue;
			if (ChessBoard[x][y] == 0) {
				PrintInXY(x * 2 + Left, y + Top, BlackChess);
				ChessBoard[x][y] = BLACK;
				isBlack = !isBlack;
				ShowInfo(isBlack);
			}
		}
		else{
			COORD pos = getMouseXY(RIGHT_CLICK);
			x = (pos.X - Left) / 2, y = pos.Y - Top;
			if (x > 18 || x < 0 || y > 18 || y < 0)
				continue;
			if (ChessBoard[x][y] == 0) {
				PrintInXY(x * 2 + Left, y + Top, WhiteChess);
				ChessBoard[x][y] = WHITE;
				isBlack = !isBlack;
				ShowInfo(isBlack);
			}
		}
		Winner = CheckWin(x, y);
		if (Winner)break;
	}while (true);
	Message(Winner);
}
GameState CheckWin(int x , int y) {
	int tmp = ChessBoard[x][y];
	int num[4] = { 1,1,1,1 };
	int i, j, m, n;
	for (i = 0; i < 8; i++) {
		m = x; n = y; j = i % 4;
		m += Direct[i][0];
		n += Direct[i][1];
		while (ChessBoard[m][n] == tmp) {
			m += Direct[i][0];
			n += Direct[i][1];
			num[j]++;
		}
	}
	for (i = 0; i < 4; i++)
		if (num[i] >= 5)
			return tmp;
	return PLAYING;
}
void Message(int whoWin){
	char *WhoWin;
	int x = 8 * 2 + Left, y = 9 + Top;
	char *str;
	str = "╔═════════╗";
	PrintInXY(x - 7, y - 1, str);
	str = "║                  ║";
	PrintInXY(x - 7, y, str);
	str = "╚═════════╝";
	PrintInXY(x - 7, y + 1, str);
	if (whoWin == BLACKWIN) {
		WhoWin = "BlackWin";
		PrintInXY(x, y, WhoWin);
	}
	else {
		WhoWin = "WhiteWin";
		PrintInXY(x, y, WhoWin);
	}
	//═║╔╗╚╝╠╣╦╩╬〇○●
}
