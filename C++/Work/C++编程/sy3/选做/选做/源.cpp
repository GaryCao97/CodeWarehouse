#include <iostream>
using namespace std;
int min(int x,int y)
{
	int z;
	z = (x >= y) ? y : x;
	return z;
}
int different(int x,int y)
{
	int z;
	if (x >= y) z = x - y;
	else z = y - x;
	return z;
}
int main()
{
	int num0;
	cout << "��ѡ����ʼ������" << endl;
	cin >> num0;
	int num[10] , difference[10] , ordinal , difference_min;
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << "�����" << i + 1 << "��������" << endl;
		cin >> num[i];
		difference[i] = different(num[i],num0);
		difference_min = min(num[i] , num0);
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		if (difference_min == difference[i]) 
		{
			ordinal = i + 1;
			break;
		}
	}
	cout << "���ʼ����" << num0 << "��ӽ������ǵ�" << ordinal << "��������" <<  num[ordinal - 1] << endl;
	return 0;
}