#include <iostream>
using namespace std;
int main()
{
	int a , b , c;
	cout<<"请输入三个整数！"<<endl<<"整数1：";
	cin>>a;
	cout<<"整数2：";
	cin>>b;
	cout<<"整数3：";
	cin>>c;
	cout<<"最小的数为："<<((a>=b)?((b>=c)?c:b):((a>=c)?c:a))<<endl;
	return 0;
}