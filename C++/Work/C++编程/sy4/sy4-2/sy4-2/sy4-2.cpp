#include <iostream>
using namespace std;
int main()
{
	char chars[]="qwertyuiopasdfghjklzxcvbnm";
	char C;
start:
	cout << "������һ���ַ���";
	cin >> C;
	int ordinal;
	for(ordinal = 0;ordinal < 26;ordinal++)
	{
		if (C == chars[ordinal])
		{
			cout << "�ַ�" << C << "���ַ���" << chars << "�еĵ�" << ordinal + 1 << "���ַ�" << endl;
			break;
		}
	}
	if (ordinal == 26) cout << "�ַ�" << C << "�������ַ���" << chars << "�е��ַ�" << endl;
	goto start;
	return 0;
}