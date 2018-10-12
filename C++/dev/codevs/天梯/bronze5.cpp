#include<cstdio>
#include<cmath>
int main(){
	int yuanjia,jiage;
	double num,zhelv;
	scanf("%d%lf",&yuanjia,&zhelv);
	num = yuanjia * zhelv / 100.0;
	num = (num > 0.0) ? floor(num + 0.5) : ceil(num - 0.5);
	jiage = ((int)num) * 10;
	printf("%d",jiage);
    return 0;
}
