#include<cstdio>

int main(){
	int hh,mm,num;
	while(scanf("%d:%d",&hh,&mm)!=EOF){
		if((hh == 24) || (hh == 12 && mm == 0) || (hh < 12)){
			printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
		}
		else{
			num = hh - 12 + (mm > 0? 1 : 0);
			while(num--){
				printf("Dang");
			}
		}
	}
	return 0;
} 
