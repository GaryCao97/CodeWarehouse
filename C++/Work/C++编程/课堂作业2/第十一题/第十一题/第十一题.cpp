#include <iostream>
using namespace std;
int main()
{
	int num;
start:
	cout << "Please input a number: " ;
	cin >> num;
	if (num <= 1)											/*报错声明，只有大于1的正整数才有质因子*/
	{
		cout << "There are something wrong!!Please input again!" << endl;
		goto start;
	}
	int p[100],e = 1;										/*声明变量p[]储存质因子，e储存质因子的个数*/
	cout << num << " = ";
	for (int i = 0;i < 100;i++)								/*循环储存质因子*/
	{
		p[i] = 0;
		for (int n = 2;n <= num && p[i] == 0;n++)			/*从小到大循环判断n是不是num的因子*/
		{
			if (num % n == 0)								/*如果n是因子那么将之储存于变量p[]中*/
			{
				num /= n;									/*并且缩小num的大小*/
				p[i] = n;
			}
		}
		if (i > 0 && p[i-1] == p[i])						/*当第二次或以上判断出的因子与前一个因子相同*/
		{
			p[i--] = 0;										/*清空本次的判断，返回一步*/
			e++;											/*储存质因子的个数的变量e+1*/
		}
		else if (i > 0 && p[i] != p[i-1])					/*当第二次或以上判断出的因子与前一个因子不同*/
		{
			cout <<" "<< p[i-1] << " ( " << e << " ) ";		/*输出上一个因子及其个数*/
			e = 1;											/*将个数计数变量归为1*/
		}
		if (p[i] == 0)break;								/*当这次的循环没有产生因子，即num已经缩小为1时，结束循环*/
	}
	cout << endl;
	goto start;
	return 0;
}