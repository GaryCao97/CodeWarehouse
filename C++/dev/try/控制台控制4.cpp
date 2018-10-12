#include <windows.h>
#include <stdio.h>
#include <conio.h>

HANDLE hOut;

HANDLE hIn;

void DrawBox(bool bSingle, SMALL_RECT rc); // 这个自定义函数在第六章用过

void ClearScreen(void);

void CharWindow(char ch, SMALL_RECT rc); // 将ch输入到指定的窗口中

void ControlStatus(DWORD state); // 在最后一行显示控制键的状态

void DeleteTopLine(SMALL_RECT rc); // 删除指定窗口中最上面的行并滚动

int main(void)

{

       hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄

       hIn = GetStdHandle(STD_INPUT_HANDLE); // 获取标准输入设备句柄

       WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE ; // 背景是蓝色，文本颜色是黄色

       SetConsoleTextAttribute(hOut, att);

       ClearScreen(); // 清屏

       INPUT_RECORD keyRec;

       DWORD state = 0, res;

       char ch;

       SMALL_RECT rc = {20, 2, 40, 12};

       DrawBox(false, rc);

       COORD pos = {rc.Left+1, rc.Top+1};

       SetConsoleCursorPosition(hOut, pos); // 设置光标位置

       for(;;) // 循环

       {

              ReadConsoleInput(hIn, &keyRec, 1, &res);

              if (state != keyRec.Event.KeyEvent.dwControlKeyState)

              {

                     state = keyRec.Event.KeyEvent.dwControlKeyState;

                     ControlStatus(state);

              }

              if (keyRec.EventType == KEY_EVENT)

              {

                     if (keyRec.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)

                            break;

                     // 按ESC键退出循环

                     if (keyRec.Event.KeyEvent.bKeyDown)

                     {

                            ch = keyRec.Event.KeyEvent.uChar.AsciiChar;

                            CharWindow(ch, rc);

                     }

              }

       }

       pos.X = 0; pos.Y = 0;

       SetConsoleCursorPosition(hOut, pos); // 设置光标位置

       CloseHandle(hOut); // 关闭标准输出设备句柄

       CloseHandle(hIn); // 关闭标准输入设备句柄

       return 0;

}

 

void CharWindow(char ch, SMALL_RECT rc) // 将ch输入到指定的窗口中

{

       static COORD chPos = {rc.Left+1, rc.Top+1};

       SetConsoleCursorPosition(hOut, chPos); // 设置光标位置

       if ((ch<0x20)||(ch>0x7e)) // 如果是不可打印的字符，具体查看ASCII码表

              return;

       WriteConsoleOutputCharacter(hOut, &ch, 1, chPos, NULL);

       if (chPos.X >= (rc.Right-2))

       {

              chPos.X = rc.Left;

              chPos.Y++;

       }

       if (chPos.Y>(rc.Bottom-1))

       {

              DeleteTopLine(rc);

              chPos.Y = rc.Bottom-1;

       }

       chPos.X++;

       SetConsoleCursorPosition(hOut, chPos); // 设置光标位置

}

 

void ControlStatus(DWORD state) // 在第一行显示控制键的状态

{

       CONSOLE_SCREEN_BUFFER_INFO bInfo;

       GetConsoleScreenBufferInfo( hOut, &bInfo );

       COORD home = {0, 24}; // 原来此处为bInfo.dwSize.Y-1，但为了更便于观察，我把这里稍微修改了一下

       WORD att0 = BACKGROUND_INTENSITY ;

       WORD att1 = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;

       FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, NULL);

       FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, NULL);

       SetConsoleTextAttribute(hOut, att1);

       COORD staPos = {bInfo.dwSize.X-16,24}; // 原来此处为bInfo.dwSize.Y-1

       SetConsoleCursorPosition(hOut, staPos);

       if (state & NUMLOCK_ON)

              WriteConsole(hOut, "NUM", 3, NULL, NULL);

       staPos.X += 4;

       SetConsoleCursorPosition(hOut, staPos);

       if (state & CAPSLOCK_ON)

              WriteConsole(hOut, "CAPS", 4, NULL, NULL);

       staPos.X += 5;

       SetConsoleCursorPosition(hOut, staPos);

       if (state & SCROLLLOCK_ON)

              WriteConsole(hOut, "SCROLL", 6, NULL, NULL);

       SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性

       SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // 恢复原来的光标位置

}

void DeleteTopLine(SMALL_RECT rc)

{

       COORD crDest;

       CHAR_INFO chFill;

       SMALL_RECT rcClip = rc;

       rcClip.Left++;

       rcClip.Right -= 2;

       rcClip.Top++;

       rcClip.Bottom--;

       crDest.X = rcClip.Left;

       crDest.Y = rcClip.Top - 1;

       CONSOLE_SCREEN_BUFFER_INFO bInfo;

       GetConsoleScreenBufferInfo( hOut, &bInfo );

       chFill.Attributes = bInfo.wAttributes;

       chFill.Char.AsciiChar = ' ';

       ScrollConsoleScreenBuffer(hOut, &rcClip, &rcClip, crDest, &chFill);

}

void ClearScreen(void)

{

       CONSOLE_SCREEN_BUFFER_INFO bInfo;

       GetConsoleScreenBufferInfo( hOut, &bInfo );

       COORD home = {0, 0};

       WORD att = bInfo.wAttributes;

       unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;

       FillConsoleOutputAttribute(hOut, att, size, home, NULL);

       FillConsoleOutputCharacter(hOut, ' ', size, home, NULL);

}

// 函数功能：画边框

void DrawBox(bool bSingle, SMALL_RECT rc)

{

       char chBox[6];

       COORD pos;

       if (bSingle)

       {

              chBox[0] = (char)0xda; // 左上角点

              chBox[1] = (char)0xbf; // 右上角点

              chBox[2] = (char)0xc0; // 左下角点

              chBox[3] = (char)0xd9; // 右下角点

              chBox[4] = (char)0xc4; // 水平

              chBox[5] = (char)0xb3; // 坚直

       }

       else

       {

              chBox[0] = (char)0xc9; // 左上角点

              chBox[1] = (char)0xbb; // 右上角点

              chBox[2] = (char)0xc8; // 左下角点

              chBox[3] = (char)0xbc; // 右下角点

              chBox[4] = (char)0xcd; // 水平

              chBox[5] = (char)0xba; // 坚直

       }

       // 画边框的上 下边界

       for(pos.X = rc.Left+1;pos.X<rc.Right-1;pos.X++)

       {    

              pos.Y = rc.Top;

              // 画上边界

              WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

              // 画左上角

              if(pos.X == rc.Left+1)

              {

                     pos.X--;

                     WriteConsoleOutputCharacter(hOut, &chBox[0],1, pos, NULL);

                     pos.X++;

              }

              // 画右上角

              if(pos.X == rc.Right-2)

              {

                     pos.X++;

                     WriteConsoleOutputCharacter(hOut, &chBox[1], 1, pos, NULL);

                     pos.X--;

              }

              pos.Y = rc.Bottom;

              // 画下边界

              WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

              // 画左下角

              if(pos.X == rc.Left+1)

              {

                     pos.X--;

                     WriteConsoleOutputCharacter(hOut, &chBox[2], 1, pos, NULL);

                     pos.X++;

              }

              // 画右下角

              if(pos.X==rc.Right-2)

              {

                     pos.X++;

                     WriteConsoleOutputCharacter(hOut, &chBox[3], 1, pos, NULL);

                     pos.X--;

              }

 

       }

       // 画边框的左右边界

       for (pos.Y = rc.Top+1; pos.Y<=rc.Bottom-1; pos.Y++)

       {

              pos.X = rc.Left;

              // 画左边界

              WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);

              pos.X = rc.Right-1;

              // 画右边界

              WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);

       }

}
