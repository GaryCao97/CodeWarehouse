#include<iostream>
using namespace std;
int Prime(int x)															/*����һ���ж����Ƿ��������ĺ���*/
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
	int integer , prime[10] , sum = 0 , n;
	cout << "������һ����������";											/*��ʾ�����ʼ������*/
	cin >> integer;
	for (int m = 0 ; m < 10 ; m++) prime[m]=0;								/*��ʼ��prime[]����*/
	int num = integer;														/*���ڴ�������integer�Ĺ��̱���num*/
	for (n = 0 ; n < 10 ; n++)												/*��ѭ����佫ǰʮ�������ֱ����뵽prime[]������*/
	{
		for (; num > 1 ;num--)												/*��num��ʼ�ж������������μ�С����*/
			if (Prime(num) != 0) {prime[n] = num--;break;}					/*�ж�num�Ƿ�Ϊ�������������ֵ��prime[]����*/
		sum += prime[n];													/*�������*/
		if (prime[n] != 0) cout << prime[n] << " + ";
	}
	cout << '\b' << '\b' << "= " << sum << endl;
	if (prime[9] == 0) cout << "����" << integer << "�ڵ���������ʮ����" << endl;
	return 0;
}