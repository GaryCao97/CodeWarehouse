#include<iostream>
#include<string.h>
using namespace std;
int main(){
	string strA,strB,strTmp;
	int num = 0;
	while(cin >> strTmp){
		if(strTmp[0] == '.')break;
		num++;
		if(num == 2)strA = strTmp;
		if(num == 14)strB = strTmp;
	}
	if(num >= 14){
		cout << strA << " and " << strB << " are inviting you to dinner...";
	}
	else if(num >= 2){
		cout << strA << " is the only one for you...";
	}
	else{
		cout << "Momo... No one is for you ...";
	}
	return 0;
}
