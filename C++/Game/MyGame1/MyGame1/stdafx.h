#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

//---------------键盘按下与弹起事件的判断------------------------------
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#define RANDOM(min,max) (min + rand()%(max - min + 1))
#define MENPAI_NUM 10
#define MENU_WIDTH 40

typedef enum {
	RESTART = -2,
	EXIT = -1,
	MAIN_MENU = 0,
	SETTING,
	HANGING,
	BACKPACK,
	PROPERTY,
	SCHOOL,
	HONGHUANG,
}GamePlace;