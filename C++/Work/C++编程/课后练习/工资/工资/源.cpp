#include <iostream>
using namespace std;

int main()
{
	double t1 , t2  , M , m ;
	cout<<"�����빤��ʱн��Ԫ����";
	cin>>m;
	cout<<"��������������ʱ�䣨ʱ����";
	cin>>t1;
	if (t1>260) 
	{
		t1 = 260;
		cout<<"ע�⣺���Ĺ���ʱ���ѳ����涨ʱ����"<<endl;
	}
	cout<<"������Ӱ๤��ʱ�䣨ʱ����";
	cin>>t2;
	M = t1 * m + t2 * 1.5 * m;
	cout<<"���չ���Ϊ��"<<M<<"Ԫ��"<<endl;
	return 0;
}