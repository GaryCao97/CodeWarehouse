#include<iostream>
using namespace std;
int main(){
	int score[10001];
	for(int i = 0;i < 10001;i++)score[i] = 0;
	int n,maxTag = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int order,per,num;
		scanf("%d-%d %d",&order,&per,&num);
		score[order]+=num;
		if(score[maxTag] < score[order])maxTag = order;
	}
	printf("%d %d",maxTag,score[maxTag]);
	return 0;
}
