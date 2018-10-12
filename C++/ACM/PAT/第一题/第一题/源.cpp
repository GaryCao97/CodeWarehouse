#include<iostream>
using namespace std;

int Callatz(int num, int count = 0){
	if (num == 1)
		return count;
	if (num % 2 == 0)
		Callatz(num / 2, count + 1);
	else
		Callatz((3 * num + 1) / 2, count + 1);
}
int main(){
	int input, output;
	cin >> input;
	output = Callatz(input);
	cout << output;
	return 1;
}