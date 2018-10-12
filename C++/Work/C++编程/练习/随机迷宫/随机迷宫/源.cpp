#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define HIGH 10
#define WIDTH 20
using namespace std;
char maze[HIGH][WIDTH];
int x = 1,y = 1;
int p = HIGH -2,q = WIDTH - 1;
int book[HIGH][WIDTH];
void Paint();
void Create();
void _Road(int m,int n);
void Road(int m,int n);
void Move();
int main()
{
	srand((unsigned)time(0));
	Create();
	Paint();
	do
	{
		Move();
		Paint();
	}while(x != p || y != q);
	cout << "WIN !!!!!" << endl;
	return 0;
}
void Road(int m,int n)
{
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int nx,ny,mx,my;
	maze[m][n] = ' ';
	int i,j;
	i = rand() % 4;
	nx = m + next[i][0];
	ny = n + next[i][1];
	if (book[nx][ny] == 0)
	{
		book[nx][ny] = 1;
		Road(nx,ny);
	}
}
void _Road(int m,int n)
{
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int nx,ny;
	maze[m][n] = ' ';
	int k;
	do
	{
		k = rand() % 4;
		nx = m + next[k][0];
		ny = n + next[k][1];
		if (book[nx][ny] == 0)
		{
			book[nx][ny] = 1;
			Road(nx,ny);
		}
	}while(maze[nx][ny] == '*' && book[nx][ny] == 1);
}
void Create()
{
	for(int i = 0;i < HIGH;i++)
		for(int j = 0;j < WIDTH;j++)
		{
			int ch = rand() % 2;
			if (ch == 0)
				maze[i][j] = ' ';
			else if (ch == 1)
				maze[i][j] = '*';
			if(i == 0 || j == 0 || i == HIGH-1 || j == WIDTH-1)
				book[i][j] = 1;
			else book[i][j] = 0;
			maze[i][j] = '*';
		}
	maze[HIGH - 2][WIDTH - 1] = 'E';
	//Road(1,1);Road(HIGH - 2,WIDTH - 2);
	int times = HIGH + WIDTH;
	for(;times > 0;times--)
	{
		int mx = rand() % (HIGH-2) + 1,my = rand() % (WIDTH-2) + 1;
		if(maze[mx][my] == '*')
			_Road(mx,my);
		else times++;
	}
	maze[1][1] = 'O';
}
void Paint()
{
	system("cls");
	for(int o = 0;o < HIGH;o++)
	{
		for(int z = 0;z < WIDTH;z++)
			cout << maze[o][z];
		cout << endl;
	}
}
void Move()
{
	char get_move;
	get_move = getch();
	switch (get_move)
	{
	case 'w':
		if(maze[x-1][y] != '*')
		{
			maze[x][y] = ' ';
			maze[--x][y] = 'O';
		}
		break;
	case 'a':
		if(maze[x][y-1] != '*')
		{
			maze[x][y] = ' ';
			maze[x][--y] = 'O';
		}
		break;
	case 's':
		if(maze[x+1][y] != '*')
		{
			maze[x][y] = ' ';
			maze[++x][y] = 'O';
		}
		break;
	case 'd':
		if(maze[x][y+1] != '*')
		{
			maze[x][y] = ' ';
			maze[x][++y] = 'O';
		}
		break;
	default:
		break;
	}
}
