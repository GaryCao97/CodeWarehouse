#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int arr[] = {1,5,19,20,60,0} , *p = arr ,input;
	cout << "请输入要插入的整数：";
	cin >> input;
	cout << "插入前：" << endl;
	for(int i = 0;i < 5;i++)
	{
		cout << *(p+i) << ' ';
	}
	cout << endl;
	for(int i = 0;i < 5;i++)
	{
		if(input <= *(p+i))
		{
			for(int j = 5;j >= i;j--)
				*(p+j) = *(p+j-1);
			*(p+i) = input;
			break;
		}
	}
	cout << "插入后：" << endl;
	for(int i = 0;i < 6;i++)
	{
		cout << *(p+i) << ' ';
	}
	cout << endl;
	return 0;
}