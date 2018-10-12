#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m=3;
start:
	cout << "请输入你要输入的数的个数n：";
	cin >> n;
	if (n <= 0) 
	{
		cout << "你输入的数据有误，还有"<< --m << "次机会重新输入！" << endl;
		goto start;
	}
	if (m == 0) 
		goto end;
	double num,max = 0,min = 0,aver = 0,sum_squares = 0,ssd;
	for (int i = 0;i < n;i++)
	{
		cout << "请输入第" << i+1 << "个数：";
		cin >> num;
		if (!i) {max = num;min = num;}
		if ( num > max) max = num;
		if (num < min) min = num;
		aver += num / n;
		sum_squares += num * num;
	}
	ssd = sqrt (sum_squares / n - pow (aver,2));
	cout << "这"<< n << "个数的数值范围为：[" << min << " , " << max << "]" << endl;
	cout << "这些数的标准差为：" << ssd << endl;
end:
	return 0;
}