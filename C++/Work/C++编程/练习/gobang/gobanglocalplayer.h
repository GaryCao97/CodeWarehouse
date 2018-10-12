#ifndef GoBangLocalPlayer_H
#define GoBangLocalPlayer_H
#include "gobanginterface.h"
class LocalPlayer:public IPlayer  //本地玩家类
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
                        int a= myui->Getmovefrom(board);  //本地玩家需要动作时
                        return a;                         //向UI请求玩家输入操作。
                }
};
#endif /* GoBangLocalPlayer_H */
