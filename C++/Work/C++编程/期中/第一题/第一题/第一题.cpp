#include <iostream>
using namespace std;
int main()
{
	double h,w,t;
	cout << "�����룺" << endl;
	cout << "����(��λ��kg) ";
	cin >> w;
	cout << "���(��λ��m)  ";
	cin >> h;
	t = w / (h * h);
	if(t < 18)
		printf("�����ָ��Ϊ%lf�����ǵ��������ơ�\n",t);
	else if(t>= 18&& t < 25)
		printf("�����ָ��Ϊ%lf�����������������ơ�\n",t);
	else if(t>= 25&& t < 27)
		printf("�����ָ��Ϊ%lf�����ǳ����������ơ�\n",t);
	else
		printf("�����ָ��Ϊ%lf�����Ƿ������ơ�\n",t);
	return 0;
}