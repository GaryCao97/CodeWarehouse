#include <iostream>
using namespace std;
int main()
{
	int num;
start:
	cout << "Please input a number: " ;
	cin >> num;
	if (num <= 1)											/*����������ֻ�д���1������������������*/
	{
		cout << "There are something wrong!!Please input again!" << endl;
		goto start;
	}
	int p[100],e = 1;										/*��������p[]���������ӣ�e���������ӵĸ���*/
	cout << num << " = ";
	for (int i = 0;i < 100;i++)								/*ѭ������������*/
	{
		p[i] = 0;
		for (int n = 2;n <= num && p[i] == 0;n++)			/*��С����ѭ���ж�n�ǲ���num������*/
		{
			if (num % n == 0)								/*���n��������ô��֮�����ڱ���p[]��*/
			{
				num /= n;									/*������Сnum�Ĵ�С*/
				p[i] = n;
			}
		}
		if (i > 0 && p[i-1] == p[i])						/*���ڶ��λ������жϳ���������ǰһ��������ͬ*/
		{
			p[i--] = 0;										/*��ձ��ε��жϣ�����һ��*/
			e++;											/*���������ӵĸ����ı���e+1*/
		}
		else if (i > 0 && p[i] != p[i-1])					/*���ڶ��λ������жϳ���������ǰһ�����Ӳ�ͬ*/
		{
			cout <<" "<< p[i-1] << " ( " << e << " ) ";		/*�����һ�����Ӽ������*/
			e = 1;											/*����������������Ϊ1*/
		}
		if (p[i] == 0)break;								/*����ε�ѭ��û�в������ӣ���num�Ѿ���СΪ1ʱ������ѭ��*/
	}
	cout << endl;
	goto start;
	return 0;
}