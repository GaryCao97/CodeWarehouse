#include <iostream>
using namespace std;
int max(int x, int y){
	int m = x;
	if (y>m)
		m = y;
	return m;
}
int main(){
	int a, b, c;
	int(*funp)(int, int); /*���庯��ָ��*/
	cout << "Input a,b:\t";
	cin >> a >> b;
	funp = max; /*����ָ��ָ�����ĺ���*/
	c = (*funp)(a, b); /*�ú���ָ����ú���*/
	cout << "max=" << c << endl;
	return 0;
}
