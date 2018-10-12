#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> num(1005);
	for(int p = 0;p < 1005;p++)num[1005] = 0;
	int n,m,blog;
	cin >> n;
	while(n--){
		cin >> m;
		while(m--){
			cin >> blog;
			num[blog]++;
		}
	}
	int max = 0;
	for(int i = 0;i < 1005;i++){
		if(num[max] <= num[i]){
			max = i;
		}
	}
	cout << max << " " << num[max];
	return 0;
}
