#ifndef GoBangLocalPlayer_H
#define GoBangLocalPlayer_H
#include "gobanginterface.h"
class LocalPlayer:public IPlayer  //���������
{
        private:
                IUserInterface *myui;
        public:
                LocalPlayer(IUserInterface *ui)
                {
                        myui=ui;
                }
                int Move(GameBoard board)
                {
                        int a= myui->Getmovefrom(board);  //���������Ҫ����ʱ
                        return a;                         //��UI����������������
                }
};
#endif /* GoBangLocalPlayer_H */
