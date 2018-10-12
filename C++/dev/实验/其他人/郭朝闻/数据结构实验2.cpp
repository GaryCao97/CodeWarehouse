 //数据结构试验二：顺序表类的定义

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include<Windows.h>
#define LIST_INIT_SIZE   100
#define LISTINCREMENT   10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
//Status 是函数的类型，其值是函数结果状态代码 
typedef int Status;
typedef int ElemType; 

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

class LIST{
	public:
		Status (*cmp)(SqList L,ElemType e);
		Status InitList_Sq(SqList &L);
		Status ListInsert_Sq(SqList &L,int i,ElemType e);
		Status ListDelete_Sq(SqList &L,int i,ElemType &e);
		Status LocateElem_Sq(SqList L,ElemType e);
        Status cmpare(ElemType a,ElemType b);
		Status UpdateList_Sq(SqList &L,int i,ElemType e);
		Status ListTraverse_Sq(SqList L);
};

Status LIST::InitList_Sq(SqList &L){
	//构造一个空的线性表L
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE *(sizeof(ElemType)));
	if(!L.elem) exit (OVERFLOW) ;
	//存储分配失败
	L.length=0;
	//空表长度为0
	L.listsize=LIST_INIT_SIZE ;
	//初始存储容量
	return OK; 
	
}


//在顺序表的第i个元素前插入一个元素

Status LIST::ListInsert_Sq(SqList &L,int i,ElemType e) {
	if(i<1 || i>L.length+1)
	   return ERROR ;
	if(L.length>=L.listsize){
	   ElemType *newbase=(ElemType *)realloc(L.elem,
	                (L.listsize+LISTINCREMENT)*sizeof(ElemType));
    if(!newbase) exit (OVERFLOW);
    L.elem=newbase;
    L.listsize+=LISTINCREMENT;
	}
    	ElemType *q=&(L.elem[i-1]);
    	ElemType *p;
    	for(p=&(L.elem[L.length-1]);p>=q;p--)
    		*(p+1)=*p;
        *q=e;
        L.length++;
	return OK;
}//ListInsert_sq


//删除顺序表第i个位置的元素 

Status LIST::ListDelete_Sq(SqList &L,int i,ElemType &e){
	if(i<1 || i>L.length)
	   return ERROR;
	   
	ElemType *p;
	p=&(L.elem[i-1]);
	*p=e;
	ElemType *q=L.elem+L.length-1;
	for(++p;p<=q;p++)
	    *(p-1)=*p;
	--L.length;
	return OK;    
} //ListDelete_sq

Status LIST::cmpare(ElemType a,ElemType b){
	if(a == b)
		return OK;
	else
		return ERROR;
}
//在顺序表中查找第i个元素

Status LIST::LocateElem_Sq(SqList L,ElemType e){
	//在顺序线性表L中查找第1个值与e满足compare()的元素的位序
	//若找到，则返回其在L中的位序，否则返回0
	int i=1;
	ElemType *p=L.elem;
	while(i<=L.length && !cmpare(*p++,e))
	    ++i;
	if(i<=L.length)
	    printf("查找的元素在第%d个位置。",i);
	else 
	    return ERROR;
} //LocateElem_Sq


//更新顺序表中第i个元素的值

Status LIST::UpdateList_Sq(SqList &L,int i,ElemType e){
	if(i<1 || i>L.length)
	  return ERROR;
	ElemType *p=&(L.elem[i-1]);
	*p=e;
	  return OK;
}//UpdateList_Sq


//遍历顺序表

Status LIST::ListTraverse_Sq(SqList L){
   
	ElemType *p=L.elem;
	ElemType *q=&L.elem[L.length-1];
	
	printf("顺序表为：");
	while(p<=q){
	    printf("%d",*p);
	    printf(" ");
	    p++;
}
       return OK;
}//ListTraverse_Sq

int main(){
	ElemType e;
	SqList L;
	LIST list;
	list.InitList_Sq(L);
	printf("\n\n==欢迎进入顺序表系统==\n\n"); 
	printf("请先输入元素个数： ");
	int N;
	scanf("%d",&N) ;
	printf("请依次输入元素:\n");
	for(int i=1;i<=N;i++){
	    printf("第%d个数据：",i);
	    scanf("%d",&e);
	    //system("pause");
	    list.ListInsert_Sq(L,i,e);
	}
	Sleep(1000);
	system("cls");
	loop:{
		printf("请选择想要进行的功能：\n");
		printf("1) 插入元素 \n");
		printf("2) 删除元素 \n");
		printf("3) 查找元素 \n");
		printf("4) 更新元素 \n");
		printf("5) 遍历线性表 \n");
	   int a;
	    scanf("%d",&a);
	    system("cls");
	    switch(a){
	    	case 1:printf("要插入哪个元素？");
	    	       scanf("%d",&e);
	    	       printf("\n");
	    	       printf("要插入哪个位置？");
	    	       scanf("%d",&N);
	    	       list.ListInsert_Sq(L,N,e);
	    	       Sleep(1000);
	    	    goto loop;break;
	    	case 2:printf("要删除哪个位置的元素？");
	    	       scanf("%d",&N);
	    	       printf("\n");
	    	       list.ListDelete_Sq(L,N,e);
				   printf("已删除%d。",e);
				   Sleep(1000);
				goto loop;break;
			case 3:printf("您想要查找的元素值是多少？");
			       scanf("%d",&e);
				   list.LocateElem_Sq(L,e);
				goto loop;break;
		    case 4:printf("您想要更新的元素位置是哪里？");
			       scanf("%d",&N);
			       printf("\n");
			       printf("您想更新成什么元素？");
			       scanf("%d\n",&e);
				   list.UpdateList_Sq(L,N,e);
				   Sleep(1000);
				   goto loop;break;
		    case 5:printf("遍历线性表");
			        list.ListTraverse_Sq(L);
			        system("pause");
			        goto loop;break;
			default:
				printf("**请您输入1~5的数字**");
				goto loop;break;
	}
}
return OK; 
}

















