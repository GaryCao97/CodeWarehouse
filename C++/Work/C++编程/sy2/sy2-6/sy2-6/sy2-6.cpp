#include <iostream>
using namespace std;
int main()
{
	int a , b , c;
	cout<<"����������������"<<endl<<"����1��";
	cin>>a;
	cout<<"����2��";
	cin>>b;
	cout<<"����3��";
	cin>>c;
	cout<<"��С����Ϊ��"<<((a>=b)?((b>=c)?c:b):((a>=c)?c:a))<<endl;
	return 0;
}