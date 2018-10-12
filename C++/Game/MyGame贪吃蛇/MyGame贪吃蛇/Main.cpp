#include <Windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
using namespace std;

#define RANDOM(min, max) ((min) + (rand()%((max) - (min) + 1)))
#define MAP_SIZE 30
#define MENU_WIDTH 10
#define TOP 1
#define LEFT (TOP * 2)
#define KEY_DOWN    80   /* 向下箭头键 */
#define KEY_UP      72   /* 向上箭头键 */
#define KEY_RIGHT   77   /* 向右箭头键 */
#define KEY_LEFT    75   /* 向左箭头键 */
//-------------贪吃蛇自身结构---------
typedef struct Position {
	int x;
	int y;
	Position operator+(Position op) {
		return{ x + op.x,y + op.y };
	}
	Position operator-(Position op) {
		return{ x - op.x,y - op.y };
	}
	bool operator!=(Position op) {
		return (x != op.x || y != op.y);
	}
	Position(int i = 0, int j = 0) {
		x = i; y = j;
	}
}Position, Direction;
typedef struct SnakeNode {
	SnakeNode* next;
	SnakeNode* prev;
	Position pos;
	Direction dir;
}*SnakeBody;
typedef struct Snake {
	SnakeBody head, tail;
	int length;
	Snake() {
		length = 3;
		head = new SnakeNode();
		SnakeBody q = head;
		for (int i = 0; i < length; i++) {
			SnakeBody p = new SnakeNode();
			p->pos = { 0 , length - i - 1 };
			p->dir.x = 0;
			p->dir.y = 1;
			p->prev = NULL;
			if (i == 0) {
				q = head = p;
			}
			else {
				p->prev = q;
				q->next = p;
				q = q->next;
			}
		}
		tail = q;
		tail->next = NULL;
	}
}Snake;
int Map[MAP_SIZE][MAP_SIZE];

//----------相关函数--------
void WindowChange();
void GotoXY(short x, short y);//光标移动
void HideCursor();//隐藏光标
int GetKey();
void Gaming();

int main() {
	WindowChange();
	srand((unsigned int)time(0));
	HideCursor();
	Gaming();
	return 0;
}

void WindowChange() {
	char str[50];
	sprintf_s(str, 50, "MODE con: COLS=%d LINES=%d", MAP_SIZE * 2 + 4 + MENU_WIDTH, MAP_SIZE + 2);
	system(str);
}
void GotoXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int GetKey(){
	int c1, c2;
	if ((c1 = _getch()) != 224)return c1;
	c2 = _getch();
	return c2;
}
void MoveSnake(Snake &S) {
	SnakeBody p = S.head;
	while (p) {
		if (!p->next)
			Map[p->pos.y][p->pos.x] = 0;
		if (p == S.head)
			Map[p->pos.y][p->pos.x] = 1;
		p->pos = p->pos + p->dir;
		p = p->next;
	}
	Map[S.head->pos.y][S.head->pos.x] = 2;
}
void PaintSnake(Snake &S) {
	SnakeBody p = S.head;
	Position q;
	while (p) {
		q = p->pos - p->dir;
		GotoXY(2 * q.x + LEFT, q.y + TOP);
		printf("  ");
		p = p->next;
	}
	p = S.head;
	while (p) {
		q = p->pos;
		GotoXY(2 * q.x + LEFT, q.y + TOP);
		printf("□");
		p = p->next;
	}
	GotoXY(2 * S.head->pos.x + LEFT, S.head->pos.y + TOP);
	printf("○");
}
void CreateFood() {
	int x, y;
	do {
		x = RANDOM(1, MAP_SIZE - 1);
		y = RANDOM(1, MAP_SIZE - 1);
	} while (Map[y][x] != 0);
	Map[y][x] = 3;
	GotoXY(LEFT + 2 * x, TOP + y);
	printf("★");
}
void Gaming() {
	for (int i = -1; i <= MAP_SIZE; i++) {
		GotoXY(LEFT + 2 * i, 0);
		printf("※");
		GotoXY(LEFT + 2 * i, TOP + MAP_SIZE);
		printf("※");
	}
	for (int i = -1; i <= MAP_SIZE; i++) {
		GotoXY(0, TOP + i);
		printf("※");
		GotoXY(LEFT + 2 * MAP_SIZE, TOP + i);
		printf("※");
	}
	Snake snake;
	Direction nowD = { 0,1 };
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			Map[i][j] = 0;
	SnakeBody p = snake.head;
	while (p) {
		GotoXY(LEFT + 2 * p->pos.x, TOP + p->pos.y);
		if(p == snake.head)
			printf("○");
		else
			printf("□");
		p = p->next;
	}
	p = snake.head;
	while (p) {
		if(p == snake.head)Map[p->pos.y][p->pos.x] = 2;
		else Map[p->pos.y][p->pos.x] = 1;
		p = p->next;
	}
	CreateFood();
	bool win = false;
	int key;
	while (true) {
		if (_kbhit()) {
			key = GetKey();
			switch (key) {
			case KEY_DOWN:
				if (nowD != Direction(0, -1))
					nowD = { 0,1 };
				break;
			case KEY_UP:
				if (nowD != Direction(0, 1))
					nowD = { 0,-1 };
				break;
			case KEY_LEFT:
				if (nowD != Direction(1, 0))
					nowD = { -1,0 };
				break;
			case KEY_RIGHT:
				if (nowD != Direction(-1, 0))
					nowD = { 1,0 };
				break;
			}
		}
		snake.head->dir = nowD;
		for (SnakeBody p = snake.head->next;p; p = p->next) {
			p->dir = p->prev->pos - p->pos;
		}
		if (Map[snake.head->pos.y + snake.head->dir.y][snake.head->pos.x + snake.head->dir.x] == 1) {
			break;
		}
		if (Map[snake.head->pos.y + snake.head->dir.y][snake.head->pos.x + snake.head->dir.x] == 3) {
			SnakeBody q = new SnakeNode();
			q->dir = snake.tail->dir;
			q->pos = snake.tail->pos - snake.tail->dir;
			q->next = NULL;
			q->prev = snake.tail;
			snake.tail->next = q;
			snake.tail = q;
			snake.length++;
			Map[q->pos.y][q->pos.x] = 1;
			CreateFood();
		}
		if (Map[snake.head->pos.y][snake.head->pos.x] == 1) {
			break;
		}
		MoveSnake(snake);
		PaintSnake(snake);
		if (snake.length == MAP_SIZE * MAP_SIZE - 1) {
			win = true;
			break;
		}
		if (snake.head->pos.x < 0 || snake.head->pos.x >= MAP_SIZE || snake.head->pos.y < 0 || snake.head->pos.y >= MAP_SIZE) {
			break;
		}
		Sleep(200);
	}
}