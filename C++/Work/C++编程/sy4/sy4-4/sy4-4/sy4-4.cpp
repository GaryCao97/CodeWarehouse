#include <iostream>
#include <cstdio>
using namespace std;
void Search(int a,int b[20])
{
	int n1 = 0, n2 = 19, n3 = (n1 + n2) / 2;
	for (;a != b[n3];)
	{
		n3 = (n1 + n2) / 2;
		if(a > b[n3]) n1 = n3;
		else if (a < b[n3]) n2 = n3;
		if(n2 - n1 == 1 && a != b[n1] && a != b[n2])break;
		else if (n2 - n1 == 1 && n2 == 19)n3 = n2;
	}
	if (a == b[n3])
		cout << a << "�����еĵ�" << n3 + 1 << "������" << endl;
	else cout << a << "���������С�" << endl;
}
int main()
{
	int num[20]={1,4,5,6,7,8,9,11,13,14,15,16,17,18,19,21,23,29,36,60};
	cout << "��ʼ����Ϊ��" << endl;
	for(int i = 0;i < 20;i++)
		cout << num[i] << " ";
	cout << endl;
	int input;
loop:
	cout << "����������Ҫ���ҵ�����";
	scanf("%d",&input);
	Search(input,num);
	goto loop;
	return 0;
}