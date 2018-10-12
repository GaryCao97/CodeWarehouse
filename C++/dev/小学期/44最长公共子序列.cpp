#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define Max(a,b) ((a)>=(b)?(a):(b))
typedef struct Set{
	int num;
	char *ch;
	Set(){
		num = 0;
		ch = NULL;
	}
}Set;

void GetMatrix(int **M,Set A,Set B){
	for(int j = 0;j <= B.num;j++){
		for(int i = 0;i <= A.num;i++){
			if(i == 0 || j == 0)M[j][i] = 0;
			else{
				if(A.ch[i-1] == B.ch[j-1]) M[j][i] = M[j - 1][i - 1] + 1;
				else M[j][i] = Max(M[j - 1][i],M[j][i - 1]);
			}
		}
	}
}
void PrintMatrix(int **M,int x,int y){
	for(int j = 0;j <= y;j++){
		for(int i = 0;i <= x;i++){
			printf("%d ",M[j][i]);
		}
		printf("\n");
	}
}
void GetSub(int **M,Set A,Set B,Set &Sub){
	Sub.num = M[B.num][A.num];
	Sub.ch = (char*)malloc(Sub.num*sizeof(char));
	int l = Sub.num - 1;
	for(int j = B.num - 1,i = A.num - 1;i >= 0 && j >= 0;){
		if(A.ch[i] == B.ch[j]){
			Sub.ch[l] = B.ch[j];
			i--;j--;l--;
		}
		else{
			if(M[j-1][i] > M[j][i-1]) j--;
			else i--;
		}
	}
}

int main(){
	int **d;
	Set A,B,Sub;
	
	printf("请输入A集合元素个数，并输入集合A：\n");
	cin >> A.num;
	A.ch = (char*)malloc(A.num*sizeof(char));
	for(int i = 0;i < A.num;i++)
		cin >> A.ch[i];
	
	printf("请输入B集合元素个数，并输入集合B：\n");
	cin >> B.num;
	B.ch = (char*)malloc(A.num*sizeof(char));
	for(int i = 0;i < B.num;i++)
		cin >> B.ch[i];
	
	d = (int**)malloc((B.num + 1) * sizeof(int*));
	for(int j = 0;j <= B.num;j++){
		d[j] = (int*)malloc((A.num + 1) * sizeof(int));
	}
	
	GetMatrix(d,A,B);
	//PrintMatrix(d,A.num,B.num);
	GetSub(d,A,B,Sub);
	for(int i = 0;i < Sub.num;i++)printf("%c ",Sub.ch[i]);
	return 0; 
}
