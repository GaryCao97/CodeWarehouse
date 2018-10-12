#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <Windows.h>
using namespace std;
char maze[10][20]={
	"*******************",
	"* *               *",
	"* *** *           *",
	"*   * *           *",
	"* * * *           *",
	"* * * *           *",
	"* * * *           *",
	"* * * *           *",
	"* *   *            ",
	"*******************"
};
int p = 8,q = 18;
int x = 1,y = 1;
void PaintMaze()
{
	system("cls");
	for(int m = 0;m < 10;m++)
	{
		for(int n = 0;n < 20;n++)
			cout << maze[m][n];
		cout << endl;
	}
}
void Move(char a)
{
	switch (a)
	{
	case 'w':
		if(maze[x-1][y] != '*')
		{
			maze[x][y] = ' ';
			maze[--x][y] = 248;
		}
		break;
	case 'a':
		if(maze[x][y-1] != '*')
		{
			maze[x][y] = ' ';
			maze[x][--y] = 248;
		}
		break;
	case 's':
		if(maze[x+1][y] != '*')
		{
			maze[x][y] = ' ';
			maze[++x][y] = 248;
		}
		break;
	case 'd':
		if(maze[x][y+1] != '*')
		{
			maze[x][y] = ' ';
			maze[x][++y] = 248;
		}
		break;
	default:
		break;
	}
}
int main()
{
	maze[1][1] = 248;
	PaintMaze();
	do
	{
		char get_move;
		get_move = getch();
		Move(get_move);
		PaintMaze();
	}while(x != p || y != q);
	cout << "win" << endl;
	return 0;
}