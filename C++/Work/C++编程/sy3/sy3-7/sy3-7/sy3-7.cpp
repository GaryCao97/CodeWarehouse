#include<iostream>
using namespace std;

int Prime(int x)															/*����һ���ж�һ�����Ƿ��������ĺ���*/
{
	for (int n = 2 ; n < x ; n++)
	{
		if (x % n != 0) {continue;}
		else {return 0;break;}
	}
	return 1;
}

int main()
{
	cout << "������һ����������";
	int integer ;															/*��ʾ�����ʼ������*/
	cin >> integer;
	
	int prime[10];															/*����prime[]����������*/
	int sum = 0;
	
	for (int i = 0 ; i < 10 ; i++) prime[i]=0;
	
	for (int n = 0 ; n < 10 ; n++)											/*��ѭ����佫ǰʮ�������ֱ����뵽prime[]������*/
	{
		int _num;
		if (n == 0) _num = 0;
		else _num = integer - prime[n-1] + 1;
		for (int i = integer - _num ; i > 1 ; i--)							/*����һ��������ʼ�ж������������μ�С����*/
		{
			if (Prime(i) != 0) {prime[n] = i;break;}						/*�ж�i�Ƿ�Ϊ�������������ֵ��prime[]����*/
		}
		sum = sum + prime[n];												/*�������*/
	}
	
	{
		cout << prime[0];
		int i = 1;
		while((i <= 9) && (prime[i] != 0))
		{
			cout << " + " << prime[i] ;
			i++;
		}
		cout << " = " << sum << endl;
		if (prime[i] == 0) cout << "����" << integer << "�ڵ���������ʮ����" << endl;
	}
	return 0;
}