#include <iostream>
using namespace std;
int main()
{
	cout << "请输入一个字符，按回车键确定" << endl;
loop:
	char a;
	a = getchar();
	if (a >= 48 && a <= 57) cout<<"您输入了一个数字"<<a<<endl;
	else if (a >= 65 && a <= 90) cout<<"您输入了一个大写字母"<<a<<endl;
	else if (a >= 97 && a <= 122) cout<<"您输入了一个小写字母"<<a<<endl;
	else if (a == 32) cout<<"您输入了一个空格"<<a<<endl;
	else if (a == 10) goto end;
	else cout<<"您输入了一个其他字符"<<a<<endl;
	cout << "请再输入一个字符，按回车键确定" << endl;
end:
	goto loop;
	return 0;
}