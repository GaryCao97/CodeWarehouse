#include <iostream>
using namespace std;
int main()
{
	cout << "������һ���������(����-1����)��" << endl;
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
	cout << "����(�����¶ȴ��ڵ���85)���� " << gaowen << " �������� " << shushi << " ����(�����¶�С��60)���� " << hanleng << endl << "ƽ���¶�" << aver << endl;
	return 0;
}