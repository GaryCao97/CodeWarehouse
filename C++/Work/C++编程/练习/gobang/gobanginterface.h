#ifndef GoBangInterface_H
#define GoBangInterface_H
class GameBoard   //������
{
        private:
        int b[225];
        public:
        GameBoard()
        {
                for(int i=0;i<225;i++)    //��ʼ��һ��������
                {
                        b[i]=0;
                }
        }
        int Check(int x,int y)            //����ָ��λ�õ�����
        {
                if(x+15*y-16<225 && x+15*y-16>=0) return b[x+15*y-16];
                return 0;
        }
        int Check(int n)
        {
                if(n<225 && n>=0)return b[n];
                return 0;
        }
        int Setpiece(int x,int y,int z)   //��ָ��λ���º�����
        {
                if(z!=0 && b[x+15*y-16]==0 && x+15*y-16<225 && x+15*y-16>=0) return b[x+15*y-16]=z;//�յ�λ�ò���������
                return 0;
        }
        int Setpiece(int n,int z)
        {
                if(z!=0 && b[n]==0 && n<225 && n>=0) return b[n]=z;
                return 0;
        }
};
class __declspec(novtable) IPlayer    //��ҽӿ�
{
        public:
        virtual int Move(GameBoard board)=0;   //�����Ҫ������
};

class __declspec(novtable) IUserInterface    //�û��ӿ�
{
        public:
        virtual void DetailUpdated(GameBoard board)=0;
        virtual int Getmovefrom(GameBoard board)=0;
        virtual void Showmessage(char *_format)=0;
};

#endif  /* GoBangInterface_H */
