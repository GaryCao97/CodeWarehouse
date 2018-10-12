#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define LEFT 0x4b00
#define RIGHT 0x4d00
#define UP 0x4800
#define DOWN 0x5000
#define W 19
#define BLACK 1
#define WHITE -1
#define CHESSBORD 0
#define TRUE 1
#define FALSE 0

int map[W][W], qipan[W][W];
int x = 0, y = 0;

void Start()
{
	system("color f1");
	for (int i = 0; i < W; i++)
		for (int j = 0; j < W; j++)
			map[i][j] = CHESSBORD;
	cout << "五子棋" << endl;
	cout << "黑棋按左右上下方向键移动棋子" << endl
		<< "按回车键确定落棋子" << endl 
		<< "白棋按wsad/WSAD键移动棋子" << endl
		<< "按空格键确定落棋子" << endl
		<< "禁止在棋盘外按空格" << endl
		<< "你是否接受上述的游戏规则（Y / N） 如果输入 Y，才可以进行游戏，进入正式的游戏界面." << endl;
}
void Paint(int a[][W])
{
	system("cls");
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < W; j++)
		{
			switch (a[i][j])
			{
			case BLACK:printf("●");
			case WHITE:printf("○");
			case CHESSBORD:
				if (i == 0 && j != 0 && j != W - 1)
					printf("┳");
				else if (i == W - 1 && j != 0 && j != W - 1)
					printf("┻");
				else if (j == 0 && i != 0 && i != W - 1)
					printf("┣");
				else if (j == W - 1 && i != 0 && i != W - 1)
					printf("┫");
				else if (i == 0 && j == 0)
					printf("┏");
				else if (i == 0 && j == W - 1)
					printf("┓");
				else if (i == W - 1 && j == 0)
					printf("┗");
				else if (i == W - 1 && j == W - 1)
					printf("┛");
				else 
					printf("╋");
			}
		}
		cout << endl;
	}
}
void Black_Control()
{
	cout << "现在轮到黑方" << endl;
	char ch;
	do
	{
		ch = _getch();
		switch (ch)
		{
		case LEFT:
			x -= 2;
			break;
		case RIGHT:
			x += 2;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:break;
		}
	} while (ch != 10);
	if (map[x][y] == CHESSBORD)
		map[x][y] = BLACK;
}
void White_Control()
{
	cout << "现在轮到白方" << endl;
	char ch;
	do
	{
		ch = _getch();
		switch (ch)
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x -= 2;
			break;
		case 'd':
			x += 2;
			break;
		default:break;
		}
	} while (ch != ' ');
	if (map[x][y] == CHESSBORD)
		map[x][y] = WHITE;
}
int Win()
{
	int book = 0,sign = FALSE;
	for (int i = 0; i < W - 4; i++)
	{
		for (int j = 0; j < W - 4; j++)
		{
			if (map[i][j] != 0)
			{
				book = map[i][j];
				if (map[i + 1][j] == book && map[i + 2][j] == book && map[i + 3][j] == book && map[i + 4][j] == book)
					sign = TRUE;
				if (map[i][j + 1] == book && map[i][j + 2] == book && map[i][j + 3] == book && map[i][j + 4] == book)
					sign = TRUE;
				if (map[i + 1][j + 1] == book && map[i + 2][j + 2] == book && map[i + 3][j + 3] == book && map[i + 4][j + 4] == book)
					sign = TRUE;
			}
		}
	}
	for (int i = W - 1; i > 3; i--)
	{
		for (int j = W - 1; j > 3; j--)
		{
			if (map[i][j] != 0)
			{
				book = map[i][j];
				if (map[i - 1][j] == book && map[i - 2][j] == book && map[i - 3][j] == book && map[i - 4][j] == book)
					sign = TRUE;
				if (map[i][j - 1] == book && map[i][j - 2] == book && map[i][j - 3] == book && map[i][j - 4] == book)
					sign = TRUE;
				if (map[i - 1][j - 1] == book && map[i - 2][j - 2] == book && map[i - 3][j - 3] == book && map[i - 4][j - 4] == book)
					sign = TRUE;
			}
		}
	}
	for (int i = 0; i < W - 4; i++)
	{
		for (int j = W - 1; j > 3; j--)
		{
			if (map[i][j] != 0)
			{
				book = map[i][j];
				if (map[i + 1][j] == book && map[i + 2][j] == book && map[i + 3][j] == book && map[i + 4][j] == book)
					sign = TRUE;
				if (map[i][j - 1] == book && map[i][j - 2] == book && map[i][j - 3] == book && map[i][j - 4] == book)
					sign = TRUE;
				if (map[i + 1][j - 1] == book && map[i + 2][j - 2] == book && map[i + 3][j - 3] == book && map[i + 4][j - 4] == book)
					sign = TRUE;
			}
		}
	}
	for (int i = W - 1; i > 3; i--)
	{
		for (int j = 0; j < W - 4; j++)
		{
			if (map[i][j] != 0)
			{
				book = map[i][j];
				if (map[i - 1][j] == book && map[i - 2][j] == book && map[i - 3][j] == book && map[i - 4][j] == book)
					sign = TRUE;
				if (map[i][j + 1] == book && map[i][j + 2] == book && map[i][j + 3] == book && map[i][j + 4] == book)
					sign = TRUE;
				if (map[i - 1][j + 1] == book && map[i - 2][j + 2] == book && map[i - 3][j + 3] == book && map[i - 4][j + 4] == book)
					sign = TRUE;
			}
		}
	}
	return sign;
}
void main()
{
	Start();
	char input1;
	cin >> input1;
	if (input1 == 'N' || input1 == 'n')
		return;
	/*do
	{*/
		Paint(map);
		/*do
		{
			Black_Control();
			White_Control();
		} while (1);
	} while (0);*/
}