#include <iostream>
using namespace std;

int main(){
	int day[2][12] = { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
	int yy, mm, dd;
	int dayNum, flag;
	while (scanf_s("%d/%d/%d", &yy, &mm, &dd) != EOF){
		dayNum = 0;
		if (yy == 0)break;
		flag = (yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0)) ? 1 : 0;
		for (int i = 0; i < mm - 1; i++){
			dayNum += day[flag][i];
		}
		dayNum += dd;
		printf_s("%d\n", dayNum);
	}
}