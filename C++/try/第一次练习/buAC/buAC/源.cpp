#include<iostream>
using namespace std;
const int len = 100;
int proSum(int startPro[len], int endPro[len], int length, int startTime, int theSum = 0){
	int maxEnd = 0;
	for (int y = 0; y < length; y++){
		maxEnd = maxEnd>endPro[y] ? maxEnd : endPro[y];
	}
	start: int flag = 0;
	for (int x = 0; x < length; x++){
		if (startPro[x] == startTime){
			flag = x;
		}
	}
	if (flag != 0){
		theSum++;
		startTime = endPro[flag];
		goto start;
	}
	else if (flag == 0 && startTime < maxEnd){
		startTime++;
		goto start;
	}
	return theSum;
}
int main(){
	int n;
	int timeStart[len], timeEnd[len];
	scanf_s("%d", &n);
	while (n != 0){
		for (int i = 0; i < n; i++)
			scanf_s("%d %d", &timeStart[i], &timeEnd[i]);
		printf_s("%d", proSum(timeStart, timeEnd, n, 0));
		scanf_s("%d", &n);
	}
}