#include<iostream>
using namespace std;
typedef struct{
	char sign;
	long k;
	long a,b;
}youli;
long gcd(long a, long b) {
	return b == 0 ? a : gcd(b, a % b);
}
void huajian(youli &num){
	if(num.b<0){
		num.b = -num.b;
		num.a = -num.a;
	}
	if(num.a<0){
		num.sign = '-';
		num.a = -num.a;
	}
	else{
		num.sign = '+';
	}
	num.k = num.a/num.b;
	num.a = num.a%num.b;
	long n = gcd(num.a,num.b);
	if(n!=0){
		num.a/=n;
		num.b/=n;
	}
}
void output(youli num){
	huajian(num);
	if(num.sign == '-'){
		cout << "(-";
	}
	if(num.k)cout << num.k;
	if(num.k && num.a)cout << ' ';
	if(num.a)cout << num.a << '/' << num.b;
	if(!num.k && !num.a) cout << '0';
	if(num.sign == '-'){
		cout << ")";
	}
}
void jia(youli num1,youli num2){
	youli ans;
	ans.b = num1.b*num2.b;
	ans.a = num1.a*num2.b + num1.b*num2.a;
	output(num1);
	cout << " + ";
	output(num2);
	cout << " = ";
	output(ans);
}
void jian(youli num1,youli num2){
	youli ans;
	ans.b = num1.b*num2.b;
	ans.a = num1.a*num2.b - num1.b*num2.a;
	output(num1);
	cout << " - ";
	output(num2);
	cout << " = ";
	output(ans);
}
void cheng(youli num1,youli num2){
	youli ans;
	ans.a = num1.a*num2.a;
	ans.b = num1.b*num2.b;
	output(num1);
	cout << " * ";
	output(num2);
	cout << " = ";
	output(ans);
}
void chu(youli num1,youli num2){
	youli ans;
	output(num1);
	cout << " / ";
	output(num2);
	cout << " = ";
	if(!num2.a) cout << "Inf";
	else{
		ans.a = num1.a*num2.b;
		ans.b = num1.b*num2.a;
		output(ans);
	} 
}
int main(){
	youli num[2];
	scanf("%ld/%ld %ld/%ld",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
	jia(num[0],num[1]);
	cout << endl;
	jian(num[0],num[1]);
	cout << endl;
	cheng(num[0],num[1]);
	cout << endl;
	chu(num[0],num[1]);
	return 0;
}
