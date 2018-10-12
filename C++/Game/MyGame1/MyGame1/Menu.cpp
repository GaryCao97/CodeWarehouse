#include "stdafx.h"
#include "Arr.h"
#include "Func.h"
#include "Menu.h"

void WindowsProperty() {
	ClearScreen();
	short w = 100, h = 40;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { w, h }); // �������û�������С
	SMALL_RECT rc = { 0,0, w - 1, h - 1 }; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
	HideCursor();
}

void Start() {
	int y = 19;
	char *str;
	str = "����ʱ3���ʼ��Ϸ";
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
	str = "��һ���������Ե������";
	PrintWordCenter(y, str);
	Sleep(1000);
	y += 2;
	str = "���꽻�ӣ�����������";
	PrintWordCenter(y, str);
	Sleep(1000);
	y += 2;
	str = "�㣬һ��                ";
	PrintWordCenter(y, str);
	Sleep(1000);

	//�Ա�ѡ��
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
	str = "��������";
	printf_s("%s", str.c_str());
	Sleep(1000);


	//����ѡ��
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

	//��������
	y += 2;
	str = "������������֣�";
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
		printf("������");
	}
	else {
		cout << Menpai[pc.Property.Menpai];
	}
}
void PrintMaster(PlayerCharacter pc) {
	if (pc.Property.Master == -1) {
		printf("��");
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
	//���ú��Ƴ�
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                ����                ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("�˳�");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "������" << pc.Name;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	PrintMenpai(pc);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.HP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.MP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.SP;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���䣺" << AgeToWord(pc.Property.Age);
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "Ե�֣�" << pc.Property.Fate;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "ʦ����";
	PrintMaster(pc);
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���飺" << pc.Property.Exp;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������" << pc.Consumables.Spirit;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "�ȼ���" << pc.Property.Level;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "��ʯ��" << pc.Consumables.Lingshi;

	//�һ���
	int btnY = y;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                                    ��");
	PrintWordCenter(y - 1, "�һ�");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

	// ��ĺ�����
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                ����                ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("���");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

	// ���Ժͱ���
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                ����                ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

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
	//���ü�
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                                    ��");
	PrintWordCenter(y - 1, "������Ϸ");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	//���ü�
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                                    ��");
	PrintWordCenter(y - 1, "������Ϸ");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	//�˳���
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                                    ��");
	PrintWordCenter(y - 1, "�˳���Ϸ");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

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
	cout << "������" << pc.Name;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	PrintMenpai(pc);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.HP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.MP;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "����ֵ��" << pc.Property.SP;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���䣺" << AgeToWord(pc.Property.Age);
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "Ե�֣�" << pc.Property.Fate;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "ʦ����";
	PrintMaster(pc);
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "������" << pc.Property.Str;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "���ݣ�" << pc.Property.Dex;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���ʣ�" << pc.Property.Con;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������" << pc.Property.Int;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���ǣ�" << pc.Property.Qualification;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "���ԣ�" << pc.Property.Perception;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	cout << "���ˣ�" << pc.Property.Fortunate;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���飺" << pc.Property.Exp;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������" << pc.Consumables.Spirit;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "�ȼ���" << pc.Property.Level;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "��ʯ��" << pc.Consumables.Lingshi;
}
void PrintProperty2(PlayerCharacter pc, int y) {
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	for (int i = y; i < bInfo.dwSize.Y; i++)
		ClearLine(i);
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "��������" << pc.Property.Attack;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������ϵ����" << pc.AbilityNum.AttackNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "��������" << pc.Property.Defence;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������ϵ����" << pc.AbilityNum.DefenceNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���У�" << pc.Property.Hit;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "����ϵ����" << pc.AbilityNum.HitNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���ܣ�" << pc.Property.Dodge;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "����ϵ����" << pc.AbilityNum.DodgeNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "�񵲣�" << pc.Property.Block;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "��ϵ����" << pc.AbilityNum.BlockNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "���٣�" << pc.Property.attackSpeed;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "����ϵ����" << pc.AbilityNum.attackSpeedNum;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "����ֵϵ����" << pc.AbilityNum.HPNum;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "����ֵϵ����" << pc.AbilityNum.MPNum;
	y++;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "����ֵ��" << pc.Property.Merit;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "������" << pc.Property.Prestige;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y);
	cout << "����ֵ��" << pc.Property.Charm;
	gotoxy((short)(bInfo.dwSize.X) / 2, y++);
	cout << "ת��������" << pc.Property.Incarnations;
}

GamePlace PropertyMenu(PlayerCharacter & pc) {
	ClearScreen();
	int startY = 5, y = startY;
	string str;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bInfo);
	//���úͷ���
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                ����                ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 3, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 5, y - 1);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

	//����ҳ�л�
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("��                ����                ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 4 - 5, y - 1);
	printf("��������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH * 3 / 4 - 7, y - 1);
	printf("��������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");

	//�����б�
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
	//���úͷ���
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y);
	printf("��                                    ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + MENU_WIDTH / 2 - 2, y++);
	printf("����");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2, y++);
	printf("����������������������������������������");
	COORD crPos;
	GamePlace choice = SCHOOL;
	int menpaiNum = -1;

	//1.ѡ��ʦ��
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
	//2.����ʦ��
	//�����ש���
	//��  ��  ��
	//�ǩ��贈��
	//��  ��  ��
	//�����ߩ���
	y = startY + 3;
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("�������������ש����������ש�����������");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("��          ��          ��          ��");
	gotoxy((short)(bInfo.dwSize.X - MENU_WIDTH) / 2 + 1, y++);
	printf("�������������ߩ����������ߩ�����������");

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

