#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
//---------------------------------------------
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
#define TOP 1
#define LEFT (2 * TOP)
#define MAX_SIZE 40
#define MENU_HEIGHT 40
#define RANDOM(min, max) ((min) + (rand()%((max) - (min) + 1)))
#define ROAD 0
#define WALL 1
#define NPC (2 + rand() % 5)

typedef struct PlayerCharacter {
	int x, y;
	char *PC;
	PlayerCharacter() {
		PC = "¡ñ";
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
//extern int Map[MAP_SIZE][MAP_SIZE];//0 ¿Õ 1 Ç½ 2-6 NPC
//extern int MapWidth, MapHeight;
