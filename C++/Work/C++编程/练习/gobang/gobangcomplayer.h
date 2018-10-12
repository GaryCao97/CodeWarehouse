#ifndef GOBANGCOMPLAYER_H_INCLUDED
#define GOBANGCOMPLAYER_H_INCLUDED
#include "gobanginterface.h"
class ComPlayer:public IPlayer          //电脑玩家类
{
        protected:
                int col;
                IUserInterface *myui;
                int calcscore(int n,GameBoard board,int h)  //计算某点分数
                {
                if(h==0) return -1;
                if(board.Check(n)!=0) return -1;   //有子的地方当然不能放了
                int score[7]={0,0,0,0,0,0,0};//5子，活4，死4，活3，死3，活2，死2
                int px=(n%15)+1;
                int py=(n/15)+1;
                int s=1;
                bool flag=true;
                int blocked=0;
                while(py>1&&flag) //向上找
                {
                        py--;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                py=(n/15)+1;          //重置
                flag=true;
                while(py<15&&flag) //向下找
                {
                        py++;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                py=(n/15)+1;           //重置
                flag=true;
                if(s>=5) score[0]++;
                if(s==4&&blocked==0) score[1]++;
                if(s==4&&blocked==1) score[2]++;
                if(s==3&&blocked==0) score[3]++;
                if(s==3&&blocked==1) score[4]++;
                if(s==2&&blocked==0) score[5]++;
                if(s==2&&blocked==1) score[6]++;
                s=1;
                blocked=0;
                while(px>1&&flag) //向左找
                {
                        px--;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;           //重置
                flag=true;
                while(px<15&&flag) //向右找
                {
                        px++;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;
                flag=true;
                if(s>=5) score[0]++;
                if(s==4&&blocked==0) score[1]++;
                if(s==4&&blocked==1) score[2]++;
                if(s==3&&blocked==0) score[3]++;
                if(s==3&&blocked==1) score[4]++;
                if(s==2&&blocked==0) score[5]++;
                if(s==2&&blocked==1) score[6]++;
                s=1;
                blocked=0;
                while(px>1&&py>1&&flag)//向左上找
                {
                        px--;
                        py--;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;              //重置
                py=(n/15)+1;
                flag=true;
                while(px<15&&py<15&&flag)//向右下找
                {
                        px++;
                        py++;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;             //重置
                py=(n/15)+1;
                flag=true;
                if(s>=5) score[0]++;
                if(s==4&&blocked==0) score[1]++;
                if(s==4&&blocked==1) score[2]++;
                if(s==3&&blocked==0) score[3]++;
                if(s==3&&blocked==1) score[4]++;
                if(s==2&&blocked==0) score[5]++;
                if(s==2&&blocked==1) score[6]++;
                s=1;
                blocked=0;
                while(px>1&&py<15&&flag)//向左下找
                {
                        px--;
                        py++;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;            //重置
                py=(n/15)+1;
                flag=true;
                while(px<15&&py>1&&flag)//向右上找
                {
                        px++;
                        py--;
                        if(board.Check(px,py)==h)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                if((board.Check(px,py)!=0)||flag) blocked++;
                px=(n%15)+1;             //重置
                py=(n/15)+1;
                flag=true;
                if(s>=5) score[0]++;
                if(s==4&&blocked==0) score[1]++;
                if(s==4&&blocked==1) score[2]++;
                if(s==3&&blocked==0) score[3]++;
                if(s==3&&blocked==1) score[4]++;
                if(s==2&&blocked==0) score[5]++;
                if(s==2&&blocked==1) score[6]++;
                int sc=0;
                sc+=100000*score[0];
                sc+=10000*score[1];
                if(score[2]>=2) sc+=10000;
                if(score[2]>=1 && score[3]>=1) sc+=10000;
                if(score[3]>=2) sc+=6000;
                if(score[3]>=1 && score[4]>=1) sc+=1000;
                if(score[2]==1) sc+=500;
                if(score[3]==1) sc+=200;
                if(score[5]>=2) sc+=100;
                if(score[4]==1) sc+=50;
                if(score[6]>=2) sc+=10;
                if(score[5]==1) sc+=5;
                if(score[6]==1) sc+=3;
                if(n==112) sc+=1;
                return sc;
                }
        public:
                ComPlayer(IUserInterface *ui,int color)
                {
                        myui=ui;
                        col=color;
                }
                virtual int Move(GameBoard board)=0;     //电脑玩家的操作
};

class BakaPlayer:public ComPlayer
{
        public:
        BakaPlayer(IUserInterface *ui,int color):ComPlayer(ui,color){}
        int Move(GameBoard board)
        {
                        int bestpoint;
                        int bestscore=0;
                        int score;
                        bool flag=true;
                        myui->Showmessage("Baka:I'm thinking...\n");
                        for(int i=0;i<225;i++)     //遍历所有点
                        {
                                score=calcscore(i,board,col)+calcscore(i,board,3-col)/2;//计算该点分数
                                if(score>bestscore)   //如果比最高分高
                                {
                                        if(score>7500 && flag)
                                        {
                                        flag=false;
                                        myui->Showmessage("Baka:I've found a powerful move!\n");
                                        }
                                        bestpoint =i;
                                        bestscore=score;//记录
                                }
                        }
                        if(bestscore>7500)
                        {
                                myui->Showmessage("Baka:Take this! ");
                                Sleep(500);
                        }
                        Sleep(500);
                        return bestpoint;  //返回自己找到的最好点
        }
};

class NormalPlayer:public ComPlayer
{
        public:
        NormalPlayer(IUserInterface *ui,int color):ComPlayer(ui,color){}
        int Move(GameBoard board)
        {
                int bestpoint;
                int bestscore=-1000000;
                int score,bestscore2,score2;
                myui->Showmessage("Hito:I'm thinking...\n");
                GameBoard temp;
                for(int i=0;i<225;i++)
                {
                        temp=board;
                        bestscore2=0;
                        score=1000000;
                        if(board.Check(i)==0)
                        {
                                temp.Setpiece(i,col);
                                for(int j=0;j<225;j++)          //下某子后对方的分数
                                {
                                        score2=calcscore(j,temp,3-col);
                                        if(score2>bestscore2)
                                                bestscore2=score2;
                                }
                                score=bestscore2;
                        }
                        score=-score;       //目的使对方无法得到高点数的位置
                        score+=(calcscore(i,board,col)+calcscore(i,board,3-col)/2)/2;
                        if(score>bestscore)
                        {
                                bestscore=score;
                                bestpoint=i;
                        }
                }
                Sleep(300);
                return bestpoint;
        }
};


#endif // GOBANGCOMPLAYER_H_INCLUDED
