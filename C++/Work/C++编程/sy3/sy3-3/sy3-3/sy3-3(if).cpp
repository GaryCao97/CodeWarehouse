#include <iostream>
using namespace std;
int main()
{
	cout << "���������ĳɼ���";
	int grade;
loop :
	cin >> grade;
	if (grade > 100 || grade < 0) {cout << "�������ݴ������������룺";goto loop;}
	else if (grade >= 90 && grade <= 100) {cout << "��ĳɼ�ΪA����" << endl;}
	else if (grade >= 80 && grade < 90) {cout << "��ĳɼ�ΪB����" << endl;}
	else if (grade >= 70 && grade < 80) {cout << "��ĳɼ�ΪC����" << endl;}
	else if (grade >= 60 && grade < 70) {cout << "��ĳɼ�ΪD����" << endl;}
	else if (grade >= 0 && grade < 60) {cout << "��ĳɼ�ΪE����" << endl;}
	cout << "���ٴ��������ĳɼ���";
	goto loop;
	return 0;
}