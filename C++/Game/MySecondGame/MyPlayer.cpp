#include "Setting.h"
#include "MyPlayer.h"
#include "stdafx.h"

void PlayerCharacter::PropertyInit() {
	Qualification = Random(10, 20);
	Perception = Random(10, 20);
	Fortunate = 50 - Qualification - Perception;
	Str = Random(5, 20);
	Dex = Random(5, 20);
	Con = Random(5, 20);
	Int = Random(5, 20);
	Age = 12;
	Exp = 1;
	Level = 1;
	AttackNum = 10;
	DefenceNum = 10;
	HitNum = 10;
	DodgeNum = 10;
	BlockNum = 10;
	attackSpeedNum = 10;
	HPNum = 10;
	MPNum = 10;
	UpdateProperty();
}

void PlayerCharacter::UpdateProperty() {
	Attack = AttackNum * (Str + Int) * 5;
	Defence = DefenceNum * (Con + Str + Int);
	Hit = HitNum * Dex / 100;
	Dodge = DodgeNum * Dex / 100;
	Block = BlockNum * Dex / 100;
	attackSpeed = attackSpeedNum * Dex / 100;
	HP = HPNum * Con;
	MP = MPNum * Int;
	SP = ((int)(Age / 1296) + Con + Int) * 10;
}
