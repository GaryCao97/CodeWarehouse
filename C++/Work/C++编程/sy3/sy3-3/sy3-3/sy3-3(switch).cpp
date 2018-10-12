#include <iostream>
using namespace std;
int main()
{
	cout << "请输入您的成绩：";
	int grade;	
loop:
	cin >> grade;
	if (grade > 100 || grade < 0) {cout << "输入数据错误！请重新输入：";goto loop;}
	switch (grade / 10)
	{
	case 10:
	case 9:	cout << "你的成绩为A级！" << endl;break;
	case 8:	cout << "你的成绩为B级！" << endl;break;
	case 7:	cout << "你的成绩为C级！" << endl;break;
	case 6:	cout << "你的成绩为D级！" << endl;break;
	default:cout << "你的成绩为E级！" << endl;
		break;
	}
	cout << "请再次输入您的成绩：";
	goto loop;
	return 0;
}