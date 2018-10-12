#include <iostream>
using namespace std;
int main()
{
	double num1,num2,result;
	char op;
	cout << "Please enter the expression: ";
	cin >> num1 >> op >> num2;
	switch (op)
	{
	case '+':result = num1 + num2;break;
	case '-':result = num1 - num2;break;
	case '*':result = num1 * num2;break;
	case '/':result = num1 / num2;break;
	default :cout << "你输入的运算符有误！" << endl;
	}
	printf("%.0lf %c %.0lf = %.0lf\n",num1,op,num2,result);
	return 0;
}