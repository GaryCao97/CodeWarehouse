#include<iostream>
#include<set>
using namespace std;
int DiffNum(int year){
	set<int> tmp;
	tmp.insert(year/1000);
	tmp.insert((year%1000)/100);
	tmp.insert((year%100)/10);
	tmp.insert(year%10);
	return tmp.size();
}
int main(){
	int yy,n,i;
	while(cin >> yy >> n){
		for(i = yy;;i++)if(n == DiffNum(i))break;
		printf("%d %04d\n",i - yy,i);
	}
	return 0;
}
