#ifndef GoBangConsoleui_H
#define GoBangConsoleui_H
#include "gobanginterface.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
HWND GetConsoleHwnd(void)           //��ȡ����̨��������ڻ�ͼ
{                                   //from MSDN
#define MY_BUFSIZE 1024 // ����Ļ����С
    HWND hwndFound;         // ���صľ��
    char pszNewWindowTitle[MY_BUFSIZE];
    char pszOldWindowTitle[MY_BUFSIZE];

    GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

    wsprintf(pszNewWindowTitle,"%d/%d",
        GetTickCount(),
        GetCurrentProcessId());

    SetConsoleTitle(pszNewWindowTitle);

    Sleep(40);

    hwndFound=FindWindow(NULL, pszNewWindowTitle);

    SetConsoleTitle(pszOldWindowTitle);

    return(hwndFound);
}
class ConsoleUI:public IUserInterface
{
        private:
                int lastx,lasty;
                HWND hConsole;
                HDC hDC;
                int linenow;
                void drawboard(GameBoard board) //������
                {
                        hConsole = GetConsoleHwnd();
                        hDC = GetDC(hConsole);
                        system("cls");//�ַ�����
                        linenow=1;
                        HBRUSH bBrush =CreateSolidBrush(RGB(256,256,256));
                        HBRUSH wBrush =CreateSolidBrush(RGB(255,255,255));
                        SelectObject(hDC,bBrush);
                        Rectangle(hDC,0,0,15*24+16,20*24+16); //�����ھ���ͼ������
                        HPEN hPen = CreatePen(PS_SOLID,1,RGB(255,255,255));
                        HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
                        int i=1;
                        for(i=1;i<=15;i++)
                        {
                                MoveToEx(hDC,i*24,24,NULL);         //������
                                LineTo(hDC,i*24,15*24);
                        }
                        for(i=1;i<=15;i++)
                        {
                                MoveToEx(hDC,24,24*i,NULL);         //�����ߣ��������
                                LineTo(hDC,15*24,i*24);
                        }
                        for(i=0;i<225;i++) //��������
                        {
                                if(board.Check(i)==1) SelectObject(hDC,bBrush);   //�����Ǻڵ�
                                if(board.Check(i)==2) SelectObject(hDC,wBrush);   //�����ð׵�
                                if(board.Check(i)!=0) Ellipse(hDC,((i%15)+1)*24-12,((i/15)+1)*24-12,((i%15)+1)*24+12,((i/15)+1)*24+12);  //���������������
                        }
                        ReleaseDC(hConsole, hDC);
                }
        public:
                ConsoleUI()
                {
                        lastx=8;
                        lasty=8;
                        linenow=1;
                }
                void DetailUpdated(GameBoard board)
                {
                        drawboard(board);
                }
                int Getmovefrom(GameBoard board)//���û��������
                {
                        int xnow,ynow;
                        xnow=lastx;
                        ynow=lasty;       //�����λ�ÿ�ʼ���
                        bool decided=false;
                        HPEN hPen;
                        HPEN hOldPen;
                        while(!decided)
                        {
                                drawboard(board);
                                hConsole = GetConsoleHwnd();
                                hDC = GetDC(hConsole);
                                hPen = CreatePen(PS_SOLID,3,RGB(255,256,256));
                                hOldPen = (HPEN)SelectObject(hDC, hPen);
                                SelectObject(hDC,CreateSolidBrush(RGB(255,256,256))); //��ɫ������ˢ��
                                if(board.Check(xnow,ynow)==0)//���������
                                {
                                        Ellipse(hDC,xnow*24-6,ynow*24-6,xnow*24+6,ynow*24+6);//��СԲ
                                }else{                                  //����
                                        MoveToEx(hDC,xnow*24-12,ynow*24-12,NULL);
                                        LineTo(hDC,xnow*24+12,ynow*24+12);
                                        MoveToEx(hDC,xnow*24+12,ynow*24-12,NULL);
                                        LineTo(hDC,xnow*24-12,ynow*24+12);        //����
                                }
                                ReleaseDC(hConsole, hDC);
                                char a='a';
                                while(!(a==32&&board.Check(xnow,ynow)==0)&& a!=0 && a!=-32 && a!=224)
                                    a=_getch();
                                if(a==32) decided=true;  //���ո�������ӣ�����ѭ��
                                if(a==0 || a==-32 || a==224)                 //�����ܼ�������������ƶ����
                                {
                                        a=_getch();
                                        switch(a)
                                        {
                                                case 72://����
                                                if(ynow>1) ynow--;
                                                break;
                                                case 75://����
                                                if(xnow>1) xnow--;
                                                break;
                                                case 80://����
                                                if(ynow<15) ynow++;
                                                break;
                                                case 77://����
                                                if(xnow<15) xnow++;
                                        }
                                }
                        }
                        lastx=xnow;
                        lasty=ynow;   //��¼���λ��
                        return xnow+15*ynow-16;
                }
                void Showmessage(char *_format)
                {
                        hConsole = GetConsoleHwnd();
                        hDC = GetDC(hConsole);
                        TextOut(hDC,0,(15+linenow)*24,_format,strlen(_format));
                        linenow++;
                        ReleaseDC(hConsole, hDC);
                }
};

#endif  /* GoBangConsoleui_H */
