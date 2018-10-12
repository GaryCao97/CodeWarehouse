#include <iostream>
using namespace std;
int main(){
	int m, n;
	while (scanf_s("%d %d", &m, &n) != EOF){
		int a, b, c, flag = 0;
		for (int i = m; i <= n; i++){
			a = i % 10;
			b = (i / 10) % 10;
			c = i / 100;
			if (i == a*a*a + b*b*b + c*c*c){
				if(flag == 0)
					printf_s("%d", i);
				else
					printf_s(" %d", i);
				flag = 1;
			}
		}
		if (flag == 0)
			printf_s("no");
		printf_s("\n");
	}
}