#include<iostream>
#include<stdlib.h>
using namespace std;
void Dsf(){
	
}
int main(){
	int m,n;
	char **map;
	cin >>m >> n;
	while(m||n){
		map = (char**)malloc(m * sizeof(char*));
		for(int i = 0;i < m;i++){
			map[i] = (char*)malloc(n * sizeof(char));
			cin >> map[i];
		}
		cin >>m >> n;
	}
	return 0;
}
