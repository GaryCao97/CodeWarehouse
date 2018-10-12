#pragma once

//------------------����̨����------------------------
void GotoXY(short x, short y);//����ƶ�
void HideCursor();
void ClearScreen(); // ����

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