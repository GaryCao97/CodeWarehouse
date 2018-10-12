#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define W 19
#define BLACK 1
#define WHITE -1
#define CHESSBORD 0
#define CH 10
#define UNCH -10
#define TRUE 1
#define FALSE 0


int map[W][W], qipan[W][W];
int x = 0, y = 0;

void Start();
void Paint(int a[][W]);
void Copy();
void Black_Control();
void White_Control();
int Win();
void Win(int a);

void main()
{
	system("color f0");
	Start();
	char input1;
	cin >> input1;
	if (input1 == 'N' || input1 == 'n')
		return;
	Paint(qipan);
	for (;;)
	{
		Black_Control();
		if (Win() != FALSE)
			break;
		White_Control();
		if (Win() != FALSE)
			break;
	}
	Win(Win());
	system("pause");
	printf("\t");
}
void Start()
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < W; j++)
			map[i][j] = CHESSBORD;
	Copy();
	qipan[x][y] = CH;
	printf("\n\n\n\t五子棋\n");
	printf("\t黑棋按左右上下方向键移动棋子\n");
	printf("\t按回车键确定落棋子\n");
	printf("\t白棋按wsad / WSAD键移动棋子\n");
	printf("\t按空格键确定落棋子\n");
	printf("\t禁止在棋盘外按空格\n");
	printf("\t你是否接受上述的游戏规则（Y / N）.\n\n\t");
}
void Paint(int a[][W])
{
	system("cls");
	printf("\n\n\n");
	for (int i = 0; i < W; i++)
	{
		printf("\t");
		for (int j = 0; j < W; j++)
		{
			switch (a[i][j])
			{
			case BLACK:printf("●"); break;
			case WHITE:printf("○"); break;
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
				break;
			case CH:printf("◎"); break;
			case UNCH:printf("╳"); break;
			}
		}
		printf("\n");
	}
}
void Copy()
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < W; j++)
			qipan[i][j] = map[i][j];
}
void Black_Control()
{
	char ch;
	do
	{
		printf("\t现在轮到黑方");
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
				y--;
				break;
			case RIGHT:
				y++;
				break;
			case UP:
				x--;
				break;
			case DOWN:
				x++;
				break;
			default:break;
			}
		}
		if (x < 0)x++;
		if (x > W - 1)x--;
		if (y < 0)y++;
		if (y > W - 1)y--;
		if (ch == '\r' && map[x][y] != CHESSBORD)
			ch = 0;
		Copy();
		if (qipan[x][y] == 0)
			qipan[x][y] = CH;
		else qipan[x][y] = UNCH;
		Paint(qipan);
	} while (ch != '\r');
	if (map[x][y] == CHESSBORD)
		map[x][y] = BLACK;
	Paint(map);
	Copy();
}
void White_Control()
{
	char ch;
	do
	{
		printf("\t现在轮到白方");
		ch = _getch();
		switch (ch)
		{
		case 'w':
			x--;
			break;
		case 's':
			x++;
			break;
		case 'a':
			y--;
			break;
		case 'd':
			y++;
			break;
		default:break;
		}
		if (x < 0)x++;
		if (x > W - 1)x--;
		if (y < 0)y++;
		if (y > W - 1)y--;
		if (ch == ' ' && map[x][y] != CHESSBORD)
			ch = 0;
		Copy();
		if (qipan[x][y] == 0)
			qipan[x][y] = CH;
		else qipan[x][y] = UNCH;
		Paint(qipan);
	} while (ch != ' ');
	if (map[x][y] == CHESSBORD)
		map[x][y] = WHITE;
	Paint(map);
	Copy();
}
int Win()
{
	int book = 0, sign = FALSE;
	for (int i = 0; i < W - 4; i++)
	{
		for (int j = 0; j < W - 4; j++)
		{
			if (map[i][j] != 0)
			{
				book = map[i][j];
				if (map[i + 1][j] == book && map[i + 2][j] == book && map[i + 3][j] == book && map[i + 4][j] == book)
					sign = map[i][j];
				if (map[i][j + 1] == book && map[i][j + 2] == book && map[i][j + 3] == book && map[i][j + 4] == book)
					sign = map[i][j];
				if (map[i + 1][j + 1] == book && map[i + 2][j + 2] == book && map[i + 3][j + 3] == book && map[i + 4][j + 4] == book)
					sign = map[i][j];
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
					sign = map[i][j];
				if (map[i][j - 1] == book && map[i][j - 2] == book && map[i][j - 3] == book && map[i][j - 4] == book)
					sign = map[i][j];
				if (map[i - 1][j - 1] == book && map[i - 2][j - 2] == book && map[i - 3][j - 3] == book && map[i - 4][j - 4] == book)
					sign = map[i][j];
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
					sign = map[i][j];
				if (map[i][j - 1] == book && map[i][j - 2] == book && map[i][j - 3] == book && map[i][j - 4] == book)
					sign = map[i][j];
				if (map[i + 1][j - 1] == book && map[i + 2][j - 2] == book && map[i + 3][j - 3] == book && map[i + 4][j - 4] == book)
					sign = map[i][j];
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
					sign = map[i][j];
				if (map[i][j + 1] == book && map[i][j + 2] == book && map[i][j + 3] == book && map[i][j + 4] == book)
					sign = map[i][j];
				if (map[i - 1][j + 1] == book && map[i - 2][j + 2] == book && map[i - 3][j + 3] == book && map[i - 4][j + 4] == book)
					sign = map[i][j];
			}
		}
	}
	return sign;
}
void Win(int a)
{
	system("cls");
	printf("\n\n\n");
	switch (a)
	{
	case BLACK:
		printf("\t黑方获胜\n\t"); 
		break;
	case WHITE:
		printf("\t白方获胜\n\t");
		break;
	}
}