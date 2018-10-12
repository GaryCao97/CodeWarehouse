#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char chs[1005];
	int m,n,i = 0,x,y;
	cin >> n;
	cin.get();
	cin.getline(chs,1005);
	m = ((strlen(chs) - 1)/n) + 1;
	char ans[n][m];
	for(y = m - 1; y >= 0; y--){
		for(x = 0; x < n; x++){
			if(i < strlen(chs)){
				ans[x][y] = chs[i++];
			}
			else ans[x][y] = ' ';
		}
	}
	for(x = 0;x < n;x++){
		for(y = 0;y < m;y++){
			printf("%c",ans[x][y]);
		}
		if(x<n -1)
		printf("\n");
	}
	return 0;
}
