#pragma once
//------------------控制台函数------------------------
void gotoxy(short x, short y);//光标移动
void gotoxy(COORD pos);//光标移动
COORD getxy();//鼠标左键单击时的位置
void HideCursor();
void ShowCursor();
void DeleteLine(short row);// 删除某行 (从0开始)
void ClearLine(short row);// 清空某行 (从0开始)
void ClearScreen(); // 清屏

//---------------------函数------------------------
char* AgeToWord(long long age);//将年龄(数字)转化为年龄(字符串)
void DrawBorder();
void PrintWordCenter(short y, string str);
void TablePrint(short y, int n, int m, string *strArr);