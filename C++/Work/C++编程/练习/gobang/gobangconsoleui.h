#ifndef GoBangConsoleui_H
#define GoBangConsoleui_H
#include "gobanginterface.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
HWND GetConsoleHwnd(void)           //获取控制台句柄，用于画图
{                                   //from MSDN
#define MY_BUFSIZE 1024 // 标题的缓冲大小
    HWND hwndFound;         // 返回的句柄
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
                void drawboard(GameBoard board) //画棋盘
                {
                        hConsole = GetConsoleHwnd();
                        hDC = GetDC(hConsole);
                        system("cls");//字符清屏
                        linenow=1;
                        HBRUSH bBrush =CreateSolidBrush(RGB(256,256,256));
                        HBRUSH wBrush =CreateSolidBrush(RGB(255,255,255));
                        SelectObject(hDC,bBrush);
                        Rectangle(hDC,0,0,15*24+16,20*24+16); //画个黑矩形图形清屏
                        HPEN hPen = CreatePen(PS_SOLID,1,RGB(255,255,255));
                        HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
                        int i=1;
                        for(i=1;i<=15;i++)
                        {
                                MoveToEx(hDC,i*24,24,NULL);         //画横线
                                LineTo(hDC,i*24,15*24);
                        }
                        for(i=1;i<=15;i++)
                        {
                                MoveToEx(hDC,24,24*i,NULL);         //画竖线，组成棋盘
                                LineTo(hDC,15*24,i*24);
                        }
                        for(i=0;i<225;i++) //遍历棋盘
                        {
                                if(board.Check(i)==1) SelectObject(hDC,bBrush);   //黑棋是黑的
                                if(board.Check(i)==2) SelectObject(hDC,wBrush);   //白棋用白的
                                if(board.Check(i)!=0) Ellipse(hDC,((i%15)+1)*24-12,((i/15)+1)*24-12,((i%15)+1)*24+12,((i/15)+1)*24+12);  //有棋子则绘制棋子
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
                int Getmovefrom(GameBoard board)//向用户请求操作
                {
                        int xnow,ynow;
                        xnow=lastx;
                        ynow=lasty;       //从最近位置开始光标
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
                                SelectObject(hDC,CreateSolidBrush(RGB(255,256,256))); //红色画笔与刷子
                                if(board.Check(xnow,ynow)==0)//如果能下子
                                {
                                        Ellipse(hDC,xnow*24-6,ynow*24-6,xnow*24+6,ynow*24+6);//画小圆
                                }else{                                  //否则
                                        MoveToEx(hDC,xnow*24-12,ynow*24-12,NULL);
                                        LineTo(hDC,xnow*24+12,ynow*24+12);
                                        MoveToEx(hDC,xnow*24+12,ynow*24-12,NULL);
                                        LineTo(hDC,xnow*24-12,ynow*24+12);        //画叉
                                }
                                ReleaseDC(hConsole, hDC);
                                char a='a';
                                while(!(a==32&&board.Check(xnow,ynow)==0)&& a!=0 && a!=-32 && a!=224)
                                    a=_getch();
                                if(a==32) decided=true;  //按空格键则下子，跳出循环
                                if(a==0 || a==-32 || a==224)                 //按功能键（方向键）则移动光标
                                {
                                        a=_getch();
                                        switch(a)
                                        {
                                                case 72://向上
                                                if(ynow>1) ynow--;
                                                break;
                                                case 75://向左
                                                if(xnow>1) xnow--;
                                                break;
                                                case 80://向下
                                                if(ynow<15) ynow++;
                                                break;
                                                case 77://向右
                                                if(xnow<15) xnow++;
                                        }
                                }
                        }
                        lastx=xnow;
                        lasty=ynow;   //记录最近位置
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
