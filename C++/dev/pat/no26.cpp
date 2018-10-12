#include<iostream>
using namespace std;
int main(){
	long long start,end,time;
	int hh,mm,ss;
	cin >> start >> end;
	time = (0.5 + (double)(end - start)/100);
	hh = time/3600;
	mm = (time%3600)/60;
	ss = time%60;
	printf("%2d:%2d:%2d",hh,mm,ss);
	return 0;
}
