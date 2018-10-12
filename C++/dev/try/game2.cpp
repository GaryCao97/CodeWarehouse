#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
#define TOP 1
#define LEFT (2 * TOP)
#define MAX_SIZE 40
#define RANDOM(min, max) ((min) + (rand()%((max) - (min) + 1)))
#define ROAD 0
#define WALL 1
#define END 2
typedef struct PlayerCharacter {
	int x, y;
	char *PC;
	PlayerCharacter() {
		PC = "●";
		x = y = 1;
	}
}PlayerCharacter;
typedef struct RandomMap {
	int **Map;
	int mapW, mapH;
	long mapID;
	RandomMap() {
		mapW = 2 * RANDOM(8, MAX_SIZE / 2) + 1;
		mapH = 2 * RANDOM(5, MAX_SIZE / 2) + 1;
		Map = (int**)malloc(mapH * sizeof(int*));
		for (int i = 0; i < mapH; i++) {
			Map[i] = (int*)malloc(mapW * sizeof(int));
			for (int j = 0; j < mapW; j++)
				Map[i][j] = WALL;
		}
	}
}RandomMap;
void GotoXY(short x, short y);//光标移动
void HideCursor();
void Create(RandomMap rMap, int m, int n);
void InitMap(RandomMap rMap);
void PaintMapPoint(RandomMap rMap, int x, int y);
void GamePlaying(PlayerCharacter &pc);
void PaintPC(PlayerCharacter pc);
void Move(RandomMap rMap, PlayerCharacter &pc, int x, int y);

int main() {
	SYSTEMTIME sys[2];
	system("MODE con: COLS=120 LINES=50");
	srand((unsigned int)time(0));
	HideCursor();
	PlayerCharacter pc;
	GetLocalTime(&sys[0]);
	GamePlaying(pc);
	GetLocalTime(&sys[1]);
	int mm = sys[1].wMinute - sys[0].wMinute, ss = sys[1].wSecond - sys[0].wSecond;
	if (ss < 0) {
		ss += 60;
		mm -= 1;
	}
	else if (ss > 59) {
		ss -= 60;
		mm += 1;
	}
	printf("\n好牛逼啊，走出迷宫只花了%2d:%2d的时间！\n", mm, ss);
	return 0;
}

void GotoXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
bool CheckBorder(RandomMap rMap, int x, int y) {
	if (x <= 0 || y <= 0 || x >= rMap.mapW - 1 || y >= rMap.mapH - 1)return true;
	else return false;
}
bool CheckOutside(RandomMap rMap, int x, int y) {
	if (x < 0 || y < 0 || x > rMap.mapW - 1 || y > rMap.mapH - 1)return false;
	else return true;
}
void Create(RandomMap rMap, int m, int n) {
	int next[4][2] = {
		{ 0,1 },
		{ 1,0 },
		{ 0,-1 },
		{ -1,0 }
	};
	int i, j, t;
	for (i = 0; i<4; i++) {
		j = rand() % 4;
		t = next[i][0], next[i][0] = next[j][0], next[j][0] = t;
		t = next[i][1], next[i][1] = next[j][1], next[j][1] = t;
	}
	rMap.Map[m][n] = ROAD;
	for (i = 0; i<4; i++)
		if (!CheckBorder(rMap, n + 2 * next[i][1], m + 2 * next[i][0]) && rMap.Map[m + 2 * next[i][0]][n + 2 * next[i][1]] == WALL) {
			rMap.Map[m + next[i][0]][n + next[i][1]] = ROAD;
			Create(rMap, m + 2 * next[i][0], n + 2 * next[i][1]);
		}
}
void InitMap(RandomMap rMap) {
	Create(rMap, 1, 1);
	rMap.Map[rMap.mapH - 2][rMap.mapW - 2] = END;
	for (int i = 0; i < rMap.mapW; i++) {
		for (int j = 0; j < rMap.mapH; j++) {
			PaintMapPoint(rMap, i, j);
		}
	}
}
void PaintMapPoint(RandomMap rMap, int x, int y) {
	GotoXY(x * 2 + LEFT, y + TOP);
	switch (rMap.Map[y][x]) {
	case 0:
		printf("  ");
		break;
	case 1:
		printf("※");
		break;
	case 2:
		printf(" E");
		break;
	}
}
void PaintPC(PlayerCharacter pc) {
	GotoXY(pc.x * 2 + LEFT, pc.y + TOP);
	printf("%s", pc.PC);
}
void Move(RandomMap rMap, PlayerCharacter &pc, int x, int y) {
	PaintMapPoint(rMap, pc.x, pc.y);
	pc.x += x;
	pc.y += y;
	PaintPC(pc);
}
void GamePlaying(PlayerCharacter &pc) {
	RandomMap rm;
	InitMap(rm);
	PaintPC(pc);
	int x, y;
	while (pc.x != rm.mapW - 2 || pc.y != rm.mapH - 2) {
		x = 0;
		y = 0;
		if (KEYDOWN(VK_UP)) {
			y--;
		}
		if (KEYDOWN(VK_DOWN)) {
			y++;
		}
		if (KEYDOWN(VK_LEFT)) {
			x--;
		}
		if (KEYDOWN(VK_RIGHT)) {
			x++;
		}
		if (x || y)
			if (CheckOutside(rm, pc.x + x, pc.y + y) && rm.Map[pc.y + y][pc.x + x] != WALL) {
				Move(rm, pc, x, y);
			}
		Sleep(100);
	}
	GotoXY(LEFT, rm.mapH + TOP);
}


