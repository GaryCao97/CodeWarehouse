#pragma once

//------------------����̨����------------------------
void curGotoXY(short x, short y);//����ƶ�
COORD getMouseXY(DWORD clickType);//��굥��ʱ��λ�� clickType = LEFT_CLICKʱΪ������
void HideCursor();
void ClearScreen(); // ����
void PrintInXY(short x, short y, char *str);
//-----------------------����-----------------------
void ShowInfo(bool isBlack);
void ClearCB();
void DrawCB();
void Game();
GameState CheckWin(int x, int y);
void Message(int whoWin);