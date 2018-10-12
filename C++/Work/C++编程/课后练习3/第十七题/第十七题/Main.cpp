#include <iostream>
#include <cstdlib>
#include <conio.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define UP 0x4800
#define DOWN 0x5000
using namespace std;
char qipan[19][39] = {
	"┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┣╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┫",
	"┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛"
};
int x = 0, y = 0;
void Start()
{
	cout << "五子棋" << endl;
	cout << "黑棋按左右上下方向键移动棋子" << endl
		<< "按回车键确定落棋子" << endl 
		<< "白棋按wsad/WSAD键移动棋子" << endl
		<< "按空格键确定落棋子" << endl
		<< "禁止在棋盘外按空格" << endl
		<< "你是否接受上述的游戏规则（Y / N） 如果输入 Y，才可以进行游戏，进入正式的游戏界面." << endl;
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
	cout << "现在轮到黑方" << endl;
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
			if (qipan[x][y] == '●' || qipan[x][y] == '○')
				cout << "不能在此下子！" << endl;
			else
				qipan[x][y] = '●';
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
	cout << "现在轮到白方" << endl;
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
			if (qipan[x][y] == '●' || qipan[x][y] == '○')
				cout << "不能在此下子！" << endl;
			else
				qipan[x][y] = '○';
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