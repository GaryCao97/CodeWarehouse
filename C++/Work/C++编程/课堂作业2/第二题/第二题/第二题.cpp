#include <iostream>
using namespace std;
int main()
{
	cout << "请输入一组最高气温(输入-1结束)：" << endl;
	int temperature = 0,shushi = 0,gaowen = 0,hanleng = 0,sum = 0,days = 0;
	while(temperature >= 0)
	{
		cin >> temperature;
		if (temperature >= 85) gaowen ++;
		else if(temperature < 60) hanleng ++;
		else shushi ++;
		sum += temperature;
		days ++;
	}
	double aver = (double)sum /days;
	cout << "高温(华氏温度大于等于85)天数 " << gaowen << " 舒适天数 " << shushi << " 寒冷(华氏温度小于60)天数 " << hanleng << endl << "平均温度" << aver << endl;
	return 0;
}