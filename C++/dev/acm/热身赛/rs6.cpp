#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct{
	char name[11];
	int score;
	int num;
}infomation;
int comp(infomation i1,infomation i2){
	if(i1.num != i2.num) return i1.num > i2.num;
	else if(i1.score != i2.score) return i1.score < i2.score;
	else return strcmp(i1.name,i2.name);
}
int main(){
	infomation *info = (infomation*)malloc(0 * sizeof(infomation));
	int n,m,p,q,num = 0;
	cin >> n >> m;
	char inputName[11];
	while(cin >> inputName){
		num++;
		info = (infomation*)realloc(info,num * sizeof(infomation));
		for(int i = 0;i < 11;i++)
			info[num-1].name[i] = inputName[i];
		info[num-1].num = 0;
		info[num-1].score = 0;
		for(int i = 0;i < n;i++){
			cin >> p;
			if(p <= 0)continue;
			else {
				info[num-1].score += p;
				info[num-1].num ++;
			}
			if(cin.peek() == '('){
				cin.get();
				cin >> q;
				cin.get();
				info[num-1].score += q*m;
			}
		}
	}
	sort(info,info+num,comp);
	for(int i = 0;i < num;i++){
		printf("%-10s %2d %4d\n",info[i].name,info[i].num,info[i].score);
	}
	return 0;
}
