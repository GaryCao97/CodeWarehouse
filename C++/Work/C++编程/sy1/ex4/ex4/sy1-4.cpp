#include  <iostream>
using namespace std; 
int main()
{
	int chang,kuan,c,s;
	cout<<"请输入长方形的长与宽！"<<endl;
	cout<<"长为";
	cin>>chang;
	cout<<"宽为";
	cin>>kuan;
	c = ( chang + kuan ) * 2;
	s = chang * kuan;
	cout<<"长方形的周长为 "<<c<<" ！ "<<"长方形的面积为 "<<s<<" ！"<<endl;
	return 0;
}
