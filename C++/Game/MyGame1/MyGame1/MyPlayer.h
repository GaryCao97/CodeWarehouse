#pragma once


typedef struct {
	//天生属性 
	int Qualification;	//根骨 
	int Perception;		//悟性 
	int Fortunate;		//气运 

	//成长属性
	int Str;	//力量 
	int Dex;	//敏捷 
	int Con;	//体质 
	int Int;	//智力 

	//人物衍生属性
	int HP;//气血/生命值
	int MP;//法力/能量值
	int SP;//精神值
	long long Age;//年龄
	int Sex;//性别
	int Exp;//经验
	int Level;//等级
	int Origin;//出身

	//能力属性 
	int Attack;//攻击力
	int Defence;//防御力
	int Hit;//命中
	int Dodge;//闪避
	int Block;//格挡
	int attackSpeed;//攻击速度

	//人物附属属性
	int Merit;//功德值/业力值
	int Prestige;//威望
	int Charm;//魅力值
	char Fate[20];//缘分
	int Menpai;
	int Master;//师父
	int Incarnations;//转生次数
}Pro;

typedef struct {
	//能力系数 
	int AttackNum;
	int DefenceNum;
	int HitNum;
	int DodgeNum;
	int BlockNum;
	int attackSpeedNum;
	int HPNum;
	int MPNum;
}AbNum;

typedef struct {
	//人物消耗值
	int Lingshi;//灵石
	int Contribution;//师门贡献
	int Spirit;//精气神
}Consum;

class PlayerCharacter{
public:
	char Name[20];
	Pro Property;
	AbNum AbilityNum;
	Consum Consumables;
	bool isNew;
	//函数、事件
	PlayerCharacter();
	~PlayerCharacter();
	void PropertyInit();//人物属性初始化
	void UpdateProperty();//更新能力属性
};

class TeacherCharacter {
public:
	string name;
	int skillNum;
	string *skill;
};