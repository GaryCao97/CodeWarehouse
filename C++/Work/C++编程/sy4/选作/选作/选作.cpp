#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
int GetBNum(int arr1[4],int arr2[4])
{
	int num=0;
	for (int n = 0;n < 4;n++)
		for (int i = 0;i < 4;i++)
			if (arr1[i] == arr2[n]) num++;
	return num;
}
int GetANum(int arr1[4],int arr2[4])
{
	int num=0;
	for (int i = 0;i < 4;i++)
		if (arr1[i] == arr2[i]) num++;
	return num;
}
int main()
{
	srand(time(0));
	int num[4], input[4], _num, _input;

	do
	{
	_num = ( rand() + 1000 ) % 10000;
	for (int i = 0;i < 4;i++)
		num[i] =  ( _num / (int)pow(10,3 - i) )  % 10;
	}while (num[0] ==num[1] || num[0] == num[2] || num[0] == num[3] || num[1] == num[2] || num[1] == num[3] || num[2] == num[3]);
	int n = 10 ;
	cout<< "������Ϸ" << endl 
		<< "���ɼ�����������һ����λ�����4λ���֣����û����£������û��²�Ľ��������ʾ��xAyB" << endl
		<<"���У�Aǰ������ֱ�ʾ�м�λ���ֲ������ֲ¶��ˣ�����λ��Ҳ��ȷ��Bǰ������ֱ�ʾ�м�λ���ֲ¶��ˣ�����λ�ò���ȷ��" << endl;
	do
	{
		cout << "�������µ����֣� ";
		cin >> _input ;
		while (_input >= 10000 || _input < 1000){
			cout << "��������һ����������֣����������룺 ";
			cin >> _input;
		}
		for (int i = 0;i < 4;i++)
			input[i] =  ( _input / (int)pow(10,3 - i) )  % 10;
		if (GetANum(num,input) == 4) 
		{
			cout << "��ϲ�����ˣ� " << endl;
			break;
		}
		else 
		{
			cout << "A" << GetANum(num,input) << "B" << GetBNum(num,input) - GetANum(num,input)<< endl;
			cout << "�Բ�����´���!�㻹�� "<< --n << " �λ��ᣡ" << endl;
		}
	}while (n > 0);
	if (n == 0)
		cout << "����" << _num << endl;
	return 0;
}