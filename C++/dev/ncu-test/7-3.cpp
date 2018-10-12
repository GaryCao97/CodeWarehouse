#include<cstdio>

int main(){
	int dA,dB,n,tA,tB,hanA,huaA,hanB,huaB,aa,bb;
	while(scanf("%d %d",&dA,&dB)!=EOF){
		aa = dA;
		bb = dB;
		scanf("%d",&n);
		while(n--){
			tA = 0;
			tB = 0;
			scanf("%d %d %d %d",&hanA,&huaA,&hanB,&huaB);
			if(dA<0 || dB<0)continue;
			if(huaA == (hanA + hanB))tA = 1;
			if(huaB == (hanA + hanB))tB = 1;
			if(tA!=tB){
				dA-=tA;
				dB-=tB;
			}
		}
		if(dA>=0) printf("B\n%d\n",aa-dA);
		else printf("A\n%d\n",bb-dB);
	}
	return 0;
}
