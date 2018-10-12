#pragma once
#include <vector>
#include "MyPlayer.h"
extern char Table[5][11];
extern string Origin[4];
extern string SexY[2];
extern string SexE[2];
extern string MainChoice[5];
extern string Menpai[MENPAI_NUM];
extern vector<TeacherCharacter> Master[MENPAI_NUM];

void InitMenpaiAndMaster();