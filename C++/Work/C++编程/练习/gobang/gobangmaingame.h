#ifndef GOBANGMAINGAME_H_INCLUDED
#define GOBANGMAINGAME_H_INCLUDED
#include "gobanginterface.h"
class Maingame
{
        private:
        GameBoard board;
        bool check(int piecex,int piecey)//���piece������������Ϸ�����򷵻�FALSE
        {
                int s=1;                 //��¼���ߵ���������
                int px=piecex;
                int py=piecey;
                int c=board.Check(px,py);
                bool flag=true;
                while(py>1&&flag) //������
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
                py=piecey;          //����
                flag=true;
                while(py<15&&flag) //������
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
                py=piecey;           //����
                flag=true;
                if(s>=5) return false; //�����ֱ����5��
                s=1;
                while(px>1&&flag) //������
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
                px=piecex;           //����
                flag=true;
                while(px<15&&flag) //������
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
                if(s>=5) return false; //���ˮƽ����5��
                s=1;
                while(px>1&&py>1&&flag)//��������
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
                px=piecex;              //����
                py=piecey;
                flag=true;
                while(px<15&&py<15&&flag)//��������
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
                px=piecex;             //����
                py=piecey;
                flag=true;
                if(s>=5) return false; //����-���µĶԽ��������5������
                s=1;
                while(px>1&&py<15&&flag)//��������
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
                px=piecex;            //����
                py=piecey;
                flag=true;
                while(px<15&&py>1&&flag)//��������
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
                px=piecex;             //����
                py=piecey;
                flag=true;
                if(s>=5) return false; //����-���ϵĶԽ��������5������
                return true;
        }
        bool check(int piece)
        {
                return check((piece%15)+1,(piece/15)+1); //ת��
        }
        IPlayer *black;
        IPlayer *white;
        IUserInterface *ui;
        public:
        Maingame(IPlayer *blackplayer,IPlayer *whiteplayer,IUserInterface *theui)
        {                                                 //��ʼ��

                black=blackplayer;
                white=whiteplayer;
                ui=theui;
                ui->DetailUpdated(board);
                ui->Showmessage("Game initialed.");
        }
        void run()                               //��Ϸ��ʼ
        {
                ui->DetailUpdated(board);
                int last=black->Move(board);           //�ڷ�����
                board.Setpiece(last,1);                //�������ºڷ�����
                ui->DetailUpdated(board);              //֪ͨ�������
                int step=1;                            //������1��
                while(check(last)&& step !=225)        //���µ��Ӳ�����Ϸ����
                {                                      //��
                        last=white->Move(board);       //Ҫ��׷�����
                        board.Setpiece(last,2);        //�������°׷�����
                        ui->DetailUpdated(board);      //֪ͨ�������
                        step++;                        //��������
                        if(check(last) && step !=225)  //���µ��Ӳ�����Ϸ����
                        {                              //��
                               last=black->Move(board);//Ҫ��ڷ�����
                               board.Setpiece(last,1); //�������ºڷ�����
                               ui->DetailUpdated(board);//֪ͨ�������
                               step++;                 //��������
                        }
                }                                       //ѭ��
                if(step==225)
                {                                       //�������Ϊ��������
                        ui->Showmessage("No one win."); //��ƽ��
                }else if(board.Check(last)==1)          //��������µ��Ǻڷ�
                {
                        ui->Showmessage("Black wins."); //�ڷ�ʤ��
                }else if(board.Check(last)==2)          //��������µľ��ǰ׷�
                {
                        ui->Showmessage("White wins."); //�׷�ʤ����
                }
        }
};



#endif // GOBANGMAINGAME_H_INCLUDED
