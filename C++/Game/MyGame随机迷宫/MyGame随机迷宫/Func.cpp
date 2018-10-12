
#include "Main.h"
#include "Func.h"

void GotoXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void ClearScreen() {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	DWORD d;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	COORD home = { 0, 0 };
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputCharacterW(GetStdHandle(STD_OUTPUT_HANDLE), 0, size, home, &d);
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
void MapRoadCreate(RandomMap rMap) {
	Create(rMap, 1, 1);
}
void InitMap(RandomMap rMap) {
	MapRoadCreate(rMap);
	for (int i = 0; i < 10; i++) {
		int x = 1 + rand() % (rMap.mapH - 2);
		int y = 1 + rand() % (rMap.mapW - 2);
		rMap.Map[x][y] = NPC;
	}
	for (int i = 0; i < rMap.mapW; i++) {
		for (int j = 0; j < rMap.mapH; j++) {
			//printf("%d ", Map[i][j]);
			PaintMapPoint(rMap, i, j);
		}
	}
	//Sleep(2000000);
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
	default:
		printf("○");
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
int GetChoice(RandomMap rMap, PlayerCharacter pc, int size) {
	int beginX = LEFT + MAX_SIZE * 2 + 8, beginY = TOP + (MENU_HEIGHT / 2) + 7, order = 0;
	for (int i = 0; i < size; i++) {
		GotoXY(beginX + 3, beginY + 2 * i);
		printf("选择%d", i);
	}
	while (true) {
		GotoXY(beginX, beginY + order * 2);
		printf("  ");
		if (KEYDOWN(VK_UP))
			order --;
		if (KEYDOWN(VK_DOWN))
			order ++;
		if (KEYDOWN(VK_ESCAPE)) {
			order = -1;
			break;
		}
		if (KEYDOWN(VK_SPACE)) 
			break;
		if (order < 0)order = 0;
		if (order >= size)order = size - 1;
		GotoXY(beginX, beginY + order * 2);
		printf("→");
		Sleep(100);
	}
	for (int i = 0; i < size; i++) {
		GotoXY(beginX + 3, beginY + 2 * i);
		printf("     ");
	}
	return order;
}
void ChangeInfo(RandomMap rMap, PlayerCharacter pc) {
	static bool isFirst = true;
	int Kind = rMap.Map[pc.y][pc.x];
	int startX = LEFT + MAX_SIZE * 2 + 4, startY = TOP;
	if (isFirst) {
		for (int i = 0; i < MENU_HEIGHT; i++) {
			GotoXY(startX, startY + i);
			if (i == 0)printf("┏━━━━━━━━━━┓");
			else if (i == MENU_HEIGHT - 1)printf("┗━━━━━━━━━━┛");
			else if (i == (MENU_HEIGHT / 2 + 1))printf("┣━━━━━━━━━━┫");
			else printf("┃                    ┃");
		}
		isFirst = false;
	}
	else {
		ClearNPCInfo();
		switch (Kind) {
		case 2:
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 2);
			printf("NPC:商店01");
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 3);
			printf("介绍：很长的介绍");
			break;
		case 3:
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 2);
			printf("NPC:商店02");
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 3);
			printf("介绍：很长的介绍");
			break;
		case 4:
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 2);
			printf("NPC:商店03");
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 3);
			printf("介绍：很长的介绍");
			break;
		case 5:
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 2);
			printf("NPC:商店04");
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 3);
			printf("介绍：很长的介绍");
			break;
		case 6:
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 2);
			printf("NPC:商店05");
			GotoXY(startX + 4, startY + (MENU_HEIGHT / 2) + 3);
			printf("介绍：很长的介绍");
			break;
		default:
			break;
		}
		switch (Kind) {
		case 1:
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			GetChoice(rMap, pc, 4);
			break;
		default:
			break;
		}
	}
}
void ClearNPCInfo() {
	int startX = LEFT + MAX_SIZE * 2 + 4, startY = TOP;
	for (int i = (MENU_HEIGHT / 2 + 2); i < MENU_HEIGHT - 1; i++) {
		GotoXY(startX + 2, startY + i);
		printf("                   ");
	}
}
void GamePlaying(PlayerCharacter &pc) {
	RandomMap rm;
	InitMap(rm);
	PaintPC(pc);
	ChangeInfo(rm, pc);
	int x, y;
	while (true) {
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
				ChangeInfo(rm, pc);
			}
		Sleep(100);
	}
}