#include<cstdio>
#include<cstring>

int main(){
	int num[100005],n,k,k2,index,tag;
	while(scanf("%d",&n)!=EOF){
		tag = 0;
		memset(num,0,100005 * sizeof(int));
		while(n--){
			scanf("%d",&k);
			k2=k;
			while(k--){
				scanf("%d",&index);
				if(k2 > 1){
					num[index] = 1;
				}
			}
		}
		scanf("%d",&k);
		while(k--){
			scanf("%d",&index);
			if(!num[index]){
				if(tag == 0)tag = 1;
				else printf(" ");
				printf("%05d",index);
				num[index] = 1;
			}
		}
		if(!tag)printf("No one is handsome\n");
		else printf("\n");
	}
	return 0;
}
