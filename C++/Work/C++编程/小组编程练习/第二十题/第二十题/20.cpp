#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;

#define End 3
#define Player 2
#define Wall 1
#define Road 0
#define W 25
#define L 25
int maze[W+2][L+2];
int x = 2,y = 1;

void Create(int x,int y);
void MapCreate();
int Start();
void Paint();
void Move();
int main()
{
	SYSTEMTIME sys[2];
	srand((unsigned)time(NULL));
	MapCreate();
	if (Start() == 0)
		return 0;
	GetLocalTime(&sys[0]);
	Paint();
	while(x != 24 || y != 25)
	{
		Move();
		Paint();
	}
	system("cls");
	GetLocalTime(&sys[1]);
	int mm = sys[1].wMinute - sys[0].wMinute, ss = sys[1].wSecond - sys[0].wSecond;
	if (ss < 0)
	{
		ss += 60;
		mm -= 1;
	}
	else if (ss > 59)
	{
		ss -= 60;
		mm += 1;
	}
	printf("\n好牛逼啊，走出迷宫只花了%2d:%2d的时间！\n", mm, ss);
	return 0;
}
int Start()
{
	system("color f5");
	cout << "走迷宫小游戏" << endl;
	cout<< "游戏规则：" << endl
		<< "使用wasd键控制移动；" << endl
		<< "☆ 是你控制的角色；" << endl
		<< "※ 是墙；" << endl
		<< "出 是出口；" << endl
		<< "到达出口即可获胜。" << endl << endl
		<< "按下'Y/y'开始游戏" << endl
		<< endl;
	char ch = getch();
	switch(ch)
	{
	case 'y':
	case 'Y':
		return 1;
		break;
	default: 
		return 0;
		break;
	}
}
void Create(int m,int n) 
{
	int next[4][2]={
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
	};
	int i,j,t;
	for(i=0;i<4;i++)
	{
		j=rand()%4;
		t=next[i][0],next[i][0]=next[j][0],next[j][0]=t;
		t=next[i][1],next[i][1]=next[j][1],next[j][1]=t;
	}
	maze[m][n]=Road;
	for(i=0;i<4;i++)
		if(maze[m+2*next[i][0]][n+2*next[i][1]]==Wall)
		{
			maze[m+next[i][0]][n+next[i][1]]=Road;
			Create(m+2*next[i][0],n+2*next[i][1]);
		}
}
void MapCreate()
{
	int i,j;
	for(i=0;i<=L+1;i++)
		for(j=0;j<=W+1;j++)
			if(i==0||i==L+1||j==0||j==W+1)
				maze[i][j]=Road;
			else maze[i][j]=Wall;
	Create(2*(rand()%(L/2)+1),2*(rand()%(W/2)+1));
	for(i=0;i<=L+1;i++) 
	{
		maze[i][0]=Wall; 
		maze[i][W+1]=Wall; 
	}
	for(j=0;j<=W+1;j++) 
	{
		maze[0][j]=Wall; 
		maze[L+1][j]=Wall;
	}
	maze[L-1][W]=End; 
	maze[2][1] = Player;
}
void Paint()
{
	system("cls");
	int i,j;
	for(i=1;i<W+1;i++)
	{
		for(j=1;j<L+1;j++)
		{
			if(maze[i][j]==Wall)printf("※");
			else if(maze[i][j]==Road)printf("  ");
			else if(maze[i][j]==Player)printf("☆");
			else printf("出");
		}
		if(i != W)printf("\n");
	}
}
void Move()
{
	char ch = getch();
	switch(ch)
	{
	case 'a':
		{
			if(maze[x][y-1]!=Wall)
			{
				maze[x][y]=Road;
				maze[x][y-1]=Player;
				y--;
			}
			break;
		}
	case 'd':
		{
			if(maze[x][y+1]!=Wall)
			{
				maze[x][y]=Road;
				maze[x][y+1]=Player;
				y++;
			}
			break;
		}
	case 'w':
		{
			if(maze[x-1][y]!=Wall)
			{
				maze[x][y]=Road;
				maze[x-1][y]=Player;
				x--;
			}
			break;
		}
	case 's':
		{
			if(maze[x+1][y]!=Wall)
			{
				maze[x][y]=Road;
				maze[x+1][y]=Player;
				x++;
			}
			break;
		}
	default:break;
	}
}
