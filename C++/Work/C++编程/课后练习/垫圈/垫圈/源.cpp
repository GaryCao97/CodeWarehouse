#include<iostream>
using namespace std;
const double PI=3.14;
class dianquan
{
	double r1,r2,midu,houdu,v;
public:
	void GetInsideRadio(double a) {r1 = a;}
	void GetOutsideRadio(double a) {r2 = a;}
	void GetHoudu(double a) {houdu = a;}
	void GetMidu(double a) {midu = a;}
	double GiveTiji() {v = midu*PI*houdu*(r2*r2-r1*r1);return v;}
};
int main()
{
	dianquan n;
	double r1,r2,midu,houdu;
	cout<<"��������Ȧ�뾶��"<<endl;
	cin>>r1;
	cout<<"��������Ȧ�뾶��"<<endl;
	cin>>r2;
	cout<<"�������Ȧ��ȣ�"<<endl;
	cin>>houdu;
	cout<<"�������Ȧ�ܶȣ�"<<endl;
	cin>>midu;
	n.GetInsideRadio(r1);	n.GetOutsideRadio(r2);	n.GetHoudu(houdu);	n.GetMidu(midu);
	cout<<"��Ȧ�����Ϊ"<<n.GiveTiji()<<endl;
}