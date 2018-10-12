#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define RAND(x) rand()%(x)
char player[4] = {'A','B','C','D'};
int main(){
	srand(time(NULL));
	int shaizi[7] = {0,0,0,0,0,0,0};
	for(int i = 1;i < 7;i++){
		shaizi[i] = RAND(16 - shaizi[0]);
		shaizi[0] += shaizi[i];
	}
	shaizi[6] += 16 - shaizi[0];
	shaizi[0] = 16;
	int prev[2] = {0,0},now[2] = {0,0},index=0;
	do{
		printf("%c:",player[index]);
		scanf("%d",&now[0]);
		if(now[0]==0||now[0] == 16)break;
		scanf("%d",&now[1]);
		if(now[0]<prev[0]){
			cout << "不符合游戏要求重新输入！";
			continue;
		}
		index=(index+1)%4;
		prev[0] = now[0];
		prev[1] = now[1];
	}while(true);
	if(shaizi[prev[1]] == prev[0]){
		printf("%c胜利\n",player[(index-1)%4]);
	}
	else{
		printf("%c胜利\n",player[index]);
	}
	return 0;
}
