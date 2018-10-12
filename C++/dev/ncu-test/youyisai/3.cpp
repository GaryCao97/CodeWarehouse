#include<cstdio>
#include<cstdlib>
#include<set> 
using namespace std;
int main(){
	set<int> num;
	int n;
	scanf("%d",&n);
	while(n--){
		int number;
		scanf("%d",&number);
		num.insert(number);
	}
	for(set<int>::iterator it = num.begin();it!=num.end();++it){
		printf("%d ",*it);
	}
	return 0;
} 
