#include <Windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
using namespace std;

//----------�������--------
int fx[4][4] = {
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};
//�����Ƿ���
int lx1[4][4] = {
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};

int lx2[4][4] = {
	{ 0,0,0,0 },
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
};

int lx3[4][4] = {
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,1,0 }
};

int lx4[4][4] = {
	{ 0,0,0,0 },
	{ 0,0,1,0 },
	{ 1,1,1,0 },
	{ 0,0,0,0 }
};
//������L��
int jx1[4][4] = {
	{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,0,0,0 }
};

int jx2[4][4] = {
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 }
};

int jx3[4][4] = {
	{ 0,0,0,0 },
	{ 1,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,0 }
};

int jx4[4][4] = {
	{ 0,0,1,0 },
	{ 0,0,1,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};
//������J��
int sx1[4][4] = {
	{ 0,0,0,0 },
	{ 0,0,1,1 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};

int sx2[4][4] = {
	{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,0 }
};
//������S��
int zx1[4][4] = {
	{ 0,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};

int zx2[4][4] = {
	{ 0,0,1,0 },
	{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
};
//������Z��
int tx1[4][4] = {
	{ 1,1,1,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};

int tx2[4][4] = {
	{ 0,0,1,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,0 }
};

int tx3[4][4] = {
	{ 0,0,0,0 },
	{ 0,0,1,0 },
	{ 0,1,1,1 },
	{ 0,0,0,0 }
};

int tx4[4][4] = {
	{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
};
//������T��
int ix1[4][4] = {
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 }
};

int ix2[4][4] = {
	{ 0,0,0,0 },
	{ 1,1,1,1 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};
//������I��

//----------��غ���--------
void WindowChange();
void GotoXY(short x, short y);//����ƶ�
void HideCursor();//���ع��
int GetKey();
void Gaming();

int main() {
	WindowChange();
	srand((unsigned int)time(0));
	HideCursor();
	Gaming();
	return 0;
}

void WindowChange() {
	char str[50];
	sprintf_s(str, 50, "MODE con: COLS=%d LINES=%d", MAP_SIZE * 2 + 4 + MENU_WIDTH, MAP_SIZE + 2);
	system(str);
}
void GotoXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int GetKey() {
	int c1, c2;
	if ((c1 = _getch()) != 224)return c1;
	c2 = _getch();
	return c2;
}