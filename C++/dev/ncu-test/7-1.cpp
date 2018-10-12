#include<cstdio>
#include<cstring>

int main(){
	char num[55];
	double n,p,q;
	int i;
	while(scanf("%s",num)!=EOF){
		n = 1;
		p = 0;
		q = strlen(num);
		i = 0;
		if(num[0] == '-'){
			n *= 1.5;
			q--;
			i++;
		}
		if(!((num[strlen(num) - 1] - '0') % 2 ))n *= 2;
		for(;i < strlen(num);i++){
			if(num[i] == '2')p++;
		}
		n *= (p/q)*100;
		printf("%.2lf%%\n",n); 
		memset(num,0,51 * sizeof(char));
	}
	return 0;
} 
