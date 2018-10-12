#include <iostream>
using namespace std;
class Time
{
public:
	int hh,mm,ss,t;
	void SetTime(){cin>>hh>>mm>>ss;}
	int time(){t=hh*3600+mm*60+ss;return t;}
	void Test(){if (ss<0){mm-=1;ss+=60;};if (mm<0){hh-=1;mm+=60;};}
};
class Line
{
public:
	double start,stop,route;
	void RouteStart(){cin>>start;}
	void RouteStop(){cin>>stop;}
	double Route(){route=stop-start;return route;}
};
int main()
{
	Time t1,t2,t;
	Line r;
	double v;
	cout << "所有输入数据均为整数" << endl << "开始里程？" << endl;
	r.RouteStart();
	cout << "开始时间（时 分 秒）？" << endl;
	t1.SetTime();
	cout << "结束里程？" << endl;
	r.RouteStop();
	cout << "结束时间（时 分 秒）？" << endl;
	t2.SetTime();
	t.hh=t2.hh-t1.hh;
	t.mm=t2.mm-t1.mm;
	t.ss=t2.ss-t1.ss;
	t.Test();
	v = r.Route() / (t.time()/3600.0);
	cout<<"汽车行驶了"<<r.Route()<<"公里"<<endl;
	cout<<"消耗时间"<<t.hh<<"时"<<t.mm<<"分"<<t.ss<<"秒"<<endl;
	cout<<"平均速度： "<<v<<"公里 / 小时"<<endl;
	return 0;
}