#include <iostream>
using namespace std;

int main()
{
	double t1 , t2  , M , m ;
	cout<<"请输入工作时薪（元）：";
	cin>>m;
	cout<<"请输入正常工作时间（时）：";
	cin>>t1;
	if (t1>260) 
	{
		t1 = 260;
		cout<<"注意：您的工作时间已超过规定时长！"<<endl;
	}
	cout<<"请输入加班工作时间（时）：";
	cin>>t2;
	M = t1 * m + t2 * 1.5 * m;
	cout<<"最终工资为："<<M<<"元！"<<endl;
	return 0;
}