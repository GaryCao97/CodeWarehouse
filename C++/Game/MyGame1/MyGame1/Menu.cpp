#include "stdafx.h"
#include "Arr.h"
#include "Func.h"
#include "Menu.h"

void WindowsProperty() {
	ClearScreen();
	short w = 100, h = 40;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { w, h }); // 重新设置缓冲区大小
	SMALL_RECT rc = { 0,0, w - 1, h - 1 }; // 重置窗口位置和大小
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
	HideCursor();
}

void Start() {
	int y = 19;
	char *str;
	str = "倒计时3秒后开始游戏";
	PrintWordCenter(y, str);
	Sleep(1000);
	int t = 3;
	ClearScreen();
	while (t) {
		str = new char(2);
		sprintf_s(str, 2, "%d", t--);
		PrintWordCenter(y, str);
		Sleep(1000);
		ClearLine(y);
	}
}

void Create(PlayerCharacter &pc) {
	int y;
	string str;
	y = 10;
	str = "在一个不明所以的日子里，";
	PrintWordCenter(y, str);
	Sleep(1000);
	y += 2;
	str = "风雨交加，电闪雷鸣，";
	PrintWordCenter(y, str);
	Sleep(1000);
	y += 2;
	str = "你，一个                ";
	PrintWordCenter(y, str);
	Sleep(1000);

	//性别选择
	TablePrint(y, 2, 10, SexY);
	COORD crPos;
	int choice = 0;
	while (1) {
		crPos = getxy();
		choice = (crPos.Y - y) / 2;
		if (choice > 0 && choice < 3)
			break;
	}
	for (int i = y + 1, j = 1; j <= 5; j++, i++) {
		ClearLine(i);
	}
	pc.Property.Sex = choice - 1;
	str = SexE[choice - 1];
	PrintWordCenter(y, str);
	str = "，出身于";
	printf_s("%s", str.c_str());
	Sleep(1000);


	//出身选择
	TablePrint(y, 4, 20, Origin);
	choice = 0;
	while (1) {
		crPos = getxy();
		choice = (crPos.Y - y) / 2;
		if (choice > 0 && choice < 5)
			break;
	}
	for (int i = y + 1, j = 1; j <= 9; j++, i++) {
		ClearLine(i);
	}
	pc.Property.Origin = choice - 1;
	y += 2;
	str = Origin[choice - 1];
	PrintWordCenter(y, str);
	Sleep(1000);

	//输入姓名
	y += 2;
	str = "请输入你的名字：";
	PrintWordCenter(y, str);
	Sleep(1000);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	gotoxy((short)(bInfo.dwSize.X - str.length()) / 2, y + 2);
	cin >> str;
	strcpy(pc.Name, str.c_str());
	pc.PropertyInit();
	pc.UpdateProperty();
	pc.Consumables.Contribution = 0;
	pc.Consumables.Lingshi = 0;
	pc.Consumables.Spirit = 0;
}

void PrintMenpai(PlayerCharacter pc) {
	if (pc.Property.Menpai == -1) {
		printf("无门派");
	}
	else {
		cout << Menpai[pc.Property.Menpai];
	}
}
void PrintMaster(PlayerCharacter pc) {
	if (pc.Property.Master == -1) {
		printf("无");
	}
	else {
		cout << Master[pc.Property.Menpai][pc.Property.Master].name;
	}
}

GamePlace MainMenu(PlayerCharacter &pc) {
	ClearScreen();
	int startY = 5, y = startY;
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	//设置和推出
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━┓┏━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                ┃┃                ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("设置");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("退出");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━┛┗━━━━━━━━┛");

	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "姓名：" << pc.Name;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	PrintMenpai(pc);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "生命值：" << pc.Property.HP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "能量值：" << pc.Property.MP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "精神值：" << pc.Property.SP;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "年龄：" << AgeToWord(pc.Property.Age);
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "缘分：" << pc.Property.Fate;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "师父：";
	PrintMaster(pc);
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "经验：" << pc.Property.Exp;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "精气神：" << pc.Consumables.Spirit;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "等级：" << pc.Property.Level;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "灵石：" << pc.Consumables.Lingshi;

	//挂机键
	int btnY = y;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                                    ┃");
	PrintWordCenter(y - 1, "挂机");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━━━━━━━━━━━┛");

	// 洪荒和门派
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━┓┏━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                ┃┃                ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("洪荒");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("门派");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━┛┗━━━━━━━━┛");

	// 属性和背包
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━┓┏━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                ┃┃                ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("属性");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("背包");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━┛┗━━━━━━━━┛");

	COORD crPos;
	GamePlace choice = MAIN_MENU;
	while (1) {
		crPos = getxy();
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			choice = SETTING;
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = EXIT;
		if (crPos.Y >= btnY && crPos.Y <= btnY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = HANGING;
		if (crPos.Y >= btnY + 3 && crPos.Y <= btnY + 5 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			choice = HONGHUANG;
		if (crPos.Y >= btnY + 3 && crPos.Y <= btnY + 5 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = SCHOOL;
		if (crPos.Y >= btnY + 6 && crPos.Y <= btnY + 8 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			choice = PROPERTY;
		if (crPos.Y >= btnY + 6 && crPos.Y <= btnY + 8 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = BACKPACK;
		if (choice != MAIN_MENU)break;
	}
	return choice;
}

GamePlace SettingMenu(PlayerCharacter & pc) {
	ClearScreen();
	int startY = 10, y = startY;
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	//重置键
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                                    ┃");
	PrintWordCenter(y - 1, "返回游戏");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━━━━━━━━━━━┛");
	//重置键
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                                    ┃");
	PrintWordCenter(y - 1, "重置游戏");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━━━━━━━━━━━┛");
	//退出键
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                                    ┃");
	PrintWordCenter(y - 1, "退出游戏");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━━━━━━━━━━━┛");

	COORD crPos;
	GamePlace choice = SETTING;
	while (1) {
		crPos = getxy();
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = MAIN_MENU;
		if (crPos.Y >= startY + 3 && crPos.Y <= startY + 5 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = RESTART;
		if (crPos.Y >= startY + 6 && crPos.Y <= startY + 8 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = EXIT;
		if (choice != SETTING)break;
	}
	return choice;
}

void PrintProperty1(PlayerCharacter pc, int y) {
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	for (int i = y; i < bInfo.dwSize.Y; i++)
		ClearLine(i);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "姓名：" << pc.Name;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	PrintMenpai(pc);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "生命值：" << pc.Property.HP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "能量值：" << pc.Property.MP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "精神值：" << pc.Property.SP;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "年龄：" << AgeToWord(pc.Property.Age);
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "缘分：" << pc.Property.Fate;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "师父：";
	PrintMaster(pc);
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "力量：" << pc.Property.Str;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "敏捷：" << pc.Property.Dex;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "体质：" << pc.Property.Con;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "智力：" << pc.Property.Int;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "根骨：" << pc.Property.Qualification;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "悟性：" << pc.Property.Perception;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "气运：" << pc.Property.Fortunate;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "经验：" << pc.Property.Exp;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "精气神：" << pc.Consumables.Spirit;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "等级：" << pc.Property.Level;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "灵石：" << pc.Consumables.Lingshi;
}
void PrintProperty2(PlayerCharacter pc, int y) {
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	for (int i = y; i < bInfo.dwSize.Y; i++)
		ClearLine(i);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "攻击力：" << pc.Property.Attack;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "攻击力系数：" << pc.AbilityNum.AttackNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "防御力：" << pc.Property.Defence;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "防御力系数：" << pc.AbilityNum.DefenceNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "命中：" << pc.Property.Hit;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "命中系数：" << pc.AbilityNum.HitNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "闪避：" << pc.Property.Dodge;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "闪避系数：" << pc.AbilityNum.DodgeNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "格挡：" << pc.Property.Block;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "格挡系数：" << pc.AbilityNum.BlockNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "攻速：" << pc.Property.attackSpeed;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "攻速系数：" << pc.AbilityNum.attackSpeedNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "生命值系数：" << pc.AbilityNum.HPNum;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "能量值系数：" << pc.AbilityNum.MPNum;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "功德值：" << pc.Property.Merit;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "威望：" << pc.Property.Prestige;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "魅力值：" << pc.Property.Charm;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "转生次数：" << pc.Property.Incarnations;
}

GamePlace PropertyMenu(PlayerCharacter & pc) {
	ClearScreen();
	int startY = 5, y = startY;
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	//设置和返回
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━┓┏━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                ┃┃                ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("返回");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("设置");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━┛┗━━━━━━━━┛");

	//属性页切换
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━┓┏━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┃                ┃┃                ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 5, y - 1);
	printf("基本属性");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 7, y - 1);
	printf("能力属性");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━┛┗━━━━━━━━┛");

	//属性列表
	PrintProperty1(pc, y);

	COORD crPos;
	GamePlace choice = PROPERTY;
	while (1) {
		crPos = getxy();
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			choice = MAIN_MENU;
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = SETTING;
		if (crPos.Y >= startY + 3 && crPos.Y <= startY + 5 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			PrintProperty1(pc, y);
		if (crPos.Y >= startY + 3 && crPos.Y <= startY + 5 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			PrintProperty2(pc, y);
		if (choice != PROPERTY)break;
	}
	return choice;
}

GamePlace MenpaiMenu(PlayerCharacter & pc) {
	ClearScreen();
	int startY = 5, y = startY;
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	//设置和返回
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y);
	printf("┃                                    ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 2 - 2, y++);
	printf("返回");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("┗━━━━━━━━━━━━━━━━━━┛");
	COORD crPos;
	GamePlace choice = SCHOOL;
	int menpaiNum = -1;

	//1.选择师门
	if (pc.Property.Menpai == -1) {
		TablePrint(y - 1, 6, MENU_WIDTH / 2, Menpai);
		while (1) {
			crPos = getxy();
			if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
				choice = MAIN_MENU;
			if (crPos.Y >= startY + 3 && crPos.Y < y + 6 * 2 - 1 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2) {
				menpaiNum = (crPos.Y - startY - 3) / 2;
				break;
			}
			if (choice != SCHOOL)break;
		}
		if (choice != SCHOOL)return choice;
		else pc.Property.Menpai = menpaiNum;
	}
	for (int i = startY + 3; i < bInfo.dwSize.Y; i++)
		ClearLine(i);
	//2.进入师门
	//┏━┳━┓
	//┃  ┃  ┃
	//┣━╋━┫
	//┃  ┃  ┃
	//┗━┻━┛
	y = startY + 3;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("┏━━━━━┳━━━━━┳━━━━━┓");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("┃          ┃          ┃          ┃");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("┗━━━━━┻━━━━━┻━━━━━┛");

	while (1) {
		crPos = getxy();
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2 - 20)
			choice = MAIN_MENU;
		if (crPos.Y >= startY && crPos.Y <= startY + 2 && crPos.X >= (bInfo.dwSize.X - MENU_WIDTH) / 2 + 20 && crPos.X <= (bInfo.dwSize.X + MENU_WIDTH) / 2)
			choice = SETTING;
		if (choice != SCHOOL)break;
	}
	return choice;
}

