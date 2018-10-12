#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	cin >> n;
	int *score = (int *)malloc((n+1)*sizeof(int));
	for(int i = 0;i < n+1;i++) score[i] = 0;
	int maxTag = 0;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		score[x]+=y;
		if(score[x] > score[maxTag]){
			maxTag = x;
		}
	}
	cout << maxTag << ' ' << score[maxTag];
	return 0;
}
