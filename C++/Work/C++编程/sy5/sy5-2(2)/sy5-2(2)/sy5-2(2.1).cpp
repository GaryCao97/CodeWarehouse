#include <iostream>
using namespace std;
extern int combinNum(int ,int);
int main()
{
	int m,n,combin;
	cout << "请输入两个正整数：";
	cin >> m >> n;
	if(m <=0 || n <= 0 || m < n)
	{
		cout << "你输入的数据有误！" << endl;
		return 0;
	}
	combin = combinNum(m,n);
	cout << "Combin " << m << "," << n << " is " << combin << endl;
	return 0;
}