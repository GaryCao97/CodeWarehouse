#include<iostream>
#include<math.h>
using namespace std;
void sortBy(int r[], int n) {
	if(n == 1){
		int i = 4 - 1;
		while (i> 0) {
			int pos = 0;
			for (int j = 0; j < i; j++)
				if (r[j] > r[j + 1]) {
					pos = j;
					int tmp = r[j]; r[j] = r[j + 1]; r[j + 1] = tmp;
				}
			i = pos;
		}
	}
	else if(n == 0){
		int i = 3;
		while (i> 0) {
			int pos = 0;
			for (int j = 0; j< i; j++)
				if (r[j] < r[j + 1]) {
					pos = j;
					int tmp = r[j];
					r[j] = r[j + 1];
					r[j + 1] = tmp;
				}
			i = pos;
		}
	}
}
void Kaprekar(int num){
	int newNum[2] = {0,0},preNum[4],ans;
	for(int i = 0;i < 4;i++){
		preNum[i] = (int)(num % (int)pow(10,i+1))/pow(10,i);
	}
	if(preNum[0]==preNum[1] && preNum[0]==preNum[2] && preNum[0]==preNum[3]){
		if(num<1000)cout << '0';
		if(num<100)cout << '0';
		if(num<10)cout << '0';
		cout << num << " - ";
		if(num<1000)cout << '0';
		if(num<100)cout << '0';
		if(num<10)cout << '0';
		cout << num << " = 0000";
		return;
	}
	sortBy(preNum,1);
	for(int i = 3;i >= 0;i--){
		newNum[0] += preNum[i] * pow(10,i);
	}
	sortBy(preNum,0);
	for(int i = 0;i < 4;i++){
		newNum[1] += preNum[i] * pow(10,i);
	}
	ans = newNum[0] - newNum[1];
	if(newNum[0]<1000)cout << '0';
	if(newNum[0]<100)cout << '0';
	if(newNum[0]<10)cout << '0';
	cout << newNum[0] << " - ";
	if(newNum[1]<1000)cout << '0';
	if(newNum[1]<100)cout << '0';
	if(newNum[1]<10)cout << '0';
	cout << newNum[1] << " = ";
	if(ans<1000)cout << '0';
	if(ans<100)cout << '0';
	if(ans<10)cout << '0';
	cout << ans;
	if(ans != 6174){
		cout << endl;
		Kaprekar(ans);
	}
	else return;
}
int main(){
	int number;
	cin >> number;
	Kaprekar(number);
	return 0;
}
