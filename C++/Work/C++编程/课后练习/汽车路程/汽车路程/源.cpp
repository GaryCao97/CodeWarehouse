#include <iostream>
using namespace std;

int main()
{
	int hh , mm , ss , t1 , t2 , start , stop; 
	int s , t;
	double v;
	cout << "�����������ݾ�Ϊ����" << endl << "��ʼ��̣�" << endl;
	cin >> start;
	cout << "��ʼʱ�䣨ʱ �� �룩��" << endl;
	cin >> hh >> mm >> ss;
	t1 = hh * 3600 + mm * 60 + ss;
	cout << "������̣�" << endl;
	cin >> stop;
	cout << "����ʱ�䣨ʱ �� �룩��" << endl;
	cin >> hh >> mm >> ss;
	t2 = hh * 3600 + mm * 60 + ss;
	s = stop - start;
	t = t2 - t1;
	v = s / (t/3600.0);
	hh = t/3600;
	mm = (t%3600)/60;
	ss = (t%3600)%60;
	cout<<"������ʻ��"<<s<<"����"<<endl;
	cout<<"����ʱ��"<<hh<<"ʱ"<<mm<<"��"<<ss<<"��"<<endl;
	cout<<"ƽ���ٶȣ� "<<v<<"���� / Сʱ"<<endl;
	return 0;
}