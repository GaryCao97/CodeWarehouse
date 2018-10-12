#pragma once

//------------------控制台函数------------------------
void GotoXY(short x, short y);//光标移动
void HideCursor();
void ClearScreen(); // 清屏

//--------------------------------------------------
void Create(RandomMap rMap, int m, int n);
void MapRoadCreate(RandomMap rMap);
void InitMap(RandomMap rMap);
void PaintMapPoint(RandomMap rMap, int x, int y);
void PaintPC(PlayerCharacter pc);
void Move(RandomMap rMap, PlayerCharacter &pc, int x, int y);
int GetChoice(RandomMap rMap, PlayerCharacter pc, int size);
void ChangeInfo(RandomMap rMap, PlayerCharacter pc);
void ClearNPCInfo();
void GamePlaying(PlayerCharacter &pc);