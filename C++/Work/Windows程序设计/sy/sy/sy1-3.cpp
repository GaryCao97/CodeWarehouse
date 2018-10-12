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
	printf_s("��������Ҫ����ĵ�ĸ�����");
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
		printf_s("��ѡ����Ҫ���еĹ��ܣ�\n");
		printf_s("���õ��λ��---------1\n");
		printf_s("��ȡ���λ��---------2\n");
		printf_s("�ƶ����λ��---------3\n");
		printf_s("��õ����ľ���-----4\n");
		printf_s("�����������---------5\n");
		printf_s("�����������---------6\n");
		scanf_s("%c", &choice);
		getchar();
		switch (choice){
		case '1':
			do{
				system("cls");
				printf_s("�����������������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("�����õ�����꣺��x,y,z��\n");
				scanf_s("%lf,%lf,%lf", &xx, &yy, &zz);
				getchar();
				if (p[i].SetPosition(xx, yy, zz)) printf_s("���óɹ�\n");
				else printf_s("����ʧ��\n");
				printf_s("���������밴1\n�����밴������\n");
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
				printf_s("�������ȡ�������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("�������Ϊ��\n");
				if (p[i].GetPosition(xx, yy, zz)){
					printf_s("��ȡ�ɹ�\n");
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				}
				else printf_s("��ȡʧ��\n");
				printf_s("���»�ȡ�밴1\n�����밴������\n");
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
				printf_s("�������ƶ��������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("��������ƶ��ľ��룺��x,y,z��\n");
				scanf_s("%lf,%lf,%lf", &xx, &yy, &zz);
				getchar();
				if (p[i].MovePoint(xx, yy, zz)) printf_s("�ƶ��ɹ�\n");
				else printf_s("�ƶ�ʧ��\n");
				printf_s("�����ƶ��밴1\n�����밴������\n");
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
				printf_s("�������һ���������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("������ڶ����������ţ�");
				scanf_s("%d", &j);
				getchar();
				double dis;
				if (p[i].GetDistance(p[j], dis)){
					printf_s("��óɹ�\n");
					if (p[i].GetPosition(xx, yy, zz))
						printf_s("(%.2lf,%.2lf,%.2lf) �� ", xx, yy, zz);
					if (p[j].GetPosition(xx, yy, zz))
						printf_s("(%.2lf,%.2lf,%.2lf) ", xx, yy, zz);
					printf_s("�����Ϊ��%.2lf\n",dis);
				}
				else printf_s("���ʧ��\n");
				printf_s("������ȡ�����밴1\n�����밴������\n");
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
				printf_s("�������һ���������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("������ڶ����������ţ�");
				scanf_s("%d", &j);
				getchar();
				ans = p[i] + p[j];
				if (p[i].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) + ", xx, yy, zz);
				if (p[j].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) = ", xx, yy, zz);
				if (ans.GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				printf_s("�����밴1\n�����밴������\n");
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
				printf_s("�������һ���������ţ�");
				scanf_s("%d", &i);
				getchar();
				printf_s("������ڶ����������ţ�");
				scanf_s("%d", &j);
				getchar();
				ans = p[i] - p[j];
				if (p[i].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) - ", xx, yy, zz);
				if (p[j].GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf) = ", xx, yy, zz);
				if (ans.GetPosition(xx, yy, zz))
					printf_s("(%.2lf,%.2lf,%.2lf)\n", xx, yy, zz);
				printf_s("�����밴1\n�����밴������\n");
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