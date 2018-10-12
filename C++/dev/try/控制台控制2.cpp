#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define getrandom( min, max ) ((rand() % (int)(((max)+1) - (min))) + (min))
void Init(void);
void gotoxy(int x, int y);
void regularcolor(void);
void randomcolor(void);
void Cls(HANDLE hConsole);
HANDLE hOut;
int forecolor[16];
int backcolor[16];
int main(void)
{
       int i;
       int a;
       for (i = 0; i < 16; i++)
       {
              forecolor[i] = i;
              backcolor[i] = i << 4;
       }
       hOut = GetStdHandle(STD_OUTPUT_HANDLE);
       Init();
       while(1)
       {
              a = getch();
              if (a == 48)
              {
                     Cls(hOut);
                     regularcolor();
                     getch();
              } else if (a == 49) {
                     Cls(hOut);
                     randomcolor();
                     getch();
              }  else {
                     Cls(hOut);
                     break;
              }
              Cls(hOut);
              Init();
       }
       CloseHandle(hOut);
       return 0;
}
//---------------------------------------------------------------------------

void gotoxy(int x, int y)
{
       COORD pos = {x, y};
       SetConsoleCursorPosition(hOut, pos);
}

void regularcolor(void)
{
       int i, j, x, y;
       int l = 8, t = 5;
       for (y = 0; y < 16; y++)
       {
              gotoxy(l - 3, y + t);
              SetConsoleTextAttribute(hOut, forecolor[15]|backcolor[0]);
              printf("%d", y);
              for (x = 0; x < 16; x++)
              {
                     gotoxy(x * 4 + l, y + t);
                     SetConsoleTextAttribute(hOut, forecolor[y]|backcolor[x]);
                     printf("ZZZ");
                     if (y == 15)
                     {
                            gotoxy(x * 4 + l, 17 + t);
                            SetConsoleTextAttribute(hOut, forecolor[15]|backcolor[0]);
                            printf("%d", x);
                     }
              }
       }
}

void randomcolor(void)
{
       int i, j, x, y;
       int l = 8, t = 5;
       char s[4] = {"012"};
       rand();
       for (y = 0; y < 16; y++)
       {
              for (x = 0; x < 16; x++)
              {
                     s[0] = getrandom(32, 127);
                     s[1] = getrandom(32, 127);
                     s[2] = getrandom(32, 127);
                     gotoxy(x * 4 + l, y + t);
                     SetConsoleTextAttribute(hOut, forecolor[getrandom(0, 15)]|backcolor[getrandom(0, 15)]);
                     printf("%c", s[0]);
                     gotoxy(x * 4 + l + 1, y + t);
                     SetConsoleTextAttribute(hOut, forecolor[getrandom(0, 15)]|backcolor[getrandom(0, 15)]);
                     printf("%c", s[1]);
                     gotoxy(x * 4 + l + 2, y + t);
                     SetConsoleTextAttribute(hOut, forecolor[getrandom(0, 15)]|backcolor[getrandom(0, 15)]);
                     printf("%c", s[2]);
              }
       }
}

void Cls(HANDLE hConsole)
{
       COORD coordScreen = {0, 0};
       BOOL   bSuccess;
       DWORD  cCharsWritten;
       CONSOLE_SCREEN_BUFFER_INFO csbi;
       DWORD  dwConSize;
       SetConsoleTextAttribute(hOut, 0x0f|0);
       bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
       dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
       bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) '   ', dwConSize, coordScreen, &cCharsWritten);
       bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
       bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
       bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
}
void Init(void)
{
       gotoxy(30, 10);
       printf("0. Regular Color Array");
       gotoxy(30, 11);
       printf("1. Random Color Array");
       gotoxy(30, 12);
       printf("2. Quit");
}
