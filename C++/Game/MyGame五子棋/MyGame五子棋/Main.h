#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#define LEFT_CLICK FROM_LEFT_1ST_BUTTON_PRESSED
#define RIGHT_CLICK RIGHTMOST_BUTTON_PRESSED

typedef int GameState;
#define PLAYING 0
#define BLACKWIN 1
#define WHITEWIN 2
#define BLACK 1
#define WHITE 2