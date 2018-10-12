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
	cout << "请选定初始整数：" << endl;
	cin >> num0;
	int num[10] , difference[10] , ordinal , difference_min;
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << "输入第" << i + 1 << "个整数：" << endl;
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
	cout << "离初始整数" << num0 << "最接近的数是第" << ordinal << "个整数：" <<  num[ordinal - 1] << endl;
	return 0;
}