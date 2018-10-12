#pragma once

//------------------控制台函数------------------------
void curGotoXY(short x, short y);//光标移动
COORD getMouseXY(DWORD clickType);//鼠标单击时的位置 clickType = LEFT_CLICK时为鼠标左键
void HideCursor();
void ClearScreen(); // 清屏
void PrintInXY(short x, short y, char *str);
//-----------------------函数-----------------------
void ShowInfo(bool isBlack);
void ClearCB();
void DrawCB();
void Game();
GameState CheckWin(int x, int y);
void Message(int whoWin);