#pragma once
#include "MyPlayer.h"
void WindowsProperty();
//游戏角色创建
void Start();
void Create(PlayerCharacter &pc);
void PrintMenpai(PlayerCharacter pc);
void PrintMaster(PlayerCharacter pc);
GamePlace MainMenu(PlayerCharacter &pc);
GamePlace SettingMenu(PlayerCharacter &pc);
void PrintProperty1(PlayerCharacter pc, int y);
void PrintProperty2(PlayerCharacter pc, int y);
GamePlace PropertyMenu(PlayerCharacter &pc);
GamePlace MenpaiMenu(PlayerCharacter &pc);
