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
	cout << "�����������ݾ�Ϊ����" << endl << "��ʼ��̣�" << endl;
	r.RouteStart();
	cout << "��ʼʱ�䣨ʱ �� �룩��" << endl;
	t1.SetTime();
	cout << "������̣�" << endl;
	r.RouteStop();
	cout << "����ʱ�䣨ʱ �� �룩��" << endl;
	t2.SetTime();
	t.hh=t2.hh-t1.hh;
	t.mm=t2.mm-t1.mm;
	t.ss=t2.ss-t1.ss;
	t.Test();
	v = r.Route() / (t.time()/3600.0);
	cout<<"������ʻ��"<<r.Route()<<"����"<<endl;
	cout<<"����ʱ��"<<t.hh<<"ʱ"<<t.mm<<"��"<<t.ss<<"��"<<endl;
	cout<<"ƽ���ٶȣ� "<<v<<"���� / Сʱ"<<endl;
	return 0;
}