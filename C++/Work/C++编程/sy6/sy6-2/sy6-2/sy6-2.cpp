#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int arr[] = {1,5,19,20,60,0} , *p = arr ,input;
	cout << "������Ҫ�����������";
	cin >> input;
	cout << "����ǰ��" << endl;
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
	cout << "�����" << endl;
	for(int i = 0;i < 6;i++)
	{
		cout << *(p+i) << ' ';
	}
	cout << endl;
	return 0;
}