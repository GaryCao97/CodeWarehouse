#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double n;
	int m;
	double sum;
	while(scanf("%lf %d",&n,&m)!=EOF){
		sum = 0;
		while(m){
			sum+=n;
			n = sqrt(n);
			m--;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
