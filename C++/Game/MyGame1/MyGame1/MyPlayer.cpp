
#include "stdafx.h"
#include "Func.h"
#include "MyPlayer.h"

PlayerCharacter::PlayerCharacter() {
	ifstream inf("Player.txt", ios_base::binary);
	//加入如果打开失败。。。
	if(inf.is_open()){
		inf.read(reinterpret_cast<char*>(&Name), sizeof(Name));
		inf.read(reinterpret_cast<char*>(&Property), sizeof(Property));
		inf.read(reinterpret_cast<char*>(&AbilityNum), sizeof(AbilityNum));
		inf.read(reinterpret_cast<char*>(&Consumables), sizeof(Consumables));
		//inf.read(reinterpret_cast<char*>(&isNew), sizeof(isNew));
		isNew = false;
	}
	else {
		isNew = true;
	}
	inf.close();
}
PlayerCharacter::~PlayerCharacter() {
	ofstream outf("Player.txt", ios_base::binary | ios_base::trunc);
	if(outf.is_open()){
		outf.write(reinterpret_cast<char*>(&Name), sizeof(Name));
		outf.write(reinterpret_cast<char*>(&Property), sizeof(Property));
		outf.write(reinterpret_cast<char*>(&AbilityNum), sizeof(AbilityNum));
		outf.write(reinterpret_cast<char*>(&Consumables), sizeof(Consumables));
		outf.write(reinterpret_cast<char*>(&isNew), sizeof(isNew));
	}
	outf.close();
}

void PlayerCharacter::PropertyInit() {
	Property.Qualification = RANDOM(15, 25);
	Sleep(10);
	Property.Perception = RANDOM(15, 25);
	Sleep(10);
	Property.Fortunate = 60 - Property.Qualification - Property.Perception;
	Property.Str = RANDOM(10, 20);
	Sleep(10);
	Property.Dex = RANDOM(10, 20);
	Sleep(10);
	Property.Con = RANDOM(10, 20);
	Sleep(10);
	Property.Int = RANDOM(10, 20);
	Property.Age = 12;
	Property.Exp = 1;
	Property.Level = 1;
	Property.Merit = 0;//功德值/业力值
	Property.Prestige = 0;//威望
	Property.Charm = 0;//魅力值
	Property.Menpai = -1;
	Property.Master = -1;//师父
	Property.Incarnations = 0;//转生次数
	strcpy(Property.Fate, "  ");
	AbilityNum.AttackNum = 10;
	AbilityNum.DefenceNum = 10;
	AbilityNum.HitNum = 10;
	AbilityNum.DodgeNum = 10;
	AbilityNum.BlockNum = 10;
	AbilityNum.attackSpeedNum = 10;
	AbilityNum.HPNum = 10;
	AbilityNum.MPNum = 10;
	UpdateProperty();
}

void PlayerCharacter::UpdateProperty() {
	Property.Attack = AbilityNum.AttackNum * (Property.Str + Property.Int) * 5;
	Property.Defence = AbilityNum.DefenceNum * (Property.Con + Property.Str + Property.Int);
	Property.Hit = AbilityNum.HitNum * Property.Dex / 100;
	Property.Dodge = AbilityNum.DodgeNum * Property.Dex / 100;
	Property.Block = AbilityNum.BlockNum * Property.Dex / 100;
	Property.attackSpeed = AbilityNum.attackSpeedNum * Property.Dex / 100;
	Property.HP = AbilityNum.HPNum * Property.Con;
	Property.MP = AbilityNum.MPNum * Property.Int;
	Property.SP = ((int)(Property.Age / 1296) + Property.Con + Property.Int) * 10;
}
