#include<iostream>
using namespace std;
int main(){
	int m,n,j,k,tag,t = 0,w = 0;
	cout << "设有n座山，计算机与人作为比赛的双方，双方轮流搬山。规定每次搬山的数目不能超过k座，谁搬最后一座谁输。"<<endl; 
	cout << "请输入山的总数(n)和每次允许搬山的最大数目(k)：";
	while(cin >> n && n != 0){
		cin >> k;
		tag = 1;
		do{
			do{
				cout << "请输入你要搬的山的数量：";
				cin >> m;
			}while(m <= 0 || m > k || n-m < 0);
			n -= m;
			if(n <= 0){
				tag = 0;
				break;
			}
			j = ((n - 1) % (k + 1) == 0)?1:((n - 1) % (k + 1));
			cout << "计算机搬" << j << "座山，还剩余" << n - j << "座!" << endl;
			n -= j;
		}while(n>0);
		t++;
		w+=tag;
		if(tag)cout << "你赢了！" << endl;
		else cout << "你输了！" << endl;
		system("pause");
		system("cls");
		cout << "请输入山的总数(n)和每次允许搬山的最大数目(k)：";
	}
	cout << "总共进行" << t << "局游戏，你共赢了" << w << "次！" << endl;
	return 0; 
} 
