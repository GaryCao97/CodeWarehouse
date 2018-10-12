#include<iostream>
using namespace std;
int main(){
	int a, b;
	scanf_s("%d %d", &a, &b);
	while (a != 0 || b != 0){
		printf_s("%d\n", a + b);
		scanf_s("%d %d", &a, &b);
	}
}