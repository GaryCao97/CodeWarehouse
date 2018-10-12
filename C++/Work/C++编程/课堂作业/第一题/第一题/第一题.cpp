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
	cout << "请输入顾客消费金额：";
	cin >> M;
	double N;
	N = _N(M);
	cout << "顾客的消费金额为：" << M << "顾客的实际消费金额为：" << (M * (1.0 - N)) << "顾客的返利金额为：" << (M * N) << endl;
	goto loop;
	return 0;
}