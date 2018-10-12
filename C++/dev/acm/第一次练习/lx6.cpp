#include<iostream>
using namespace std;
int main(){
	int yy,mm,dd,day;
	while(scanf("%d/%d/%d",&yy,&mm,&dd)!=EOF){
		day = dd;
		switch(mm){
			case 12:day+=30;
			case 11:day+=31;
			case 10:day+=30;
			case 9:day+=31;
			case 8:day+=31;
			case 7:day+=30;
			case 6:day+=31;
			case 5:day+=30;
			case 4:day+=31;
			case 3:day+=(yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0))?29:28;
			case 2:day+=31;
			case 1:break;
		}
		printf("%d\n",day);
	}
	return 0;
}
