#include<iostream>
using namespace std;
int main()
{
	double x , y;
	cout<<"请输入平面上点的横坐标x和纵坐标y"<<endl<<"横坐标x为：";
	cin>>x;
	cout<<"纵坐标y为：";
	cin>>y;
	cout<<"输出的值为："<<(((x <= 2)&&(x >= -2)) && ((y <= 2)&&(y >= -2)))<<endl;
}