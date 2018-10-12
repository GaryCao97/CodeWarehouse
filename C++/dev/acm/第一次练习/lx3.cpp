#include<iostream>
using namespace std;
#define PI 3.1415927
int main(){
	double r,ans;
	while(scanf("%lf",&r)!=EOF){
		ans = (4.0 * PI * r*r*r) / 3.0;
		printf("%.3lf\n",ans);
	} 
	return 0;
}
