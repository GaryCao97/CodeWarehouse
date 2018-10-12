#include <iostream>
using namespace std;
int main()
{
	int num1,num2,p;
	cout << "Enter a fraction (like: 1/2) : " ;
	scanf("%d/%d",&num1,&num2);
	for (p = num1;p > 0 && (num2 % p != 0 || num1 % p != 0);p--);
	num1 = num1 / p;
	num2 = num2 / p;
	cout << "In lowest terms : " << num1 << "/" << num2 << endl;
	return 0;
}