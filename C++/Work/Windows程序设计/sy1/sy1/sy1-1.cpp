#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;
BOOLEAN Prime(long long num){
	for (int i = 2; i < sqrt(num); i++){
		if (num % i == 0)
			return FALSE;
	}
	return TRUE;
}
int main(){
	long long n;
	cin >> n;
	while (n > 0){
		cout << Prime(n) << endl;
		cin >> n;
	}
	return 0;
}