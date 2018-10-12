#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;

class TPoint{
	private:
		double x,y,z;
	public:
		void set(double xx,double yy,double zz);
		void read(double &xx,double &yy,double &zz);
		void move(double xx,double yy,double zz);
		void GetDistance(TPoint p1, double &dis);
		TPoint operator+(TPoint p);
		TPoint operator-(TPoint p);
};

void TPoint::set(double xx,double yy,double zz){
		x=xx;
		y=yy;
		z=zz;
		cout<<endl;
}


void TPoint::read(double &xx,double &yy,double &zz){
	xx = x;
	yy = y;
	zz = z;
}

void TPoint::move(double xx,double yy,double zz){
	x+=xx;
	y+=yy;
	z+=zz;
}

void TPoint::GetDistance(TPoint p1, double &dis){
	double x1, y1, z1;
	p1.read(x1, y1, z1);
	dis = sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) + (z1 - z)*(z1 - z));
}

TPoint TPoint::operator+(TPoint p){
	TPoint q;
	q.x = x + p.x;
	q.y = y + p.y;
	q.z = z + p.z;
	return q;
}

TPoint TPoint::operator-(TPoint p){
	TPoint q;
	q.x = x - p.x;
	q.y = y - p.y;
	q.z = z - p.z;
	return q;
}


int main(){
	int N,n,i;
	int a,b; 
	double xx, yy, zz;
	cout<<"请输入有多少个坐标： ";
	cin>>N;
	TPoint point[N];
	TPoint andpoint;
	cout<<endl;
	loop:
	{
	cout<<"您想进行什么操作？"<<endl;
	cout<<"1) 设置坐标；"<<endl;
	cout<<"2) 读取坐标；"<<endl;
	cout<<"3) 移动坐标；"<<endl;
	cout<<"4) 计算坐标的距离；"<<endl;
	cin>>n;
	switch(n){
	case 1:
		system("cls");
		for(i=1;i<=N;i++){
		cout<<"请输入第"<<i<<"个坐标的值： "<<endl;
		cin>>xx>>yy>>zz;
		point[i-1].set(xx,yy,zz);
		}
		//cout<<"("<<point[i-1].x<<","<<point[i-1].y<<","<<point[i-1].z<<")"<<endl;
		break;
	case 2:
		system("cls");
		cout<<"请输入要查找坐标的序号： ";
		cin>>i;
		point[i-1].read(xx,yy,zz);
		cout<<"("<<xx<<","<<yy<<","<<zz<<")"<<endl;
		break;
	case 3:
		system("cls");
		cout<<"请输入要移动的坐标序号：";
		cin>>i;
		cout<<endl; 
		cout<<"请输入要移动的值： ";
		cin>>xx>>yy>>zz;
		cout<<endl;
		point[i-1].move(xx,yy,zz);
		point[i-1].read(xx,yy,zz);
		cout<<"移动后坐标值为："<<"("<<xx<<","<<yy<<","<<zz<<")"<<endl;
		break;
	case 4:
		system("cls");
		double dis;
		cout<<"请输入要计算哪两个点的序号： ";
		cin>>a>>b;
		cout<<endl;
		point[a-1].GetDistance(point[b-1],dis);
		cout<<"两点间距离为："<<dis<<endl;
		break;
	default:
		cout<<"请输入1-4的数字"<<endl;
		break;	
	}
	goto loop;
	}//loop
	point[3] = point[1]+(point[2])
}//main







