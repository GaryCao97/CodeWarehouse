#include <iostream>
using namespace std;
int main()
{
	char chars[]="qwertyuiopasdfghjklzxcvbnm";
	char C;
start:
	cout << "请输入一个字符：";
	cin >> C;
	int ordinal;
	for(ordinal = 0;ordinal < 26;ordinal++)
	{
		if (C == chars[ordinal])
		{
			cout << "字符" << C << "是字符串" << chars << "中的第" << ordinal + 1 << "个字符" << endl;
			break;
		}
	}
	if (ordinal == 26) cout << "字符" << C << "不是是字符串" << chars << "中的字符" << endl;
	goto start;
	return 0;
}