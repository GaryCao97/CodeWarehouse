#include <iostream>
#include <cstdlib>
#include <conio.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define UP 0x4800
#define DOWN 0x5000
using namespace std;
char qipan[19][39] = {
	"���ששששששששששששששששש�",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"�ǩ������������������",
	"���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�"
};
int x = 0, y = 0;
void Start()
{
	cout << "������" << endl;
	cout << "���尴�������·�����ƶ�����" << endl
		<< "���س���ȷ��������" << endl 
		<< "���尴wsad/WSAD���ƶ�����" << endl
		<< "���ո��ȷ��������" << endl
		<< "��ֹ�������ⰴ�ո�" << endl
		<< "���Ƿ������������Ϸ����Y / N�� ������� Y���ſ��Խ�����Ϸ��������ʽ����Ϸ����." << endl;
}
void Paint()
{
	system("cls");
	for (int i = 0; i < 19; i++)
	{
		printf_s("%s\n", qipan[i]);
		
	}
}
void Black_Control()
{
	cout << "�����ֵ��ڷ�" << endl;
	char ch;
	do
	{
		ch = _getch();
		switch (ch)
		{
		case LEFT:
			x -= 2;
			break;
		case RIGHT:
			x += 2;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case 10:
			if (qipan[x][y] == '��' || qipan[x][y] == '��')
				cout << "�����ڴ����ӣ�" << endl;
			else
				qipan[x][y] = '��';
			break;
		}
		Paint();
		if (x < 0)
			x += 2;
		if (x > 39)
			x -= 2;
		if (y < 0)
			y++;
		if (y > 19)
			y--;
		Paint();
	} while (ch != 10);
}
void White_Control()
{
	cout << "�����ֵ��׷�" << endl;
	char ch;
	do
	{
		ch = _getch();
		switch (ch)
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x -= 2;
			break;
		case 'd':
			x += 2;
			break;
		case ' ':
			if (qipan[x][y] == '��' || qipan[x][y] == '��')
				cout << "�����ڴ����ӣ�" << endl;
			else
				qipan[x][y] = '��';
			break;
		}
		Paint();
		if (x < 0)
			x += 2;
		if (x > 39)
			x -= 2;
		if (y < 0)
			y++;
		if (y > 19)
			y--;
		Paint();
	} while (ch != ' ');
}
int Win()
{
	return 0;
}
void main()
{
	cout << qipan[0] ;
	/*Start();
	char input1;
	cin >> input1;
	if (input1 == 'N' || input1 == 'n')
		return;
	do
	{
		Paint();
		do
		{
			Black_Control();
			White_Control();
		} while (1);
	} while (0);*/
}