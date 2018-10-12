#include <iostream>
using namespace std;

int main()
{
	int hh , mm , ss , t1 , t2 , start , stop; 
	int s , t;
	double v;
	cout << "所有输入数据均为整数" << endl << "开始里程？" << endl;
	cin >> start;
	cout << "开始时间（时 分 秒）？" << endl;
	cin >> hh >> mm >> ss;
	t1 = hh * 3600 + mm * 60 + ss;
	cout << "结束里程？" << endl;
	cin >> stop;
	cout << "结束时间（时 分 秒）？" << endl;
	cin >> hh >> mm >> ss;
	t2 = hh * 3600 + mm * 60 + ss;
	s = stop - start;
	t = t2 - t1;
	v = s / (t/3600.0);
	hh = t/3600;
	mm = (t%3600)/60;
	ss = (t%3600)%60;
	cout<<"汽车行驶了"<<s<<"公里"<<endl;
	cout<<"消耗时间"<<hh<<"时"<<mm<<"分"<<ss<<"秒"<<endl;
	cout<<"平均速度： "<<v<<"公里 / 小时"<<endl;
	return 0;
}