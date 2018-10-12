#include<cstdio>
#include<set>
using namespace std;
int main(){
	int n,m;
	set<int> num;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		num.insert(m);
	}
	printf("%d\n",num.size());
	set<int>::iterator iter=num.begin();
    while(iter!=num.end()){  
        printf("%d",*iter);
        ++iter;
        if(iter!=num.end())printf(" ");
	}
	return 0;
} 
