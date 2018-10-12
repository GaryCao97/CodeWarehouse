#include<iostream>
using namespace std;
int main(){
	char a,b,c,tmp;
	while(cin >>a >> b>>c){
		if(a>b){
			tmp = a;a = b;b = tmp;
		}
		if(b>c){
			tmp = b;b = c;c = tmp;
		}
		if(a>b){
			tmp = a;a = b;b = tmp;
		}
		printf("%c %c %c\n",a,b,c);
	}
	return 0;
} 
