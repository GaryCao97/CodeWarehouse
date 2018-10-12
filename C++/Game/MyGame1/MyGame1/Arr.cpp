#include "stdafx.h"
#include "Arr.h"

char Table[5][11] = {
	"┏━┳━┓" ,
	"┃  ┃  ┃" ,
	"┣━╋━┫" ,
	"┃  ┃  ┃" ,
	"┗━┻━┛"
	//┏━┳━┓
	//┃  ┃  ┃
	//┣━╋━┫
	//┃  ┃  ┃
	//┗━┻━┛
};
string Origin[4] = {
	"不知道的出身1",
	"不知道的出身2",
	"不知道的出身3",
	"不知道的出身4"
};
string SexY[2] = {
	"性别：男",
	"性别：女"
};
string SexE[2] = {
	"无名小辈",
	"无名女子"
};
string Menpai[MENPAI_NUM];
vector<TeacherCharacter> Master[MENPAI_NUM];


void InitMenpaiAndMaster() {
	Menpai[0] = "人教";
	Menpai[1] = "阐教";
	Menpai[2] = "截教";
	Menpai[3] = "天庭";
	Menpai[4] = "地府";
	Menpai[5] = "佛教";
	Menpai[6] = "？？";
	Menpai[7] = "紫霄宫";
	Menpai[8] = "五庄观";
	Menpai[9] = "魔教";
	TeacherCharacter tmp;
	//人教
	tmp.name = "太上老君";
	Master[0].push_back(tmp);
	tmp.name = "玄都";
	Master[0].push_back(tmp);
	//阐教
	tmp.name = "元始天尊";
	Master[1].push_back(tmp);
	//截教
	tmp.name = "通天教主";
	Master[2].push_back(tmp);
	//天庭
	tmp.name = "女娲";
	Master[3].push_back(tmp);
	//地府
	tmp.name = "后土";
	Master[4].push_back(tmp);
	//佛教
	tmp.name = "接引";
	Master[5].push_back(tmp);
	tmp.name = "准提";
	Master[5].push_back(tmp);
	//？？
	tmp.name = "扬眉";
	Master[6].push_back(tmp);
	//紫霄宫
	tmp.name = "鸿钧";
	Master[7].push_back(tmp);
	//五庄观
	tmp.name = "镇元子";
	Master[8].push_back(tmp);
	//魔教
	tmp.name = "罗睺";
	Master[9].push_back(tmp);
}