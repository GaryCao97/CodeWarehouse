#include <iostream>
using namespace std;

double _N(int x)
{
	switch (x/100)
	{
	case 0 :return 0.0;break;
	case 1 :return 0.015;break;
	case 2 :return 0.025;break;
	case 3 :return 0.035;break;
	case 4 :return 0.045;break;
	case 5 :return 0.055;break;
	default :return 0.06;
	}
}

int main()
{
	int M;
loop :
	cout << "������˿����ѽ�";
	cin >> M;
	double N;
	N = _N(M);
	cout << "�˿͵����ѽ��Ϊ��" << M << "�˿͵�ʵ�����ѽ��Ϊ��" << (M * (1.0 - N)) << "�˿͵ķ������Ϊ��" << (M * N) << endl;
	goto loop;
	return 0;
}