#ifndef GOBANGMAINGAME_H_INCLUDED
#define GOBANGMAINGAME_H_INCLUDED
#include "gobanginterface.h"
class Maingame
{
        private:
        GameBoard board;
        bool check(int piecex,int piecey)//如果piece处的棋子让游戏结束则返回FALSE
        {
                int s=1;                 //记录连线的棋子数量
                int px=piecex;
                int py=piecey;
                int c=board.Check(px,py);
                bool flag=true;
                while(py>1&&flag) //向上找
                {
                        py--;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                py=piecey;          //重置
                flag=true;
                while(py<15&&flag) //向下找
                {
                        py++;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                py=piecey;           //重置
                flag=true;
                if(s>=5) return false; //如果垂直连成5个
                s=1;
                while(px>1&&flag) //向左找
                {
                        px--;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;           //重置
                flag=true;
                while(px<15&&flag) //向右找
                {
                        px++;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;
                flag=true;
                if(s>=5) return false; //如果水平连成5个
                s=1;
                while(px>1&&py>1&&flag)//向左上找
                {
                        px--;
                        py--;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;              //重置
                py=piecey;
                flag=true;
                while(px<15&&py<15&&flag)//向右下找
                {
                        px++;
                        py++;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;             //重置
                py=piecey;
                flag=true;
                if(s>=5) return false; //左上-右下的对角线如果有5个以上
                s=1;
                while(px>1&&py<15&&flag)//向左下找
                {
                        px--;
                        py++;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;            //重置
                py=piecey;
                flag=true;
                while(px<15&&py>1&&flag)//向右上找
                {
                        px++;
                        py--;
                        if(board.Check(px,py)==c)
                        {
                                s++;
                        }
                        else
                        {
                                flag=false;
                        }
                }
                px=piecex;             //重置
                py=piecey;
                flag=true;
                if(s>=5) return false; //左下-右上的对角线如果有5个以上
                return true;
        }
        bool check(int piece)
        {
                return check((piece%15)+1,(piece/15)+1); //转换
        }
        IPlayer *black;
        IPlayer *white;
        IUserInterface *ui;
        public:
        Maingame(IPlayer *blackplayer,IPlayer *whiteplayer,IUserInterface *theui)
        {                                                 //初始化

                black=blackplayer;
                white=whiteplayer;
                ui=theui;
                ui->DetailUpdated(board);
                ui->Showmessage("Game initialed.");
        }
        void run()                               //游戏开始
        {
                ui->DetailUpdated(board);
                int last=black->Move(board);           //黑方先下
                board.Setpiece(last,1);                //棋盘落下黑方棋子
                ui->DetailUpdated(board);              //通知界面更新
                int step=1;                            //进行了1步
                while(check(last)&& step !=225)        //落下的子不让游戏结束
                {                                      //则
                        last=white->Move(board);       //要求白方下子
                        board.Setpiece(last,2);        //棋盘落下白方棋子
                        ui->DetailUpdated(board);      //通知界面更新
                        step++;                        //步数增加
                        if(check(last) && step !=225)  //落下的子不让游戏结束
                        {                              //则
                               last=black->Move(board);//要求黑方下子
                               board.Setpiece(last,1); //棋盘落下黑方棋子
                               ui->DetailUpdated(board);//通知界面更新
                               step++;                 //步数增加
                        }
                }                                       //循环
                if(step==225)
                {                                       //如果是因为步数用完
                        ui->Showmessage("No one win."); //则平局
                }else if(board.Check(last)==1)          //否则最后下的是黑方
                {
                        ui->Showmessage("Black wins."); //黑方胜利
                }else if(board.Check(last)==2)          //否则最后下的就是白方
                {
                        ui->Showmessage("White wins."); //白方胜利。
                }
        }
};



#endif // GOBANGMAINGAME_H_INCLUDED
