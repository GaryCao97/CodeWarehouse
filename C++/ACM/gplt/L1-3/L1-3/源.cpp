#include<iostream>
using namespace std;
int main(){
	int count[2], max[2];
	cin >> max[0] >> max[1];
	int num;
	cin >> num;
	count[0] = count[1] = 0;
	for (int i = 0; i < num; i++){
		int A[2], B[2];
		cin >> A[0] >> A[1] >> B[0] >> B[1];
		if (A[1] == (A[0] + B[0])){
			max[0]--;
			count[0]++;
		}
		if (B[1] == (A[0] + B[0])){
			max[1]--;
			count[1]++;
		}
		if (max[0] == 0 || max[1] == 0)
			break;
	}
	if (max[0] == 0){
		cout << "A" << endl << count[1];
	}
	else{
		cout << "B" << endl << count[0];
	}
	return 0;
}