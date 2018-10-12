#include<iostream>
using namespace std;
int win[3][3] = {{1,0,2},{2,1,0},{0,2,1}};
int change(char ch){
	if(ch == 'J') return 0;
	if(ch == 'C') return 1;
	if(ch == 'B') return 2;
}
char back(int n){
	if(n == 0)return 'J';
	if(n == 1)return 'C';
	if(n == 2)return 'B';
}
int cq(char a,char b){
	return win[change(a)][change(b)];
}
int main(){
	int num[2][3] = {{0,0,0},{0,0,0}};
	int winNum[2][3] = {{0,0,0},{0,0,0}};
	int n;
	char a,b;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		num[0][cq(a,b)]++;
		num[1][cq(b,a)]++;
		if(cq(a,b) == 2) winNum[0][change(a)]++;
		if(cq(b,a) == 2) winNum[1][change(b)]++;
	}
	int max[2] = {0,0};
	int tag[2];
	for(int i = 0;i < 3;i++){
		if(max[0] <= winNum[0][i]){
			max[0] = winNum[0][i];
			tag[0] = i;
		}
		if(max[1] <= winNum[1][i]){
			max[1] = winNum[1][i];
			tag[1] = i;
		}
	}
	printf("%d %d %d\n",num[0][2],num[0][1],num[0][0]);
	printf("%d %d %d\n",num[1][2],num[1][1],num[1][0]);
	printf("%c %c",back(tag[0]),back(tag[1]));
	return 0;
}
