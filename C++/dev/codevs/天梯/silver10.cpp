#include<cstdio>
int main(){
	int n,i,j,x,y,arr[100][100],num = 2,tag,sum=0;
	for(i = 0;i < 100;i++)
		for(j = 0;j < 100;j++)
			arr[i][j] = 0;
	scanf("%d",&n);
	x = y = i = j = n/2;
	tag = n * n;
	arr[i][j] = 1;
	y++;
	while(num <= tag){
		do{
			arr[x][y] = num++;
			x--;
		}while(arr[x][y - 1]);
		do{
			arr[x][y] = num++;
			y--;
		}while(arr[x + 1][y]);
		do{
			arr[x][y] = num++;
			x++;
		}while(arr[x][y + 1]);
		do{
			arr[x][y] = num++;
			y++;
		}while(arr[x - 1][y]);
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			if(j!=0)printf(" ");
			printf("%d",arr[i][j]);
			if(i == j || i+j == n-1)sum+=arr[i][j];
		}
		printf("\n");
	}
	printf("%d",sum);
	return 0;
} 
