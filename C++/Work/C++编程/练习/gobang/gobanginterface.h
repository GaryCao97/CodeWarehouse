#ifndef GoBangInterface_H
#define GoBangInterface_H
class GameBoard   //棋盘类
{
        private:
        int b[225];
        public:
        GameBoard()
        {
                for(int i=0;i<225;i++)    //初始化一个空棋盘
                {
                        b[i]=0;
                }
        }
        int Check(int x,int y)            //返回指定位置的棋子
        {
                if(x+15*y-16<225 && x+15*y-16>=0) return b[x+15*y-16];
                return 0;
        }
        int Check(int n)
        {
                if(n<225 && n>=0)return b[n];
                return 0;
        }
        int Setpiece(int x,int y,int z)   //将指定位置下好棋子
        {
                if(z!=0 && b[x+15*y-16]==0 && x+15*y-16<225 && x+15*y-16>=0) return b[x+15*y-16]=z;//空的位置才能下棋子
                return 0;
        }
        int Setpiece(int n,int z)
        {
                if(z!=0 && b[n]==0 && n<225 && n>=0) return b[n]=z;
                return 0;
        }
};
class __declspec(novtable) IPlayer    //玩家接口
{
        public:
        virtual int Move(GameBoard board)=0;   //玩家需要能下棋
};

class __declspec(novtable) IUserInterface    //用户接口
{
        public:
        virtual void DetailUpdated(GameBoard board)=0;
        virtual int Getmovefrom(GameBoard board)=0;
        virtual void Showmessage(char *_format)=0;
};

#endif  /* GoBangInterface_H */
