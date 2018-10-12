#include <iostream>
using namespace std;
int main()
{
	cout << "请输入您的成绩：";
	int grade;
loop :
	cin >> grade;
	if (grade > 100 || grade < 0) {cout << "输入数据错误！请重新输入：";goto loop;}
	else if (grade >= 90 && grade <= 100) {cout << "你的成绩为A级！" << endl;}
	else if (grade >= 80 && grade < 90) {cout << "你的成绩为B级！" << endl;}
	else if (grade >= 70 && grade < 80) {cout << "你的成绩为C级！" << endl;}
	else if (grade >= 60 && grade < 70) {cout << "你的成绩为D级！" << endl;}
	else if (grade >= 0 && grade < 60) {cout << "你的成绩为E级！" << endl;}
	cout << "请再次输入您的成绩：";
	goto loop;
	return 0;
}