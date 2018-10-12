#include<iostream>
using namespace std;

class TPoint {
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
TPoint::TPoint(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}
bool TPoint::SetPosition(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
	return true;
}
bool TPoint::GetPosition(double &xx, double &yy, double &zz) {
	xx = x;
	yy = y;
	zz = z;
	return true;
}
bool TPoint::MovePoint(double xx, double yy, double zz) {
	x += xx;
	y += yy;
	z += zz;
	return true;
}
bool TPoint::GetDistance(TPoint p1, double &dis) {
	double x1, y1, z1;
	p1.GetPosition(x1, y1, z1);
	dis = sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) + (z1 - z)*(z1 - z));
	return true;
}
int main() {
	TPoint *p;
	int n;
	cin >> n;
	p = (TPoint*)malloc(n * sizeof(TPoint));
	for (int i = 0; i < n; i++) {
		double xx, yy, zz;
		cin >> xx >> yy >> zz;
		p[i].SetPosition(xx, yy, zz);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dis;
			double xx, yy, zz;
			if (p[i].GetDistance(p[j], dis)) {
				if (p[i].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) Óë ", xx, yy, zz);
				if (p[j].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) ", xx, yy, zz);
				printf_s("¼ä¾àÀëÎª£º%.2lf\n", dis);
			}
		}
	}
	return 0;
}