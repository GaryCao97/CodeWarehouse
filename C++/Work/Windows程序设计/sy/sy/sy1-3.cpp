#include<iostream>
using namespace std;
class TPoint{
private:
	double x, y, z;
public:
	TPoint(double xx = 0, double yy = 0, double zz = 0);
	bool SetPosition(double xx = 0, double yy = 0, double zz = 0);
	bool GetPosition(double &xx, double &yy, double &zz);
	bool MovePoint(double xx, double yy, double zz);
	bool GetDistance(TPoint p1, double &dis);
	TPoint operator+(TPoint p);
	TPoint operator-(TPoint p);
};
TPoint::TPoint(double xx, double yy, double zz){
	x = xx;
	y = yy;
	z = zz;
}
bool TPoint::SetPosition(double xx, double yy, double zz){
	x = xx;
	y = yy;
	z = zz;
	return true;
}
bool TPoint::GetPosition(double &xx, double &yy, double &zz){
	xx = x;
	yy = y;
	zz = z;
	return true;
}
bool TPoint::MovePoint(double xx, double yy, double zz){
	x += xx;
	y += yy;
	z += zz;
	return true;
}
bool TPoint::GetDistance(TPoint p1, double &dis){
	double x1, y1, z1;
	p1.GetPosition(x1, y1, z1);
	dis = sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) + (z1 - z)*(z1 - z));
	return true;
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
	char choice;
	TPoint *p;
	printf_s("请输入你要输入的点的个数：");
	int n;
	scanf_s("%d", &n);
	getchar();
	p = (TPoint*)malloc(n*sizeof(TPoint));
	do{
		double xx, yy, zz;
		TPoint ans;
		char choose;
		int i, j;
		system("cls");
		printf_s("请选择你要进行的功能：\n");
		printf_s("设置点的位置---------1\n");
		printf_s("获取点的位置---------2\n");
		printf_s("移动点的位置---------3\n");
		printf_s("获得点与点的距离-----4\n");
		printf_s("计算两点相加---------5\n");
		printf_s("计算两点相减---------6\n");
		scanf_s("%c", &choice);
		getchar();
		switch (choice){
		case '1':
			do{
				system("cls");
				printf_s("请输入设置坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("请设置点的坐标：（x,y,z）\n");
				scanf_s("%lf,%lf,%lf", &xx, &yy, &zz);
				getchar();
				if (p[i].SetPosition(xx, yy, zz)) printf_s("设置成功\n");
				else printf_s("设置失败\n");
				printf_s("重新设置请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		case '2':
			do{
				system("cls");
				printf_s("请输入获取坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("点的坐标为：\n");
				if (p[i].GetPosition(xx, yy, zz)){
					printf_s("获取成功\n");
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				}
				else printf_s("获取失败\n");
				printf_s("重新获取请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		case '3':
			do{
				system("cls");
				printf_s("请输入移动坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("请输入点移动的距离：（x,y,z）\n");
				scanf_s("%lf,%lf,%lf", &xx, &yy, &zz);
				getchar();
				if (p[i].MovePoint(xx, yy, zz)) printf_s("移动成功\n");
				else printf_s("移动失败\n");
				printf_s("继续移动请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		case '4':
			do{
				system("cls");
				printf_s("请输入第一个坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("请输入第二个坐标的序号：");
				scanf_s("%d", &j);
				getchar();
				double dis;
				if (p[i].GetDistance(p[j], dis)){
					printf_s("获得成功\n");
					if (p[i].GetPosition(xx, yy, zz))
						printf_s("(%.2lf,%.2lf,%.2lf) 与 ", xx, yy, zz);
					if (p[j].GetPosition(xx, yy, zz))
						printf_s("(%.2lf,%.2lf,%.2lf) ", xx, yy, zz);
					printf_s("间距离为：%.2lf\n",dis);
				}
				else printf_s("获得失败\n");
				printf_s("继续获取距离请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		case '5':
			do{
				system("cls");
				printf_s("请输入第一个坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("请输入第二个坐标的序号：");
				scanf_s("%d", &j);
				getchar();
				ans = p[i] + p[j];
				if (p[i].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) + ", xx, yy, zz);
				if (p[j].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) = ", xx, yy, zz);
				if (ans.GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				printf_s("继续请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		case '6':
			do{
				system("cls");
				printf_s("请输入第一个坐标的序号：");
				scanf_s("%d", &i);
				getchar();
				printf_s("请输入第二个坐标的序号：");
				scanf_s("%d", &j);
				getchar();
				ans = p[i] - p[j];
				if (p[i].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) - ", xx, yy, zz);
				if (p[j].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) = ", xx, yy, zz);
				if (ans.GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				printf_s("继续请按1\n返回请按其他键\n");
				scanf_s("%c", &choose);
				getchar();
				if (choose == '1')
					continue;
				else break;
			} while (1);
			break;
		}
		if (choice > '6' || choice < '1')
			break;
	} while (1);
	return 0;
}