#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
	int n,a[3];
	double ans,r,pi=3.141592653589793238462643383;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[0]>> a[1]>> a[2];
		sort(a,a+2);
		r = a[0]*a[0] + ((a[2]-a[0])>0?(a[2]-a[0]):0)*((a[2]-a[0])>0?(a[2]-a[0]):0);
		ans = pi*(r);
		cout<< fixed << setprecision(12) << ans <<endl;
	}
	return 0;
}
