#include<iostream>
using namespace std;
int main(){
	double num[6];
	int flags[6];
	for(int i = 0;i < 6;i++){
		num[i] = 0;
		flags[i] = 0;
	}
	int n,m;
	int flag = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> m;
		if(m%5 == 0){
			if(m % 2 == 0){
				num[1]+=m;
				flags[1] = 1;
			}
		}
		else if(m%5 == 1){
			flags[2] = 1;
			if(flag == 0){
				flag = 1;
				num[2]+=m;
			}
			else{
				flag = 0;
				num[2]-=m;
			}
		}
		else if(m%5 == 2){
			flags[3] = 1;
			num[3]++;
		}
		else if(m%5 == 3){
			flags[4] = 1;
			num[0]++;
			num[4]+=m;
		}
		else if(m%5 == 4){
			if(flags[5]==0){
				num[5] = m;
				flags[5]=1;
			}
			else{
				if(num[5] < m) num[5] = m;
			}
		}
	}
	for(int i = 1;i <= 5;i++){
		if(flags[i]==0)cout << 'N';
		else{
			if(i!=4)
				printf("%.0lf",num[i]);
			else
				printf("%.1lf",num[i]/num[0]);
		}
		if(i!=5)
		cout << ' ';
	}
	return 0;
}
