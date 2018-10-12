//#include<iostream>
//using namespace std;
//int gcd(int x,int y){
//	int z = y;
//	while(x%y!=0){
//		z = x%y;
//		x = y;
//		y = z;
//	}
//	return z;  
//}
//int main(){
//	int n1,n2;
//	while(scanf("%d %d",&n1,&n2)!=EOF){
//		printf("%d\n",n1*n2/gcd(n1,n2));
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int gcd(int x,int y){
	if(!y) return x;
	else return gcd(y,x%y);
}
int main(){
	int a,b;
	while(cin >> a>> b){
		cout << a*b/gcd(a,b) << endl;
	}
	return 0;
}
