#include <iostream>
using namespace std;
long long Jie(int num)
{
	long long Mul = 1;
	for (int o = 1; o <= num; o++)
		Mul *= o;
	return Mul;
}
void main()
{
	double e = 0, Pre_Num = 1;
	int n;
	for (n = 0; Pre_Num > 0.000001; n++)
	{
		if (n != 0)
			Pre_Num = (double)1 / Jie(n);
		e += Pre_Num;
	}
	cout << e << endl;
}