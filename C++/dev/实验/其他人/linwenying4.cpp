#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

/*双向链表结点类的定义*/
typedef struct DuLNode{   
	ElemType data;
	struct DuLNode * prior,* next;
}DuLNode,* DuLinkList;

DuLinkList L;

int amount=0;

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

/*寻找第i个结点，使p指向该结点*/
Status LocatePos(DuLinkList L,int i,DuLinkList &p){
	int j=1;
	while(p&&j<i){ //寻找第i个结点
		p=p->next;
		++j;
	}
	return OK;
}


/*建立双向链表*/
void CreateList_DuL(DuLinkList &L,int n){
	DuLinkList p,q;
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->next=NULL;//先建立一个带头结点的双向链表
	q=L;
	for(int i=0;i<n;++i){
		p=(DuLinkList)malloc(sizeof(DuLNode));//生成新结点
		scanf("%d",&p->data);//输入元素值
		p->next=q->next;
		q->next=p;
		q=p;
	}
}

/*在双向链表的第i个结点前插入一个结点*/
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	DuLinkList p=L,s;
	int j=0;
	while(p&&j<i-1){ //寻找第i-1个结点
		p=p->next;
		++j;
	}
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;//生成新结点
	s->data=e;
	s->next=p->next;//插入L中
	p->next=s;
	s->prior=p;
	if(s->next) 
		s->next->prior=s;
	amount++;
	return OK;
}

/*在双向链表的第i个结点前删除一个结点*/
Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
	DuLinkList p=L;
	int j=0;
	while(p&&j<i-1){ //寻找第i-1个结点
		p=p->next;
		++j;
	}
	e=p->data;
	p->prior->next=p->next;
	if(p->next)
		p->next->prior=p->prior;
	free(p);//删除并释放结点
	amount--;
	return OK;
}


/*在双向链表中查找第i个结点*/
Status ListSearch_DuL(DuLinkList L,int i,ElemType &e){
	DuLinkList p=L->next;
	LocatePos(L,i,p);//寻找第i个结点并使p指向该结点
	e=p->data;	
	printf("第%d",i);
	printf("个元素的值为：%d",e);
	printf("\n");
	return OK;
}

/*在双向链表中更新第i个结点*/
Status ListUpdata_DuL(DuLinkList L,int i,ElemType e){
	DuLinkList p=L->next;
	LocatePos(L,i,p);//寻找第i个结点并使p指向该结点
	p->data=e;
	return OK;
}

void visit(ElemType e)  
{  
    printf("%d  ",e);  //打印数据元素 
}  

/*遍历双向链表*/
Status ListTraverse_DuL(DuLinkList L, void (*visit)( ElemType )){
	DuLinkList p=L->next;
	while(p){
		visit(p->data); //依次对L的每个数据元素调用visit()函数
		p=p->next;		//一旦visit()失败，则操作失败
	}	 
	printf("\n");
	return OK;
}


int main(){
	int i=0,num,n;
	ElemType e; 
	printf("\t\t\t\t双向链表的基本操作\n");
	printf("\t\t-----------------------------------------------\n");
	loop1:
		do{	
			printf("请输入双向链表元素的个数:");
			scanf("%d",&n);
			if(n==0){
			printf("双向链表中的元素个数不能为0！请重新输入:\n");
			goto loop1;
			}
			else{
			printf("请输入双向链表中的元素:");
			CreateList_DuL(L,n); 
			amount=n;// 
			break;
			}
		}while(1);
	while(1){
	printf("请选择以下操作：\n");  //提示 
	printf("---------------------------------------------------\n");
	printf("1、在双向链表的第i个结点前插入一个结点\n");
	printf("2、在双向链表的第i个结点前删除一个结点 \n");
	printf("3、在双向链表中查找第i个结点的值\n");
	printf("4、更新双向链表中第i个结点的值\n");
	printf("5、遍历双向链表\n");
	printf("6、结束退出\n");
	printf("---------------------------------------------------\n");
	loop2:
	scanf("%d",&num);	//对输入的数字进行判断
	if(!(num>=1&&num<=6)){	//如果输入不为1-6的数字则重新输入 
		printf("输入错误！请重新选择:\n");
		goto loop2;
	}
	switch(num){
		case 1 : printf("请输入i的值：");
				 scanf("%d",&i);
				 if(i>amount||i<1){  //判断i的值是否在范围内 
				 	printf("输入i值错误！\n");
				 	break; 
				 }
				 printf("请输要插入的元素值：");
				 scanf("%d",&e);
				 ListInsert_DuL(L,i,e);  //在双向链表的第i个元素前插入一个结点
				 printf("操作成功！\n\n"); 
				  break;
		case 2 : printf("请输入i的值：");
				 scanf("%d",&i);
				 if(i>amount||i<=1){
				 	printf("输入i值错误！\n");
				 	break; 
				 }
				 ListDelete_DuL(L,i,e);  //在双向链表的第i个元素前删除一个结点 
				 printf("操作成功！\n\n");
		 		 break;
		case 3 : printf("请输入i的值：");
				 scanf("%d",&i);
				 if(i>amount||i<1){
				 	printf("输入i值错误！\n");
				 	break; 
				 }
				 ListSearch_DuL(L,i,e);  // 在双向链表中查找第i个结点
				 printf("操作成功！\n\n"); 
				   break;
		case 4 : printf("请输入i的值：");
				 scanf("%d",&i);
				 if(i>amount||i<1){
				 	printf("输入i值错误！\n");
				 	break; 
				 }
				 printf("请输入要更新的元素值：");
				 scanf("%d",&e);
				 ListUpdata_DuL(L,i,e);  //更新双向链表中第i个元素的值
				 printf("操作成功！\n\n");   break;
		case 5 : printf("遍历双向链表： ");
				 ListTraverse_DuL(L,visit);  //遍历双向链表
			 	 printf("操作成功！\n\n");  break; 
		case 6 : system("CLS");
				 printf("\t\n程序结束！\n\t再见！\n");
				 exit(0);	//结束程序 
		}
	}
}

