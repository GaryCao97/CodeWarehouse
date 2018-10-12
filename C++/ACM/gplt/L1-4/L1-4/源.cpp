#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int handsome[100000];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int K;
		cin >> K;
		for (int j = 0; j < K; j++){
			int num;
			cin >> num;
			handsome[num] = 1;
		}
	}
	int M, flag = 0;
	cin >> M;
	for (int i = 0; i < M; i++){
		int input;
		cin >> input;
		if (handsome[input] != 1){
			cout << input << setw(6);
			handsome[input] = 1;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "No one is handsome";
	return 0;
}