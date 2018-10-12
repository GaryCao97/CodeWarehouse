#include <iostream>
#include <string.h>
using namespace std;
int huanghou[11],ans;
void search(int cur,int n){
	int i,j,ok;
	if(cur==n) ans++;
	else for(i=0;i<n;i++)
	{
		ok=1;
		huanghou[cur]=i;
		for(j=0;j<cur;j++)
			if((huanghou[cur]==huanghou[j])||(cur-huanghou[cur]==j-huanghou[j])||(cur+huanghou[cur]==j+huanghou[j])){
    			ok=0;
    			break;
    		}
		if(ok)
			search(cur+1,n);
	}
}

int main(){
	int num[11];
	int n;
	for(int i=1;i<=10;i++){
		search(0,i);
		num[i]=ans;
		ans=0;
	}
	while(cin>>n&&n){
		cout<<num[n]<<endl;
	}
	return 0;
}
