#include <iostream>
using namespace std;
int main()
{
	cout << "������һ���ַ������س���ȷ��" << endl;
loop:
	char a;
	a = getchar();
	if (a >= 48 && a <= 57) cout<<"��������һ������"<<a<<endl;
	else if (a >= 65 && a <= 90) cout<<"��������һ����д��ĸ"<<a<<endl;
	else if (a >= 97 && a <= 122) cout<<"��������һ��Сд��ĸ"<<a<<endl;
	else if (a == 32) cout<<"��������һ���ո�"<<a<<endl;
	else if (a == 10) goto end;
	else cout<<"��������һ�������ַ�"<<a<<endl;
	cout << "��������һ���ַ������س���ȷ��" << endl;
end:
	goto loop;
	return 0;
}