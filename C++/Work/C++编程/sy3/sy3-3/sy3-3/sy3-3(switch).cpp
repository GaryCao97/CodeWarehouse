#include <iostream>
using namespace std;
int main()
{
	cout << "���������ĳɼ���";
	int grade;	
loop:
	cin >> grade;
	if (grade > 100 || grade < 0) {cout << "�������ݴ������������룺";goto loop;}
	switch (grade / 10)
	{
	case 10:
	case 9:	cout << "��ĳɼ�ΪA����" << endl;break;
	case 8:	cout << "��ĳɼ�ΪB����" << endl;break;
	case 7:	cout << "��ĳɼ�ΪC����" << endl;break;
	case 6:	cout << "��ĳɼ�ΪD����" << endl;break;
	default:cout << "��ĳɼ�ΪE����" << endl;
		break;
	}
	cout << "���ٴ��������ĳɼ���";
	goto loop;
	return 0;
}