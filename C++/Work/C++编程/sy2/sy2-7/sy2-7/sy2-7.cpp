#include<iostream>
using namespace std;
int main()
{
	double x , y;
	cout<<"������ƽ���ϵ�ĺ�����x��������y"<<endl<<"������xΪ��";
	cin>>x;
	cout<<"������yΪ��";
	cin>>y;
	cout<<"�����ֵΪ��"<<(((x <= 2)&&(x >= -2)) && ((y <= 2)&&(y >= -2)))<<endl;
}