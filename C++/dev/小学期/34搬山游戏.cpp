#include<iostream>
using namespace std;
int main(){
	int m,n,j,k,tag,t = 0,w = 0;
	cout << "����n��ɽ�������������Ϊ������˫����˫��������ɽ���涨ÿ�ΰ�ɽ����Ŀ���ܳ���k����˭�����һ��˭�䡣"<<endl; 
	cout << "������ɽ������(n)��ÿ�������ɽ�������Ŀ(k)��";
	while(cin >> n && n != 0){
		cin >> k;
		tag = 1;
		do{
			do{
				cout << "��������Ҫ���ɽ��������";
				cin >> m;
			}while(m <= 0 || m > k || n-m < 0);
			n -= m;
			if(n <= 0){
				tag = 0;
				break;
			}
			j = ((n - 1) % (k + 1) == 0)?1:((n - 1) % (k + 1));
			cout << "�������" << j << "��ɽ����ʣ��" << n - j << "��!" << endl;
			n -= j;
		}while(n>0);
		t++;
		w+=tag;
		if(tag)cout << "��Ӯ�ˣ�" << endl;
		else cout << "�����ˣ�" << endl;
		system("pause");
		system("cls");
		cout << "������ɽ������(n)��ÿ�������ɽ�������Ŀ(k)��";
	}
	cout << "�ܹ�����" << t << "����Ϸ���㹲Ӯ��" << w << "�Σ�" << endl;
	return 0; 
} 
