#include <windows.h>
#include <stdio.h>
#include <conio.h>

HANDLE hOut;

HANDLE hIn;

void DrawBox(bool bSingle, SMALL_RECT rc); // ����Զ��庯���ڵ������ù�

void ClearScreen(void);

void CharWindow(char ch, SMALL_RECT rc); // ��ch���뵽ָ���Ĵ�����

void ControlStatus(DWORD state); // �����һ����ʾ���Ƽ���״̬

void DeleteTopLine(SMALL_RECT rc); // ɾ��ָ����������������в�����

int main(void)

{

       hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���

       hIn = GetStdHandle(STD_INPUT_HANDLE); // ��ȡ��׼�����豸���

       WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE ; // ��������ɫ���ı���ɫ�ǻ�ɫ

       SetConsoleTextAttribute(hOut, att);

       ClearScreen(); // ����

       INPUT_RECORD keyRec;

       DWORD state = 0, res;

       char ch;

       SMALL_RECT rc = {20, 2, 40, 12};

       DrawBox(false, rc);

       COORD pos = {rc.Left+1, rc.Top+1};

       SetConsoleCursorPosition(hOut, pos); // ���ù��λ��

       for(;;) // ѭ��

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

                     // ��ESC���˳�ѭ��

                     if (keyRec.Event.KeyEvent.bKeyDown)

                     {

                            ch = keyRec.Event.KeyEvent.uChar.AsciiChar;

                            CharWindow(ch, rc);

                     }

              }

       }

       pos.X = 0; pos.Y = 0;

       SetConsoleCursorPosition(hOut, pos); // ���ù��λ��

       CloseHandle(hOut); // �رձ�׼����豸���

       CloseHandle(hIn); // �رձ�׼�����豸���

       return 0;

}

 

void CharWindow(char ch, SMALL_RECT rc) // ��ch���뵽ָ���Ĵ�����

{

       static COORD chPos = {rc.Left+1, rc.Top+1};

       SetConsoleCursorPosition(hOut, chPos); // ���ù��λ��

       if ((ch<0x20)||(ch>0x7e)) // ����ǲ��ɴ�ӡ���ַ�������鿴ASCII���

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

       SetConsoleCursorPosition(hOut, chPos); // ���ù��λ��

}

 

void ControlStatus(DWORD state) // �ڵ�һ����ʾ���Ƽ���״̬

{

       CONSOLE_SCREEN_BUFFER_INFO bInfo;

       GetConsoleScreenBufferInfo( hOut, &bInfo );

       COORD home = {0, 24}; // ԭ���˴�ΪbInfo.dwSize.Y-1����Ϊ�˸����ڹ۲죬�Ұ�������΢�޸���һ��

       WORD att0 = BACKGROUND_INTENSITY ;

       WORD att1 = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;

       FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, NULL);

       FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, NULL);

       SetConsoleTextAttribute(hOut, att1);

       COORD staPos = {bInfo.dwSize.X-16,24}; // ԭ���˴�ΪbInfo.dwSize.Y-1

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

       SetConsoleTextAttribute(hOut, bInfo.wAttributes); // �ָ�ԭ��������

       SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // �ָ�ԭ���Ĺ��λ��

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

// �������ܣ����߿�

void DrawBox(bool bSingle, SMALL_RECT rc)

{

       char chBox[6];

       COORD pos;

       if (bSingle)

       {

              chBox[0] = (char)0xda; // ���Ͻǵ�

              chBox[1] = (char)0xbf; // ���Ͻǵ�

              chBox[2] = (char)0xc0; // ���½ǵ�

              chBox[3] = (char)0xd9; // ���½ǵ�

              chBox[4] = (char)0xc4; // ˮƽ

              chBox[5] = (char)0xb3; // ��ֱ

       }

       else

       {

              chBox[0] = (char)0xc9; // ���Ͻǵ�

              chBox[1] = (char)0xbb; // ���Ͻǵ�

              chBox[2] = (char)0xc8; // ���½ǵ�

              chBox[3] = (char)0xbc; // ���½ǵ�

              chBox[4] = (char)0xcd; // ˮƽ

              chBox[5] = (char)0xba; // ��ֱ

       }

       // ���߿���� �±߽�

       for(pos.X = rc.Left+1;pos.X<rc.Right-1;pos.X++)

       {    

              pos.Y = rc.Top;

              // ���ϱ߽�

              WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

              // �����Ͻ�

              if(pos.X == rc.Left+1)

              {

                     pos.X--;

                     WriteConsoleOutputCharacter(hOut, &chBox[0],1, pos, NULL);

                     pos.X++;

              }

              // �����Ͻ�

              if(pos.X == rc.Right-2)

              {

                     pos.X++;

                     WriteConsoleOutputCharacter(hOut, &chBox[1], 1, pos, NULL);

                     pos.X--;

              }

              pos.Y = rc.Bottom;

              // ���±߽�

              WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

              // �����½�

              if(pos.X == rc.Left+1)

              {

                     pos.X--;

                     WriteConsoleOutputCharacter(hOut, &chBox[2], 1, pos, NULL);

                     pos.X++;

              }

              // �����½�

              if(pos.X==rc.Right-2)

              {

                     pos.X++;

                     WriteConsoleOutputCharacter(hOut, &chBox[3], 1, pos, NULL);

                     pos.X--;

              }

 

       }

       // ���߿�����ұ߽�

       for (pos.Y = rc.Top+1; pos.Y<=rc.Bottom-1; pos.Y++)

       {

              pos.X = rc.Left;

              // ����߽�

              WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);

              pos.X = rc.Right-1;

              // ���ұ߽�

              WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);

       }

}
